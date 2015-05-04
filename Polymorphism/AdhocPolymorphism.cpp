//
//  Overloading.cpp
//  Polymorphism
//
//  Created by Manuel Giffels on 04.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>

void MyPrint(int a) {
    std::cout << "This int is: " << a << std::endl;
}

void MyPrint(float a) {
    std::cout << "This float is: " << a << std::endl;
}


int main(int argc, char* argv[]){
    int a = 4;
    float b = 4.1;
    MyPrint(a);
    MyPrint(b);
}