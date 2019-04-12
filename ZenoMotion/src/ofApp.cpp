#include "ofApp.h"


glm::vec2 pos, target;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
    
    
    // start off the point
    pos = glm::vec2(20, ofGetHeight()/2);
    target = glm::vec2(ofGetWidth()-100, ofGetHeight()/2);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    // zeno motion
    // pos = (target * 0.1) + (pos * 0.9);
    
    // base on speed
    float speed = 0.2;
    pos = (speed * target) + (pos * (1.0 - speed));
    
    // a simple way to write this equation
    // pos += (target - pos) * speed;
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // the target
    ofSetColor(255);
    ofFill();
    ofDrawCircle(target, 20);
    
    // the pos
    ofSetColor(0);
    ofFill();
    ofDrawCircle(pos, 10);
    
    
    ofDrawBitmapStringHighlight("click to move target", 20, 20);
    
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

    target.x = x;
    target.y = y;
    
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
