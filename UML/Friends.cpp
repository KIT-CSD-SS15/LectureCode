//
//  Friends.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

class ClassA {
    friend class ClassB;
public:
    void doWork() {m_x = 3.0;};
private:
    double m_x;
};

class ClassB {
public:
    void service (ClassA& a) {a.m_x = 2.0;}
};

int main(int argc, char* argv[]) {
    ClassA my_class_a = ClassA();
    ClassB my_class_b = ClassB();
    my_class_a.doWork();
    my_class_b.service(my_class_a);
}