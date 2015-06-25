//
//  Example02.cpp
//  Debugging
//
//  Created by Manuel Giffels on 10.12.14.
//  Copyright (c) 2014 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <vector>

std::vector<int>* convert(int array[], int size)
{
    std::vector<int> tmp;
    
    for(int i=0; i<size; ++i)
    {
        tmp.push_back(array[i]);
    }
    
    return &tmp;
}

int main (int argc, char* argv[])
{
    
    int array[] = {1,2,3,4,5};
    
    std::vector<int>* myvector = convert(array,5);
    
    std::vector<int>::iterator iter;
    
    std::cout << "Ergebnis: ";
    
    for(iter=myvector->begin(); iter!=myvector->end(); ++iter)
        std::cout << *iter << " ,";
    
    delete myvector;
    
    std::cout << std::endl;
    
    return 0;
}