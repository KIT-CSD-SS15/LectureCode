//
//  Exercise01.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 02.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <thread>
#include <vector>

void helloworld() {
    std::cout << "Hello World from thread_id: " << std::this_thread::get_id() << "!" << std::endl;
}

int main(int argc, char* argv[]) {

    std::cout << "My hardware supports " << std::thread::hardware_concurrency()
              << " concurrent processes!" << std::endl;
    
    const unsigned num_of_threads(10);
    
    std::vector<std::thread> my_threads;
    
    for(unsigned i=0; i<num_of_threads; ++i) {
        my_threads.emplace_back(std::thread(helloworld));
    }
    
    for (auto &iter: my_threads) {
        if(iter.joinable())
            iter.join();
    }
    
    return 0;
}