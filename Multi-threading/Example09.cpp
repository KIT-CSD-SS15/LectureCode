//
//  Example09.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 10.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex g_mutex_i, g_mutex_j;

void swap(int& i, int&j) {
    std::lock_guard<std::mutex> lock_i(g_mutex_i);
    int temp = i;
    std::lock_guard<std::mutex> lock_j(g_mutex_j);
    i=j;
    j=temp;
}

void print_values(int&i, int&j) {
    std::lock_guard<std::mutex> lock_j(g_mutex_j);
    std::lock_guard<std::mutex> lock_i(g_mutex_i);
    std::cout << "i is " << i << " and j is " << j << std::endl;
}

int main(int argc, char* argv[]) {
    std::vector<std::thread> my_threads;
    
    int a=0;
    int b=10;
    
    for (unsigned i=0; i<100; ++i)
        if (i%2)
            my_threads.emplace_back(std::thread(swap, std::ref(a), std::ref(b)));
        else
            my_threads.emplace_back(std::thread(print_values, std::ref(a), std::ref(b)));
    
    for (auto &my_thread: my_threads)
        my_thread.join();
    
    return 0;
}