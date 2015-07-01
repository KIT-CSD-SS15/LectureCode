//
//  Example04.cpp
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

int main(int argc, char* argv[]) {
    std::thread my_thread(helloworld);
    
    if (my_thread.joinable())
        my_thread.join();
    
    return 0;
}
