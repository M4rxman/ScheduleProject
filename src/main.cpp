#include <iostream>
#include "ClassesSchedule.h"
#include "StudentsClasses.h"

int main(int argc, char* argv[]) {
    std::cout << "AED" << std::endl;

    ClassesPerUc classesPerUc;
    ifstream classes_per_uc("C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes_per_uc.csv");
    classesPerUc.readFile(classes_per_uc);
    classesPerUc.printData();

    std::cout << "Classes Schedule" << std::endl;

   ClassesSchedule classesSchedule;
    ifstream classes("C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes.csv");
    classesSchedule.readFile(classes, classesPerUc);
    classesSchedule.printData(classesPerUc);

    std::cout << "Student Classes" << std::endl;

    StudentsClasses studentsClasses;
    ifstream student_classes("C:\\Users\\alex2\\Downloads\\schedule\\Data\\students_classes.csv");
    studentsClasses.readFile(student_classes);
    studentsClasses.printData();

}
