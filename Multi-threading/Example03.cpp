//
//  Example05.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 04.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <thread>

void thread_id() {
    std::cout << "Thread_id: "
              << std::this_thread::get_id()
              << std::endl;
}

int main(int argc, char* argv[]) {
    std::thread my_thread(thread_id);
                          
    if (my_thread.joinable())
        my_thread.join();
    
    std::cout << "My hardware supports "
              << std::thread::hardware_concurrency()
              << " concurrent processes!"
              << std::endl;
    
    return 0;
}
