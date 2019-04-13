#pragma once

#include "ofMain.h"

class Dot {
public:
    
    float x, y, radius;
    ofColor color;
    
    Dot(float x, float y) {
        this->x = x;
        this->y = y;
        radius = ofRandom(10, 50);
        color.set(ofRandom(255));
    }
    
    void draw() {
        ofFill();
        ofSetColor(color);
        ofDrawCircle(x, y, radius);
    }
    
};

class ofApp : public ofBaseApp{

	public:
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector <Dot> myDots;
    
    
};
