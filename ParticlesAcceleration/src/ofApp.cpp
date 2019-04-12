#include "ofApp.h"

glm::vec2 pos, vel, acc;
float radius = 50;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
    
    vel.x = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 1);
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // we need to reset acceleration
    // so they do not accumulate
    acc *= 0;
    
    // add a downward force
    acc.y += 0.5;
    
    // slow down
    vel *= 0.98;
    
    vel += acc;
    pos += vel;
    
    
    // now hit some walls
    if (pos.y > ofGetHeight() - radius) {
        // move to the edge
        pos.y = ofGetHeight() - radius;
        vel.y *= -1;
    }
    
    if (pos.y < radius) {
        // move to the edge
        pos.y = radius;
        vel.y *= -1;
    }
    
    if (pos.x < radius) {
        // move to the edge
        pos.x = radius;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth() - radius) {
        // move to the edge
        pos.x = ofGetWidth() - radius;
        vel.x *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofDrawCircle(pos, radius);
    
    
    ofDrawBitmapStringHighlight("click for random velocity", 20, 20);
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
    
    vel.x = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 1);
    
    // make it very strong
    vel *= 100;
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
