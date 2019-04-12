#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float t = ofGetElapsedTimef();
    
    // 1D
//    float nx = ofNoise(t);
//    float ny = ofNoise(10 + t);
    
    // 2D
//     float nx = ofNoise(20, t);
//     float ny = ofNoise(100, t);
    
    // try it 3D noise
    float nx = ofNoise(20, t, 10);
    float ny = ofNoise(100, t, 55);
    
    glm::vec2 pos;
    
    pos.x = ofMap(nx, 0, 1, 0, ofGetWidth());
    pos.y = ofMap(ny, 0, 1, 0, ofGetHeight());
    
    ofFill();
    ofSetColor(255);
    ofDrawCircle(pos, 30);
    
    // using a loop we can see the steps in the noise
    // we need scale "i" for smoother results
    /*
    float scale = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 0.2, true);
    for(int i=0; i<100; i++) {
        
        // 1D
        float nx = ofNoise(t + i * scale);
        float ny = ofNoise(10 + t + i * scale);

        // 2D
        // float nx = ofNoise(20, t + i * scale);
        // float ny = ofNoise(100, t + i * scale);

        // try it 3D noise
        //float nx = ofNoise(20, t + i * scale, 10);
        //float ny = ofNoise(100, t + i * scale, i * scale);

        glm::vec2 pos;

        pos.x = ofMap(nx, 0, 1, 0, ofGetWidth());
        pos.y = ofMap(ny, 0, 1, 0, ofGetHeight());
        
        ofFill();
        ofSetColor(255);
        ofDrawCircle(pos, 3);
    }*/
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
