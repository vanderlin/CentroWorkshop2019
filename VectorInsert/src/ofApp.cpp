#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    count = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0; i<items.size(); i++) {
        string b = i == count ? "x" : " ";
        ofDrawBitmapStringHighlight("["+b+"] "+ofToString(items[i].index) + "  ----- "+items[i].name, 30, 30 + i * 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a') {
        Object obj;
        obj.name = "insert "+ofToString(ofGetUnixTime());
        obj.index = items.size();
        int nextIndex = MIN(items.size(), count+1);
        items.insert(items.begin()+(nextIndex), obj);
    }
    if (key == 'p') {
        Object obj;
        obj.name = "push "+ofToString(ofGetUnixTime());
        obj.index = items.size();
        items.push_back(obj);
    }
    
    if (key == 'c') {
        items.clear();
    }
    
    if (count > 0 && key == OF_KEY_UP) {
        count --;
    }
    
    if (count < items.size()-1 && key == OF_KEY_DOWN) {
        count ++;
    }
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
