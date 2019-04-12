#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(60);    
    ofBackground(232, 180, 150);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // time
    float t = ofGetElapsedTimeMillis() * 0.001;
    float pct = ofMap(sin(t), -1.0, 1.0, 0.0, 1.0);
    
    
    // two points
    auto a = glm::vec2(100, ofGetHeight()/2);
    auto b = glm::vec2(ofGetWidth() - 100, ofGetHeight()/2);
    
    
    // raise pct to a power between 0 - 1
    float power = ofMap(ofGetMouseX(), 100, ofGetWidth()-100, 0.0, 1.0, true);
    
    
    float f = powf(pct, power);
    auto c = ((1.0 - f) * a) + (b * f);
    
    ofSetColor(255);
    ofDrawCircle(c, 10 + (10 * f));
    
    ofSetColor(20);
    ofDrawLine(a, b);
    ofDrawCircle(a, 3);
    ofDrawCircle(b, 3);
    
    
    int steps = 20;
    for(int i=0; i<steps; i++) {
        
        float f = ofMap(i, 0, steps-1, 0.0, 1.0);
        float pct = powf(f, power);
        
        auto c = ((1.0 - pct) * a) + (b * pct);
        
        ofSetColor(0, 100);
        ofDrawCircle(c, 2 + (10 * pct));
    }
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
