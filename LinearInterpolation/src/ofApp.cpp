#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    ofBackground(232, 180, 150);
    
    a.x = 0;
    a.y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // set b to the mouse
    b.x = ofGetMouseX();
    b.y = ofGetMouseY();
    
    // we have (t) as the increasing percentage
    t += 0.01;
    if (t > 1.0) t = 0.0;
    
    // linear interpolation formula
    auto c = ((1.0 - t) * a) + (t * b);
    
    // (a, b) are dark gray
    ofSetColor(20);
    ofDrawCircle(a, 10);
    ofDrawCircle(b, 10);
    ofDrawLine(a, b);
    
    // (c) is white the interpolated point
    ofSetColor(255);
    ofDrawCircle(c, 20);
    
    // draw some of this information for us to see
    string info = "fps "+ofToString(ofGetFrameRate(), 1) + "\n";
    
    // what is t 0-1 and %
    info += "t "+ofToString(t) + "\n";
    info += "t "+ofToString(t * 100, 1) + "%\n";
    ofDrawBitmapStringHighlight(info, 20, 20);
    
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
