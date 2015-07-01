//
//  Example01.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 02.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <thread>

void helloworld() {
    std::cout << "Hello World!" << std::endl;
}

void startthread() {
    //Start a daemon thread
    std::thread my_thread(helloworld);
}

int main(int argc, char* argv[]) {
    startthread();
    std::cout << "Thread started!" << std::endl;
    return 0;
}