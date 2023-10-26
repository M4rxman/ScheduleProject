#ifndef STUDENT_CLASSES_H
#define STUDENT_CLASSES_H

#include <string>
#include <vector>

using namespace std;

class StudentClasses {
    string _studentCode;
    string _studentName;
    string _ucCode;
    string _classCode;

public:
    StudentClasses();
    StudentClasses(string studentCode,string studentName, string ucCode, string classCode);
    void SetStudentCode(string studentCode);
    void SetStudentName(string studentName);
    void SetUcCode(string ucCode);
    void SetClassCode(string classCode);
    string GetStudentCode();
    string GetStudentName();
    string GetUcCode();
    string GetClassCode();
    bool operator < (const StudentClasses& code) const;
};

#endif // STUDENT_CLASSES_H