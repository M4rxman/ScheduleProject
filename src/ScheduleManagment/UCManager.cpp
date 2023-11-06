#include "UCManager.h"
/**
 * @brief Add a student to a UC (Course).
 * @param studentCode The code of the student to be added.
 * @param ucCode The code of the UC (Course) to add the student to.
 * @return True if the addition was successful, false otherwise.
 */
bool UCManager::addStudentToUC(const std::string& studentCode, const std::string& ucCode) {
    // Find the student in the StudentsClasses data
    Student* student = studentsClasses.findStudentByCode(studentCode);
    if (!student) {
        std::cout << "Student not found." << std::endl;
        return false;
    }

    // Find the UC in the ClassesPerUc data
    UcCode* uc = classesPerUc.findUcCodeByCode(ucCode);
    if (!uc) {
        std::cout << "UC not found." << std::endl;
        return false;
    }

    // Check if the student can be added to the UC
    if (canAddStudentToUC(*student, *uc)) {
        student->addUcCode(*uc);
        std::cout << "Student " << studentCode << " added to UC " << ucCode << "." << std::endl;
        return true;
    } else {
        std::cout << "Cannot add student to UC due to constraints." << std::endl;
        return false;
    }
}
/**
 * @brief Remove a student from a UC (Course).
 * @param studentCode The code of the student to be removed.
 * @param ucCode The code of the UC (Course) to remove the student from.
 * @return True if the removal was successful, false otherwise.
 */
bool UCManager::removeStudentFromUC(const std::string& studentCode, const std::string& ucCode) {
    // Find the student in the StudentsClasses data
    Student* student = studentsClasses.findStudentByCode(studentCode);
    if (!student) {
        std::cout << "Student not found." << std::endl;
        return false;
    }

    // Find the UC in the ClassesPerUc data
    UcCode* uc = classesPerUc.findUcCodeByCode(ucCode);
    if (!uc) {
        std::cout << "UC not found." << std::endl;
        return false;
    }

    // Check if the student can be removed from the UC
    if (canRemoveStudentFromUC(*student, *uc)) {
        student->removeUcCode(*uc);
        std::cout << "Student " << studentCode << " removed from UC " << ucCode << "." << std::endl;
        return true;
    } else {
        std::cout << "Cannot remove student from UC due to constraints." << std::endl;
        return false;
    }
}
/**
 * @brief Switch a student from one UC to another.
 * @param studentCode The code of the student to be switched.
 * @param oldUCCode The code of the current UC.
 * @param newUCCode The code of the new UC.
 * @return True if the switch was successful, false otherwise.
 */
bool UCManager::switchStudentUC(const std::string& studentCode, const std::string& oldUCCode, const std::string& newUCCode) {
    // Find the student in the StudentsClasses data
    Student* student = studentsClasses.findStudentByCode(studentCode);
    if (!student) {
        std::cout << "Student not found." << std::endl;
        return false;
    }

    // Find the old UC and new UC in the ClassesPerUc data
    UcCode* oldUC = classesPerUc.findUcCodeByCode(oldUCCode);
    UcCode* newUC = classesPerUc.findUcCodeByCode(newUCCode);

    if (!oldUC || !newUC) {
        std::cout << "Old or new UC not found." << std::endl;
        return false;
    }

    // Check if the student can switch from old UC to new UC
    if (canSwitchStudentUC(*student, *oldUC, *newUC)) {
        student->removeUcCode(*oldUC);
        student->addUcCode(*newUC);
        std::cout << "Student " << studentCode << " switched from UC " << oldUCCode << " to UC " << newUCCode << "." << std::endl;
        return true;
    } else {
        std::cout << "Cannot switch student's UC due to constraints." << std::endl;
        return false;
    }
}
/**
 * @brief Check if it's possible to add a student to a UC.
 * @param student The student object to add.
 * @param ucCode The UC code to add the student to.
 * @return True if the addition is allowed, false otherwise.
 */
bool UCManager::canAddStudentToUC(Student& student, UcCode ucCode) {
    // Constraint 1: A student cannot be registered in more than 7 UCs at any given time
    bool return_answer = false;
    if (student.getUcCodelist().size() >= 7) {
        std::cout << "Cannot add the student to the UC. The student is already registered in 7 UCs." << std::endl;
        return return_answer;
    }

    // Constraint 3: The resulting schedule will not conflict with the student's original schedule
    for (ClassCode ucClass : ucCode.getClassCodes()) {
        for (Schedule ucSchedule : ucClass.getSchedule()) {
            for (UcCode studentUc : student.getUcCodelist()) {
                for (ClassCode studentUcClass : studentUc.getClassCodes()) {
                    for (Schedule studentSchedule : studentUcClass.getSchedule()) {
                        // Check for schedule conflicts between the student's schedule and the new UC's schedule
                        if (student.hasScheduleConflict(studentSchedule, ucSchedule)) {
                            std::cout << "Cannot add the student to the UC. Schedule conflict detected." << std::endl;
                            return false;
                        }
                    }
                }
            }
        }
    }

    // Return true if all constraints are met
    return true;
}
/**
 * @brief Check if it's possible to remove a student from a UC.
 * @param student The student object to remove.
 * @param ucCode The UC code to remove the student from.
 * @return True if the removal is allowed, false otherwise.
 */
bool UCManager::canRemoveStudentFromUC(Student& student, UcCode& ucCode) {
    // Rule 1: A student cannot be in more than one class at once for a given UC
    if (!studentsClasses.isStudentInUc(student, ucCode)) {
        return false;
    }
    return false; // The student is not in any class for this UC, so they cannot be removed
}

/**
 * @brief Check if it's possible to switch a student from one UC to another.
 * @param student The student object to switch.
 * @param oldUCCode The code of the current UC.
 * @param newUCCode The code of the new UC.
 * @return True if the switch is allowed, false otherwise.
 */
bool UCManager::canSwitchStudentUC(Student& student, UcCode& oldUCCode, UcCode& newUCCode) {
    // Rule 1: A student cannot be in more than one class at once for a given UC
    if (!studentsClasses.isStudentInUc(student, oldUCCode)) {
        return false;
    }

    // Rule 2: A class can only accept a new student if its capacity has not been exceeded
    if (studentsClasses.isStudentInUc(student, newUCCode)) {
        return false;
    }

    // Rule 3: A class can only accept a new student if the balance between class occupation is not disturbed
    for (ClassCode classCode : newUCCode.getClassCodes()) {
        for (ClassCode oldClassCode : oldUCCode.getClassCodes()) {
            int studentsDiff = static_cast<int>(newUCCode.getClassCodes().size()) - static_cast<int>(oldUCCode.getClassCodes().size());
            if (abs(studentsDiff) > 4) {
                return false; // The balance would be disturbed, so the student cannot switch
            }
        }
    }

    // Rule 4: There is no conflict between the student's schedule and the new class's schedule
    for (ClassCode classCode : newUCCode.getClassCodes()) {
        for (Schedule classSchedule : classCode.getSchedule()) {
            for (Schedule studentSchedule : student.getSchedule()) {
                if (student.hasScheduleConflict(classSchedule, studentSchedule)) {
                    return false; // There is a schedule conflict, so the student cannot switch
                }
            }
        }
    }

    return true; // All constraints are met, so the student can switch to the new UC
}