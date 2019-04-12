#include "ofApp.h"

glm::vec2 pos, vel;

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
    
    pos = pos + vel;
    vel = vel * 0.98;
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofDrawCircle(pos, 10);
    
    
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
