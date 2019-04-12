#include "ofApp.h"

// two points that we want to interpolate
glm::vec2 a, b;

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(232, 180, 150);
    
    
    // make two points
    a = glm::vec2(100, ofRandom(100, ofGetHeight()-100));
    b = glm::vec2(ofGetWidth()-100, ofRandom(100, ofGetHeight()-100));
    
}

//--------------------------------------------------------------
void ofApp::update(){

    float pct = 0.5;
    
    auto a = glm::vec2(100, 200);
    auto b = glm::vec2(200, 300);

    auto c = glm::vec2();
    c.x = ((1.0 - pct) * a.x) + (pct * b.x);
    c.y = ((1.0 - pct) * a.y) + (pct * b.y);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    // make a percentage of mouse x and width of screen
    float pct = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 1.0, true);
    
    // draw points a & b
    ofSetColor(20);
    ofDrawCircle(a, 10);
    ofDrawCircle(b, 10);
    ofDrawLine(a, b);
    
    
    // 01
    // interpolate between these two points
    // the very long way
    // auto c = glm::vec2();
    // c.x = ((1.0 - pct) * a.x) + (pct * b.x);
    // c.y = ((1.0 - pct) * a.y) + (pct * b.y);
    
    // 02
    // the operator overloaded way
    // auto c = ((1.0 - pct) * a) + (pct * b);
    
    // 03
    // the OF way
    // auto c = glm::vec2();
    // c.x = ofLerp(a.x, b.x, pct);
    // c.y = ofLerp(a.y, b.y, pct);
    
    // 04
    // the GLM way (cleanest)
    auto c = glm::lerp(a, b, pct);
    
    // draw point c
    ofSetColor(255);
    ofDrawCircle(c, 20);
    ofDrawLine(a, c);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a = glm::vec2(100, ofRandom(100, ofGetHeight()-100));
    b = glm::vec2(ofGetWidth()-100, ofRandom(100, ofGetHeight()-100));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
