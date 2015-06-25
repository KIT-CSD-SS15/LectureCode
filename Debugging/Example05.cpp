//
//  Example05.cpp
//  Debugging
//
//  Created by Manuel Giffels on 16.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>

int test() {
    int *my_int = new int;
    return 0;
}

int main(int argc, char* argv[]) {
    int *ptr_test;
    test();
    std::cout << *(ptr_test+1000000000000) << std::endl;
    return *ptr_test;
}