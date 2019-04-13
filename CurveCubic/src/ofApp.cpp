#include "ofApp.h"

static glm::vec2 quadraticPoint(glm::vec2 p0, glm::vec2 p1, glm::vec2 p2, float t) {
    auto c = glm::vec2();
    c.x = pow(1.0 - t, 2) * p0.x + (1.0 - t) * 2 * t * p1.x + t * t * p2.x;
    c.y = pow(1.0 - t, 2) * p0.y + (1.0 - t) * 2 * t * p1.y + t * t * p2.y;
    return c;
}

static glm::vec2 cubicPoint(glm::vec2 p0, glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, float t) {
    auto c = glm::vec2();
    c.x = pow(1.0 - t, 3) * p0.x + pow(1.0 - t, 2) * 3 * t * p1.x + (1.0 - t) * 3 * t * t * p2.x + t * t * t * p3.x;
    c.y = pow(1.0 - t, 3) * p0.y + pow(1.0 - t, 2) * 3 * t * p1.y + (1.0 - t) * 3 * t * t * p2.y + t * t * t * p3.y;
    return c;
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(232, 180, 150);

    bUseCubic = true;
    
    // make 4 random points
    points.addVertex(200, ofRandom(100, ofGetHeight()-100));
    points.addVertex(ofRandom(300, 400), ofRandom(100, ofGetHeight()-100));
    points.addVertex(ofGetWidth()/2, ofRandom(100, ofGetHeight()-100));
    points.addVertex(ofGetWidth()-200, ofRandom(100, ofGetHeight()-100));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float resolution = 0.005;
    
    ofSetColor(20);
    points.draw();
    for(auto &pnt : points) {
        ofDrawCircle(pnt, 3);
    }
    
    ofPolyline curveLine;
    
    // create curve using a quadratic function
    if (!bUseCubic && points.size() >= 3) {
        for(float f=0; f<=1.001; f+=resolution) {
            
            auto p0 = points[0];
            auto p1 = points[1];
            auto p2 = points[2];
            
            auto point = quadraticPoint(p0, p1, p2, f);
            
            curveLine.addVertex(point.x, point.y);
        }
      
    }
    
    // create curve using a cubic function
    if (bUseCubic && points.size() >= 4) {
        for(float f=0; f<=1.001; f+=resolution) {
            
            auto p0 = points[0];
            auto p1 = points[1];
            auto p2 = points[2];
            auto p3 = points[3];
            
            auto point = cubicPoint(p0, p1, p2, p3, f);
            
            curveLine.addVertex(point.x, point.y);
        }
        
    }
    
    // draw the curve line
    ofSetColor(255);
    for(auto &pnt : curveLine) {
        ofDrawCircle(pnt, 2);
    }
    curveLine.draw();
    
    float pct = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 1.0);
    auto pointAlongCurve = curveLine.getPointAtPercent(pct);
    
    ofDrawCircle(pointAlongCurve, 10);
    
    // draw some info
    ofDrawBitmapStringHighlight(bUseCubic ? "Cubic" : "Quadratic", 20, 20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        points.clear();
    }
    if (key == ' ') {
        bUseCubic = !bUseCubic;
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
    if (pointIndex != -1) {
        points[pointIndex].x = x;
        points[pointIndex].y = y;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    auto mouse = glm::vec2(x, y);
    
    for(int i=0; i<points.size(); i++) {
        if (glm::length(mouse - points[i]) < 30) {
            pointIndex = i;
            break;
        }
    }
    
    if (pointIndex == -1) {
        int maxPoints = bUseCubic ? 4 : 3;
        
        if (points.size() >= maxPoints) {
            points.getVertices().erase(points.begin());
        }
        points.addVertex(x , y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pointIndex = -1;
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
