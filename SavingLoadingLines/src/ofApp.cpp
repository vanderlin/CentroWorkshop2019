#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(232, 180, 150);
    
    // try and load our xml file
    ofXml xml;
    if (xml.load("lines.xml")) {
        
        /*
        <?xml version="1.0"?>
        <line>
        <point x="284" y="462" />
        <point x="284" y="462" />
        ...
        </line>
         
        <line>
        <point x="284" y="462" />
        <point x="284" y="462" />
        ...
        </line>
        */
        
        // get all the line nodes
        auto lineNodes = xml.getChildren("line");
        
        // loop through each node
        for(auto &lineNode : lineNodes) {
            
            // make a vector to hold all the points
            vector <glm::vec2> line;
            
            // get all the point children
            auto pointNodes = lineNode.getChildren("point");
            
            // loop those points
            for(auto &pntNode : pointNodes) {
                float x = pntNode.getAttribute("x").getFloatValue();
                float y = pntNode.getAttribute("y").getFloatValue();
                line.push_back(glm::vec2(x, y));
            }
            
            // add the new line to the lines vector
            lines.push_back(line);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto &line : lines) {
        for(int i=1; i<line.size(); i++) {
            
            auto &pointA = line[i-1];
            auto &pointB = line[i];
            
            // the vector from a - b
            auto vec = pointA - pointB;
            
            // the vector from a - b
            auto middle = (pointB - pointA) * 0.5;
            
            // distance from a - b
            float dis = glm::length(vec);
            
            ofSetColor(232, 102, 146);
            ofDrawCircle(pointA + middle, dis * 0.5);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'c') {
        lines.clear();
    }
    
    // save our lines
    if (key == 's') {
        
        ofXml xml;
        
        for(auto &line : lines) {
            auto lineNode = xml.appendChild("line");
            for(auto &pt : line) {
                auto pointNode = lineNode.appendChild("point");
                pointNode.setAttribute("x", pt.x);
                pointNode.setAttribute("y", pt.y);
            }
        }
        
        xml.save("lines.xml");
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    lines.back().push_back(glm::vec2(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    vector <glm::vec2> line = {glm::vec2(x, y)};
    lines.push_back(line);
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
