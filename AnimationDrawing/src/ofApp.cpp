#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    // time
    float t = ofGetElapsedTimef() * 5;
    
    // how many circles do we draw
    int num = 100;
    
    for(int i=0; i<num; i++) {
        
        // normalize i so that its between 0 - 1
        float n = ofMap(i, 0, num-1, 0.0, 1.0);
        
        // map x across the screen
        float x = 100 + (n * (ofGetWidth()-200));

        // make a sin func based on time + n then scale
        auto f = sin(t + n) * 10.0;

        auto rad = 20 + sin((n * TWO_PI) + t) * 20;

        // go wild here!
        ofSetColor(120 + sin(f * 0.1) * 120,
                   120 + sin(f * 0.01) * 120,
                   120 + sin(f * 0.001) * 120);
        
        // draw a circle
        ofDrawCircle(x, ofGetHeight()/2, rad);
        
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
