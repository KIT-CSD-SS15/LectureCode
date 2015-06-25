//
//  Example04.cpp
//  Debugging
//
//  Created by Manuel Giffels on 10.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>

int main(int argc, char* argv[])
{
    int test;
    
    float* Heap_Array = new float[100];
    
    if(test==0)
        std::cout << "test ist 0" << std::endl;
    
    Heap_Array[100] = 10.1;
    
    delete Heap_Array;
    
    return 0;
}
