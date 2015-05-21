#pragma once                  //make sure, file is included once
#ifndef IDENTIFIER            //"if not defined" do something
#define IDENTIFIER            //define an identifier
#define SQUARE(x) x*x         //brackets 
#else                         //basically like else
#define SQUARE(x) x*x*x       //brackets 
#endif                        //closing bracket with ifndef
#include <iostream>

int main ()
{
  std::cout << SQUARE(2) 
            << "; in line: "
            <<  __LINE__     //double __ prefix marks attributes
            << std::endl;
}

