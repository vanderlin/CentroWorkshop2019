//
//  SplineUtils.h
//  bspline
//
//  Created by Todd Vanderlins on 4/9/19.
//
//

#pragma once
#include "ofMain.h"

namespace SplineUtils {
    
    // From the amazing Paul Bourke
    // http://paulbourke.net/miscellaneous/interpolation/
    static float hermiteInterpolate(float y0, float y1, float y2, float y3, float mu, float tension, float bias) {
        
        float m0, m1,mu2,mu3;
        float a0, a1,a2,a3;
        
        mu2 = mu * mu;
        mu3 = mu2 * mu;
        m0  = (y1-y0)*(1+bias)*(1-tension)/2;
        m0 += (y2-y1)*(1-bias)*(1-tension)/2;
        m1  = (y2-y1)*(1+bias)*(1-tension)/2;
        m1 += (y3-y2)*(1-bias)*(1-tension)/2;
        a0 =  2*mu3 - 3*mu2 + 1;
        a1 =    mu3 - 2*mu2 + mu;
        a2 =    mu3 -   mu2;
        a3 = -2*mu3 + 3*mu2;
        
        return(a0 * y1 + a1 * m0 + a2 * m1 + a3 * y2);
    }
    
    static float cubicInterpolate(float y0, float y1, float y2, float y3, float mu) {
        
        float a0,a1,a2,a3,mu2;
        
        mu2 = mu * mu;
        a0 = y3 - y2 - y0 + y1;
        a1 = y0 - y1 - a0;
        a2 = y2 - y0;
        a3 = y1;
        
        return(a0 * mu * mu2 + a1 * mu2 + a2 * mu + a3);
    }
    
    
    static glm::vec2 cubicBezier(const glm::vec2& p0, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3, float t) {
        glm::vec2 point;
        point = t * t * t * (-1 * p0 + 3 * p1 - 3 * p2 + p3) / 6;
        point += t * t * (3 * p0 - 6 * p1 + 3 * p2) / 6;
        point += t * (-3 * p0 + 3 * p2) / 6;
        point += (p0 + 4 * p1 + p2) / 6.0;
        return point;
    }
    
    static glm::vec2 catmullRom(const glm::vec2 &p0, const glm::vec2 &p1, const glm::vec2 &p2, const glm::vec2 &p3, float t) {
        glm::vec2 point;
        point = t * t * t * ((-1.0) * p0 + 3 * p1 - 3 * p2 + p3) / 2;
        point += t * t * (2 * p0 - 5 * p1 + 4 * p2 - p3) / 2;
        point += t * ((-1.0) * p0 + p2) / 2;
        point += p1;
        return point;
    }
    
    // Tension: 1 is high, 0 normal, -1 is low
    // Bias: 0 is even,
    // positive is towards first segment,
    // negative towards the other
    static glm::vec2 hermite(const glm::vec2 &p0, const glm::vec2 &p1, const glm::vec2 &p2, const glm::vec2 &p3, float t, float tension, float bias) {
        float x = hermiteInterpolate(p0.x, p1.x, p2.x, p3.x, t, tension, bias);
        float y = hermiteInterpolate(p0.y, p1.y, p2.y, p3.y, t, tension, bias);
        return glm::vec2(x, y);
    }
    
    static glm::vec2 cubic(const glm::vec2 &p0, const glm::vec2 &p1, const glm::vec2 &p2, const glm::vec2 &p3, float t) {
        float x = cubicInterpolate(p0.x, p1.x, p2.x, p3.x, t);
        float y = cubicInterpolate(p0.y, p1.y, p2.y, p3.y, t);
        return glm::vec2(x, y);
    }
    
};
