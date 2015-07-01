//
//  Example07.cpp
//  Multi-threading
//
//  Created by Manuel Giffels on 04.02.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//

#include <iostream>
#include <string>
#include <thread>

class Radio {
public:
    Radio(std::string band):m_band(band){
    }
    
    Radio(const Radio& other_radio){
        m_band = other_radio.m_band;
    }
    
    std::string get_band(void) {
        return m_band;
    }
    
    void toggleAMFM() {
        if(m_band==std::string("FM"))
           m_band = std::string("AM");
        else
           m_band = std::string("FM");
    }
private:
    std::string m_band;
};

void toggle(Radio& radio) {
    radio.toggleAMFM();
    std::cout << radio.get_band() << std::endl;
}

int main(int argc, char* argv[]) {
    Radio my_radio("FM");
    auto radio_toggle = std::bind(toggle, my_radio);
    std::thread my_thread(radio_toggle);
    
    if (my_thread.joinable())
        my_thread.join();
    
    std::cout << my_radio.get_band() << std::endl;
    
    return 0;
}
