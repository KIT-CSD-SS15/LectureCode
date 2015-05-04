//
//  Figures.cpp
//  Polymorphism
//
//  Created by Manuel Giffels on 16.10.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <string>

class Polygon { //abstract base class
public:
    Polygon(double width, double height):m_width(width), m_height(height){}
    virtual const double area() const = 0; //pure virtual function
    virtual const std::string polygon_type() const = 0; //pure virtual function
protected:
    const double m_height;
    const double m_width;
};

class Rectangle: public Polygon {
public:
    Rectangle(double width, double height):Polygon(width, height){}
    const double area() const{return m_width*m_height;}
    const std::string polygon_type() const {return std::string("Rectangle");}
};

class Triangle: public Polygon {
public:
    Triangle(int width, int height):Polygon(width, height){}
    const double area() const{return m_width*m_height/2.;}
    const std::string polygon_type() const {return std::string("Triangle");};
};


void print_polygon(const Polygon& my_polygon){
    std::cout << "Area of " << my_polygon.polygon_type()
    << ": " << my_polygon.area() << std::endl;
}

int main(int argc, char* argv[]){
    Triangle my_triangle = Triangle(3, 4);
    print_polygon(my_triangle);
    Rectangle my_rectangle = Rectangle(3, 4);
    print_polygon(my_rectangle);
}
