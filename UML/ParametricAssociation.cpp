//
//  ParametricAssociation.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

class ClassB {
public:
    void service() const {return;}
};

class ClassA {
public:
    void doWork(const ClassB& b) {
        b.service();
    }
};

int main(int argc, char* argv[]) {
    ClassB my_class_b = ClassB();
    ClassA my_class_a = ClassA();
    my_class_a.doWork(my_class_b);
}