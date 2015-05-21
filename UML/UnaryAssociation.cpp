//
//  UnaryAssociation.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

class ClassB {
public:
    void service() {return;}
};

class ClassA {
public:
    ClassA(ClassB& b):m_class_b(b){}
    void doWork() {m_class_b.service();}
private:
    ClassB& m_class_b;
};

int main(int argc, char* argv[]) {
    ClassB my_class_b = ClassB();
    ClassA my_class_a(my_class_b);
    return 0;
}