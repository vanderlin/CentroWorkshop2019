#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(232, 180, 150);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    ofTranslate(50, 50);
    
    float t = ofGetElapsedTimef();

    int steps = 100;


    auto rect = ofRectangle(0, 0, 500, 500);
    ofSetColor(20);
    ofNoFill();
    ofDrawRectangle(rect);

    // half way line
    ofDrawLine(0, 500/2, 500, 500/2);

    for (int i=0; i<steps; i++) {

        // normalize i
        float n = ofMap(i, 0, steps-1, 0.0, 1.0);

        float x = n * 500;
        float dis = 150;
        float y = (dis/2) + sin(n + t) * (dis/2);

        if(i == steps-1) ofDrawBitmapString(ofToString(y, 1), 510, 500/2);

        ofFill();
        ofDrawCircle(x, (500/2) - y, 2);

    }

    ofPopMatrix();
   
    
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
