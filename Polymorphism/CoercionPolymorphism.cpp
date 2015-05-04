//
//  Casting.cpp
//  Polymorphism
//
//  Created by Manuel Giffels on 04.11.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

int main(int argc, char* argv[]) {
    float my_float = 4; //implicit cast from int to float data type
    int my_int = 5.5;   //implicit cast from float to int data type
    float my_float2 = static_cast<float>(my_int); //explicit cast from int to float data type
}