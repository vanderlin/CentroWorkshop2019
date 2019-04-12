#include "ofApp.h"

ofColor * colorPtr = nullptr;
ofColor color;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(20);

    
    // a null pointer of type ofColor
    colorPtr = nullptr;
    
    // a color object
    color.set(255);
    cout << color << endl;
    
    // set colorPtr to reference color
    colorPtr = &color;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update the color pointer -- referencing the color object
    // on mouse press we set colorPtr to reference color
    // on release we set it to nullptr
    if (ofGetMousePressed()) {
        colorPtr = &color;
    }
    else {
        colorPtr = nullptr;
    }
    
    if (colorPtr) {
        colorPtr->set(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 255.0, true));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the background with color
    ofBackground(color);
    
    // you can also use color pointer but you will
    // need to dereference the pointer
    // ofBackground(*colorPtr);
    
    // print out values
    ofDrawBitmapStringHighlight("color "+ofToString(color), 20, 20);
    if (colorPtr) ofDrawBitmapStringHighlight("color ptr "+ofToString(*colorPtr), 20, 60);
    else ofDrawBitmapStringHighlight("color ptr "+ofToString("nullptr"), 20, 60);

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
