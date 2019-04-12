#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // time
    float t = ofGetElapsedTimef();
    float pct = ofMap(sin(t), -1.0, 1.0, 0.0, 1.0);
    
    // two points
    auto a = glm::vec2(100, ofGetHeight()/2);
    auto b = glm::vec2(ofGetWidth() - 100, ofGetHeight()/2);
    
    // linear
    // auto c = ((1.0 - pct) * a) + (b * pct);
    
    
    // we can use any curve function :)
    // auto f = 1.0 - pow(abs(pct), 0.5);
    // auto c = ((1.0 - f) * a) + (b * f);
    
    // we can use any of these tweening equations
    // https://github.com/satoruhiga/ofxEasingFunc/blob/master/src/ofxEasingFunc.h
    auto f = ofxEasingFunc::Cubic::easeInOut(pct);
    auto c = glm::lerp(a, b, f);
    
    ofSetColor(255);
    ofDrawCircle(c, 10);
    
    ofSetColor(20);
    ofDrawLine(a, b);
    ofDrawCircle(a, 3);
    ofDrawCircle(b, 3);
    
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
