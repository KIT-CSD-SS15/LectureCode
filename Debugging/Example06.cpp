//
//  Example06.cpp
//  Debugging
//
//  Created by Manuel Giffels on 16.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>

unsigned long arth_sum(unsigned long value) {
    unsigned long result = 0;
    
    for (unsigned int i=0; i<=value; ++i) {
        result+=i;
    }
    
    return result;
}

unsigned long gaussian_sum(unsigned long value) {
    return value * (value+1) /2;
}

unsigned long alt_gaussian_sum(unsigned long value) {
    return (value * (value+1)) >> 1;
}

int main(int argc, char* argv[]) {
    unsigned int my_value = 1000000000;
    unsigned int repetition = 500000000;
    while (repetition--){
        gaussian_sum(my_value);
        alt_gaussian_sum(my_value);
    }
    std::cout << "arth_sum: " << arth_sum(my_value) << std::endl;
    std::cout << "gaussian_sum: " << gaussian_sum(my_value) << std::endl;
    std::cout << "alt_gaussian_sum: " << alt_gaussian_sum(my_value) << std::endl;
    
    return 0;
}
