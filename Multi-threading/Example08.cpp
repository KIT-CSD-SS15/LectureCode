//
//  Example08.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 04.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void print_values(std::vector<int>& vector) {
    for (auto& value: vector)
        std::cout << value << std::endl;
}

void start_thread() {
    std::vector<int> my_vector(100, 0);
    auto print_vector = std::bind(print_values, std::ref(my_vector));
    std::thread my_thread(print_vector);
    
    if (my_thread.joinable())
        my_thread.detach();
}

int main(int argc, char* argv[]) {
    start_thread();
    
    //wait 10 seconds before exiting main
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Exit main!" << std::endl;
    
    return 0;
}
