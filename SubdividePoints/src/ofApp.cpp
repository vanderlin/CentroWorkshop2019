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

    
    // draw the line
    ofSetColor(20);
    points.draw();
    
    // draw the original points
    for (auto &pt : points) {
        ofSetColor(20);
        ofNoFill();
        ofDrawCircle(pt, 15);
    }
    
    int subdivideNum = 5;
    int totalPoints = subdivideNum * points.size();
    int numPoints = points.size()-1;
    
    float step = 1.0 / float(totalPoints-1);
    
    
    for(int i=0; i<totalPoints; i++) {
        
        float pct = i * step;
        
        float indexf = numPoints * pct;
        float indexI = floor(indexf);
        
        float f = indexf - indexI;
        
        auto a = points[ofClamp(indexI, 0, numPoints)];
        auto b = points[ofClamp(indexI+1, 0, numPoints)];
        
        // now lerp from a-b
        auto c = glm::lerp(a, b, f);

        ofSetColor(i % subdivideNum==0 ? 255 : 0);
        ofFill();
        ofDrawCircle(c, 3);
    }
    
    
    // draw some info to screen
    string info = "num points "+ofToString(points.size()) + "\n";
    info += "subdivide num "+ofToString(subdivideNum) + "\n";
    info += "total "+ofToString(totalPoints) + "\n";
    ofDrawBitmapStringHighlight(info, 20, 20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        points.clear();
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
    points.addVertex(x, y);
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
