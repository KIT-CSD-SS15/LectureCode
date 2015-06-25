//
//  Example03.cpp
//  Debugging
//
//  Created by Manuel Giffels on 08.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <string>

class TestClass {
public:
    TestClass(std::string my_name){
        std::string m_name = my_name;
    }
    void print(void) {
        std::cout << "m_name is: " << m_name << std::endl;
    }
private:
    std::string m_name;
};

int main(int argc, char* argv[]) {
    TestClass my_test("Hello World");
    my_test.print();
    return 0;
}
