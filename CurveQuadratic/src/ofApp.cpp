#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(232, 180, 150);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw circles for all points
    for(auto &pt : points) {
        ofSetColor(20);
        ofDrawCircle(pt, 3);
    }
    points.draw();
    
    
    // we must have three points
    if (points.size() == 3) {
        
        int num = 20;
        for(int i=0; i<num; i++) {
        
            float f = ofMap(i, 0, num-1, 0.0, 1.0);
            
            // get the mid point of 0 - 1
            //auto mid0 = ((1.0 - f) * points[0]) + (f * points[1]);
            auto mid0 = glm::lerp(points[0], points[1], f);
            
            // get the mid point of 1 - 2
            //auto mid1 = ((1.0 - f) * points[1]) + (f * points[2]);
            auto mid1 = glm::lerp(points[1], points[2], f);
            
            // draw those points
            ofSetColor(0, 20);
            ofDrawCircle(mid0, 2);
            ofDrawCircle(mid1, 2);
//
            // draw line between mid points
            ofDrawLine(mid0, mid1);

//
            // draw a cicle ad the curve point
            //auto curvePnt = ((1.0 - f) * mid0) + (f * mid1);
            auto curvePnt = glm::lerp(mid0, mid1, f);
            ofDrawCircle(curvePnt, 2);

        }
     
        float maxT = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 1.0, true);
        
        // get the mid point of 0 - 1
        // auto mid0 = ((1.0 - maxT) * points[0]) + (maxT * points[1]);
        auto mid0 = glm::lerp(points[0], points[1], maxT);

        // get the mid point of 1 - 2
        //auto mid1 = ((1.0 - maxT) * points[1]) + (maxT * points[2]);
        auto mid1 = glm::lerp(points[1], points[2], maxT);

        // draw those points
        ofSetColor(0);
        ofDrawCircle(mid0, 3);
        ofDrawCircle(mid1, 3);
        
        // draw line between mid points
        ofDrawLine(mid0, mid1);
    
    
        
        ofPolyline line;
        
        for(float f=0; f<=maxT+.001; f+=0.01f) {
            
            // get the mid point of 0 - 1
            auto mid0 = glm::lerp(points[0], points[1], f);
            
            // get the mid point of 1 - 2
            auto mid1 = glm::lerp(points[1], points[2], f);
            
            // get the curve point based on (mid0 - mid1) * f
            auto curvePnt = glm::lerp(mid0, mid1, f);

            // draw line between mid points
            line.addVertex(curvePnt.x, curvePnt.y);
            
        }
       
        // close the last point
        //if (maxT > 0.9) {
        //    line.addVertex(points[2]);
        //}

        // draw the new curve line
        ofSetColor(232, 102, 146);
        ofSetLineWidth(3);
        line.draw();
        ofSetLineWidth(1);
        
        // draw all the curve points as dots
        for(auto &pt : line) {
            ofSetColor(255);
            ofDrawCircle(pt, 3);
        }

    }
 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    points.clear();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (selectedIndex != -1) {
        points[selectedIndex].x = x;
        points[selectedIndex].y = y;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
   
    auto mouse = glm::vec2(x, y);
    
    // lets see if we touched a point
    for(int i=0; i<points.size(); i++) {
        if (glm::length(mouse - points[i]) < 20) {
            selectedIndex = i;
            break;
        }
    }
    
    // if we didnt
    if (selectedIndex == -1) {
        
        // if we have 3 points remove the last one
        if (points.size() >= 3) {
            points.getVertices().erase(points.begin());
        }
        
        points.addVertex(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    selectedIndex = -1;
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
