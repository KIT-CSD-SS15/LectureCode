//
//  Aggregation.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <vector>

class Student {
public:
    void listen() {return;}
};

class Lecture {
public:
    void talk() {return;}
    void addStudent(Student* student) {m_student.push_back(student);}
private:
    std::vector<Student*> m_student;
};

int main(int argc, char* argv[]) {
    Student my_student = Student();
    Lecture my_lecture = Lecture();
    my_lecture.addStudent(&my_student);
}