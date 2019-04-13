//
//  Segment.hpp
//  ParticlesConnections
//
//  Created by tvanderlin on 4/13/19.
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class Segment {
public:
    
    Particle * a;
    Particle * b;
    float length;
    
    Segment(Particle * a, Particle * b, float length) {
        this->a = a;
        this->b = b;
        this->length = length;
    }
    
};
