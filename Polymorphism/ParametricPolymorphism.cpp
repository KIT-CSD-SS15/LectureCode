//
//  GetMinimum.cpp
//  Polymorphism
//
//  Created by Manuel Giffels on 04.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>

template <class T>
T GetMinimum(T a, T b) {
    return a < b ? a : b;
}

int main(int argc, char* argv[]){
    std::cout << GetMinimum(1, 9) << std::endl;
    
    std::vector<double> double_vec;
    std::vector<std::string> string_vec;
    double_vec.push_back(.1);
    double_vec.push_back(.2);
    string_vec.push_back("Hello");
    string_vec.push_back("World");
}