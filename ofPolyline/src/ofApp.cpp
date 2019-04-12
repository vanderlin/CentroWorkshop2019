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
    
    ofSetColor(232, 102, 146);
    
    // 01
    // take the points and resample so
    // that there are always 20 points
    /*
     ofPolyline resampled = line.getResampledByCount(20);
     resampled.draw();
     
     // draw the points
     for(auto &pt : resampled) {
        ofSetColor(0);
        ofDrawCircle(pt, 2);
     }
     */
    
    // 02
    // take the points and resample
    // them to be spaced every 10px
    ofPolyline resampled = line.getResampledBySpacing(10);
    resampled.draw();
    
    // draw the points
    for(auto &pt : resampled) {
        ofSetColor(0);
        ofFill();
        ofDrawCircle(pt, 2);
    }
    
    
    // 03
    // get a point at a percentage along the
    // line. we get the mouse percentage along
    // the x axis - only if mouse is not pressed.
    /*if (line.size() && !ofGetMousePressed()) {
        float pct = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 1.0, true);
        auto point = line.getPointAtPercent(pct);
        ofSetColor(255);
        ofDrawCircle(point, 20);
        
        ofDrawBitmapStringHighlight(ofToString(pct*100, 1)+"%", ofGetMouseX(), ofGetMouseY());
    }*/
    
    
    // 04
    // Get the bounds and center based on the point
    /*
    auto bounds = line.getBoundingBox();
    auto center = line.getCentroid2D();
    ofSetColor(255);
    
    ofFill();
    ofDrawCircle(center, 30);
    
    ofNoFill();
    ofDrawRectangle(bounds);
    */
    
    
    // 05
    // Get perpendicular lines for each point
    // we will do this manully then the ofPolyline way
    /*for(int i=1; i<line.size(); i++) {
        auto & a = line[i-1];
        auto & b = line[i];
        
        // get the vector from a - b
        auto v = a - b;
        
        // normalize this vector
        // (or by hand)
        //float len = sqrt(v.x * v.x + v.y * v.y);
        //if (len > 0.0) {
        //    v /= len;
        //}
        v = glm::normalize(v);
        
        // get the perpendicular
        auto perp = glm::vec2(-v.y, v.x);
        
        // or simiply the ofPolyline way
        // perp = line.getNormalAtIndex(i);
        
        // draw this perpendicular line
        ofDrawLine(a, a + (perp * 10));
        ofDrawLine(a, a - (perp * 10));
        
    }*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        line.clear();
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
    line.addVertex(x, y);
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
