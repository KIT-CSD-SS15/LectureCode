//
//  Example06.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 03.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <thread>

void helloworld(std::string name) {
    std::cout << "Hello " << name
    << "!" << std::endl;
}

int main(int argc, char* argv[]) {
    std::thread my_world_thread(helloworld,
                                std::string("World"));
    
    if (my_world_thread.joinable())
        my_world_thread.join();
    
    auto hellouniverse = std::bind(helloworld,
                                   std::string("Universe"));
    std::thread my_universe_thread(hellouniverse);
    
    if (my_universe_thread.joinable())
        my_universe_thread.join();
    
    return 0;
}

