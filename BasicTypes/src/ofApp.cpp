#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    ofLog() << "hello" << endl;
    
    int w = ofGetWidth();
    int h = ofGetHeight();
    
    int t = ofGetElapsedTimef();
    
    int mx = ofGetMouseX();
    int my = ofGetMouseY();
    
    string uid = ofToString("01234");
    
    int timestamp = ofGetUnixTime();
    
    int f = ofToFloat("0.1");
    
    int i = ofToInt("100");
    
    float fps = ofGetFrameRate();
    
    // there are many many more.
    
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
