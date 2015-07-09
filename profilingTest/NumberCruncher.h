#pragma once
#include <iostream>
#include <vector>

class NumberCruncher
{
public:
  int sumUpTo(int number){
    int current = 0;
    for (int ii = 1; ii<= number; ++ii){
      current = sum(current, ii);
      for (int jj = 0; jj < 1000000; ++jj){
        ;
      }
    }
    return current;
  }

  void addTwoVectors() {
    std::vector<int> vector1(10000);
    std::vector<int> vector2(10000);

    std::vector<int> vector3(10000);

    for (int ii = 0; ii < 10000; ++ii){
      vector1[ii] = ii;
      vector2[ii] = ii * 3;
    }

    for (int ii = 0; ii < 10000; ++ii){
      for (int jj = 0; jj < 10000; ++jj){
        vector2[jj] = vector1[jj]+vector2[ii];
      }
    }
  }

private:
  int sum(int number1, int number2 ){
    for (int jj = 0; jj < 1000000; ++jj){
      ;
    }
    return number1 + number2;
  }
};
