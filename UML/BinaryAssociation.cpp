//
//  BinaryAssociation.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

class ClassA;

class ClassB{
public:
    void service() {return;}
    void doSomething() {return;}
    void setA(ClassA* a) {m_class_a=a;}
private:
    ClassA* m_class_a;
};

class ClassA{
public:
    void doWork() {return;}
    void setB(ClassB* b) {m_class_b=b;}
private:
    ClassB* m_class_b;
};

int main(int argc, char* argv[]) {
    ClassA my_class_a = ClassA();
    ClassB my_class_b = ClassB();
    
    my_class_a.setB(&my_class_b);
    my_class_b.setA(&my_class_a);
}