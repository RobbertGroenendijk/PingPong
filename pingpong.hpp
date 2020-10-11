//
//  pingpong.hpp
//  worley_1
//
//  Created by Robbert Groenendijk on 14/07/2020.
//

#ifndef pingpong_hpp
#define pingpong_hpp

#include "ofMain.h"

class Pingpong {
public:
    Pingpong();
    ~Pingpong();
    void allocate(unsigned int width, unsigned int height);
    void swap();
    ofFbo* getDisplayBuffer();
    ofFbo* getReadBuffer();
    ofFbo* getBuffer(unsigned int bufferNumber);
private:
    ofFbo* pingpongBuffer_[2];
    ofFbo buffer1_;
    ofFbo buffer2_;
    
};

#endif /* pingpong_hpp */
