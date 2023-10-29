#include <iostream>
#include "ClassesSchedule.h"

int main(int argc, char* argv[]) {
    std::cout << "AED" << std::endl;

    ClassesPerUc classesPerUc;
    ifstream classes_per_uc("C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes_per_uc.csv");
    classesPerUc.readFile(classes_per_uc);
    classesPerUc.printData();

   ClassesSchedule classesSchedule;
    ifstream classes("C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes.csv");
    classesSchedule.readFile(classes, classesPerUc);
    //classesSchedule.writeFile();


}
