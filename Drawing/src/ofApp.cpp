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

    
    // 01
    // draw a circle at mouse position
    /*
    auto mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
    ofDrawCircle(mouse, 100);
    */
    
    
    // 02
    // get mouse speed
    /*
    auto mouseVector = mouse - glm::vec2(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    auto speed = ofClamp(glm::length(mouseVector), 2, 10);
    ofDrawCircle(mouse, 10 + speed);
    */
    
    // 03
    // draw all of our points
    for(int i=1; i<points.size(); i++) {
        auto &pointB = points[i-1];
        auto &pointA = points[i];
        ofSetColor(232, 102, 146);
        ofDrawLine(pointA, pointB);
    }
  
    
    // 04
    // draw points as cricles and size
    // based on distance from each other
    for(int i=1; i<points.size(); i++) {
     
        auto &pointA = points[i-1];
        auto &pointB = points[i];
        
        // distance from a - b
        float dis = glm::length(pointA - pointB);
        
        // the radius is half the distance
        float radius = dis * 0.5;
        
        // get the middle point from between a - b
        auto middle = (pointA - pointB) * 0.5;
        
        // draw the circle in the middle
        ofSetColor(232, 102, 146);
        ofDrawCircle(pointB + middle, radius);
        
        // draw a dot at a & b
        ofSetColor(20);
        ofDrawCircle(pointA, 1);
        ofDrawCircle(pointB, 1);
    }
    
    
    
    
    // 05
    // draw points as rectangle and size based on distance
    // from each other and rotate based on the angle btween a - b
    /*
    for(int i=1; i<points.size(); i++) {
        
        auto &pointA = points[i-1];
        auto &pointB = points[i];
        
        // the vector from a - b
        auto vec = pointA - pointB;
        
        // distance from a - b
        float dis = glm::length(vec);
        
        // angle in radians
        float angle = -1 * atan2(-vec.y, vec.x);
        
        // get the middle point from between a - b
        auto middle = (pointA - pointB) * 0.5;
        
        // draw the circle in the middle
        ofSetColor(232, 102, 146);
        ofPushMatrix();
        ofTranslate(pointA - middle);
        ofRotateDeg(ofRadToDeg(angle));
        
        ofNoFill();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(0, 0, dis, 30);
        ofSetRectMode(OF_RECTMODE_CORNER);
        
        ofPopMatrix();
        
        // draw a dot at a & b
        ofSetColor(20);
        ofDrawCircle(pointA, 1);
        ofDrawCircle(pointB, 1);
    }
    */
   
    // 06
    // remove points if we have more than 100 points
    if (points.size() > 100) {
        points.erase(points.begin());
    }
   
    
    // 07
    // draw many line paths
    for(auto &line : lines) {
        for(int i=1; i<line.size(); i++) {
            
            auto &pointA = line[i-1];
            auto &pointB = line[i];
            
            // the vector from a - b
            auto vec = pointA - pointB;
            
            // distance from a - b
            float dis = glm::length(vec);
            
            ofSetLineWidth(3);
            ofSetColor(232, 102, 146);
            ofDrawLine(pointA, pointB);
            ofSetLineWidth(1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'c') {
        points.clear();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    points.push_back(glm::vec2(x, y));
    
    //lines.back().push_back(glm::vec2(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    points.push_back(glm::vec2(x, y));
    
    //vector <glm::vec2> line = {glm::vec2(x, y)};
    //lines.push_back(line);
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
