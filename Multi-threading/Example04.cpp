//
//  Example03.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 02.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <chrono>
#include <iostream>
#include <thread>

void helloworld() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Hello World!" << std::endl;
    }
}

void startthread() {
    //Start a daemon thread
    std::thread my_thread(helloworld);
    my_thread.detach();
}

int main(int argc, char* argv[]) {
    startthread();
    //wait 10 seconds before exiting main
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Exit main!" << std::endl;
    return 0;
}
