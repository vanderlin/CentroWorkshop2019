#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofBackground(20);
    
    gui.setup("particles");
    gui.add(gravity.set("gravity", 0.0, -0.5, 0.5));
    gui.add(repelScale.set("repel scale", 1.0, 0.1, 3.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    auto mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
    auto center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);

    /*
    float radius = 100;
    ofSetColor(255);
    ofDrawCircle(center, radius);
    ofSetColor(0);
    ofDrawCircle(center, 1);
    
    auto vec = center - mouse;
    float len = glm::length(vec);
    float pct = 1 - (len / radius);

    ofDrawBitmapStringHighlight("len " + ofToString(len) + "\npct "+ofToString(pct), 220, 220);
    */
    
    
    //for(auto &particle : particles) {
    for(int i=0; i<particles.size(); i++) {
        
        Particle & particle = particles[i];
        
        //add some downward force
        particle.acc.y += gravity;
        
        // avoid the mouse
        particle.repel(mouse.x, mouse.y, 100, 1.0);
        
        particle.repel(center.x, center.y, 300, 2.0);
        
        // force to the center of screen
        particle.attract(center.x, center.y, 600);

        // rotate around screen center
        particle.rotate(center.x, center.y, 600, 0.2);
        
        for(int j=i-1; j>=0; j--) {
            Particle & other = particles[j];
            float minDis = (particle.radius + other.radius) + 10;
            particle.repel(other, minDis, repelScale);
        }
    }
    
    for(auto &particle : particles) {
        particle.update();
        particle.checkForWalls(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
    }
    
    for(auto &particle : particles) {
        ofFill();
        ofSetColor(255, 29, 150);
        ofDrawCircle(particle.pos, particle.radius);
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        Particle particle(ofGetMouseX(), ofGetMouseY());
        particle.vel.x = ofRandom(-2, 2);
        particle.vel.y = ofRandom(-2, 2);
        particle.vel *= 0;
        //particle.vel *= 10;
        
        particles.push_back(particle);
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

    Particle particle(x, y);
    particle.vel.x = ofRandom(-2, 2);
    particle.vel.y = ofRandom(-2, 2);
    
    //particle.vel *= 10;
    
    particles.push_back(particle);
    
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
