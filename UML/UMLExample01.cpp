//
//  UMLExample01.cpp
//  UML
//
//  Created by Manuel Giffels on 12.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <string>

class Example {
public:
    Example(double x):m_x(x){}
    double x() {return m_x;}
    static std::string class_name() {return m_class_name;}
private:
    double m_x;
    static std::string m_class_name;
};

std::string Example::m_class_name = "Example";

int main(int argc, char* argv[]) {
    Example my_example1 = Example(1.41);
    Example my_example2 = Example(3.14);
    
    std::cout << "x: " << my_example1.x() << " class_name: " << my_example1.class_name() << std::endl;
    std::cout << "x: " << my_example2.x() << " class_name: " << my_example2.class_name() << std::endl;
    std::cout << "class_name: " << Example::class_name() << std::endl;
    return 0;
}
