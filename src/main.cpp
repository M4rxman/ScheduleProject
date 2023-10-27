#include <iostream>
#include "ClassesPerUc.h"

int main(int argc, char* argv[]) {
    std::cout << "AED" << std::endl;

    ClassesPerUc myClass;
    ifstream MyReadFile("C:\\Users\\alex2\\Downloads\\schedule\\Data\\classes_per_uc.csv");
    myClass.readFile(MyReadFile);
    myClass.writeFile();

}
