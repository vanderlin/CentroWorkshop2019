//
//  Particle.hpp
//  Particles
//
//  Created by tvanderlin on 4/13/19.
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    glm::vec2 pos, vel, acc;
    float radius;
    Particle(float x, float y) {
        pos.x = x;
        pos.y = y;
        radius = ofRandom(10, 20);
    }
    
    ~Particle() {
        //cout << "~Particle" << endl;
    }
    
    void checkForWalls(ofRectangle bounds) {
    
        if (pos.y > bounds.getBottom()-radius) {
            pos.y = bounds.getBottom()-radius;
            vel.y *= -1;
        }
        if (pos.y < bounds.getTop()+radius) {
            vel.y *= -1;
            pos.y = bounds.getTop()+radius;
        }
        if(pos.x < bounds.getLeft()+radius) {
            vel.x *= -1;
            pos.x = bounds.getLeft()+radius;
        }
        if(pos.x > bounds.getRight()-radius) {
            vel.x *= -1;
            pos.x = bounds.getRight()-radius;
        }
    }
    
    
    void repel(float x, float y, float minDis, float scale = 1.0) {
        auto vec = glm::vec2(x, y) - pos;
        float len = glm::length(vec);
        
        if (len < minDis && len) {
            
            float pct = 1 - (len / minDis);

            vec /= len;
            acc -= vec * pct * scale;
            
        }
    }
    
    void attract(float x, float y, float minDis, float scale = 1.0) {
        
        auto vec = glm::vec2(x, y) - pos;
        float len = glm::length(vec);
        
        if (len < minDis && len > 0) {
            
            float pct = 1 - (len / minDis);
            
            vec /= len;
            acc += vec * pct * scale;
            
        }
    }
    
    void rotate(float x, float y, float minDis, float scale = 1.0) {
        
        auto vec = glm::vec2(x, y) - pos;
        float len = glm::length(vec);
        
        if (len < minDis && len > 0) {
            
            float pct = 1 - (len / minDis);
            
            vec /= len;
            
            auto perp = glm::vec2(-vec.y, vec.x);
            
            acc += perp * pct * scale;
            
        }
    }
    
    void repel(Particle &other, float minDis, float scale = 1.0) {
        auto vec = other.pos - pos;
        float len = glm::length(vec);
        
        if (len < minDis && len) {
            
            float pct = 1 - (len / minDis);
            
            vec /= len;
            
            acc -= vec * pct * scale;
            other.acc += vec * pct * scale;
            
        }
    }
    
    void update() {
        vel += acc;
        vel *= 0.98;
        pos += vel;
        
        acc *= 0;
    }
    
};
