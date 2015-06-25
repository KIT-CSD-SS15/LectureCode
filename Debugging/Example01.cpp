//
//  Example01.cpp
//  Debugging
//
//  Created by Manuel Giffels on 08.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//
#include <iostream>

int main (int argc, char* argv[])
{
    int my_value;
    int array[9];
    
    // do not care about this part (just to let the example work on different compilers clang/gcc)
    static volatile int end_of_loop;

    __asm__ __volatile__("subl  %%ebx,%%eax; sarl %%cl,%%eax"
                         :"=a"(end_of_loop)
                         :"a"(&my_value), "b"(&array[0]),  "c"(sizeof(end_of_loop)/2)
                         );
    // do not care about the part above
    
    my_value = 10;
    
    for(int i=0; i<=end_of_loop; ++i)
    {
        array[i] = 0;
    }
    
    std::cout << "My value: " << my_value << std::endl;
    
    return 0;
}
