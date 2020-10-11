//
//  pingpong.cpp
//  worley_1
//
//  Created by Robbert Groenendijk on 14/07/2020.
//

#include "pingpong.hpp"

Pingpong::Pingpong() {
    std::cout << "Pingpong buffer initiated" << std::endl;
    pingpongBuffer_[0] = &buffer1_;
    pingpongBuffer_[1] = &buffer2_;
}
Pingpong::~Pingpong() {
    std::cout << "Pingpong buffer destroyed" << std::endl;
}
void Pingpong::allocate(unsigned int width, unsigned int height) {
    buffer1_.allocate(width, height, GL_RGBA);
    buffer2_.allocate(width, height, GL_RGBA);
}
void Pingpong::swap() {
    ofFbo* temp_pntr = pingpongBuffer_[0];
    pingpongBuffer_[0] = pingpongBuffer_[1];
    pingpongBuffer_[1] = temp_pntr;
    
    //std::cout << "Pingpong buffers swapped" << std::endl;
}
ofFbo* Pingpong::getDisplayBuffer() {
    return pingpongBuffer_[0];
}
ofFbo* Pingpong::getReadBuffer(){
    return pingpongBuffer_[1];
}
ofFbo* Pingpong::getBuffer(unsigned int bufferNumber) {
    if (bufferNumber < 2) {
        return pingpongBuffer_[bufferNumber];
    }
    return pingpongBuffer_[0]; // Default return
}
