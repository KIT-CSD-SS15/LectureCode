//
//  Rectangle.cpp
//  Polymorphism
//
//  Created by Manuel Giffels on 04.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//
#include <iostream>

class Rectangle {
public:
    Rectangle(double width, double height):m_width(width), m_height(height){}
    const double area() const{
        return m_width*m_height;
    }
private:
    const double m_width;
    const double m_height;
protected:
    double m_demonstrate_only;
};

int main(int argc, char* argv[]){
    Rectangle my_rectangle = Rectangle(3, 4);
    std::cout << my_rectangle.area() << std::endl;
}
