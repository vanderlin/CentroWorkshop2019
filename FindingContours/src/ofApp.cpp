#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    video.load("test.mov");
    video.play();
    
    bCaptureBg = true;
    
    thresholdImage.allocate(video.getWidth(), video.getHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void ofApp::update() {
    video.update();
    
    if (video.isFrameNew()) {
        
        float threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0.0, 255.0, true);
        
        cv::Mat grayMat;
        ofxCv::copyGray(video, grayMat);
        
        if (bCaptureBg) {
            ofxCv::copy(grayMat, bgImage);
            bCaptureBg = false;
        }
        
//        cv::Mat diffImage;
//        ofxCv::absdiff(grayMat, bgImage, diffImage);
//
        ofxCv::threshold(grayMat, thresholdImage, threshold);
        
//        ofxCv::invert(thresholdImage);
        
        contourFinder.findContours(thresholdImage);
        
        thresholdImage.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetColor(255);
    video.draw(0, 0);
    
    ofSetColor(161, 20, 69);
    glLineWidth(4);
    //contourFinder.draw();
    
    for(int i=0; i<contourFinder.size(); i++) {
        auto poly = contourFinder.getPolyline(i);
        poly.getResampledBySpacing(20).draw();
    }
    glLineWidth(1);
    
    ofSetColor(255);
    float sw = video.getWidth() / 3;
    float sh = video.getHeight() / 3;
    thresholdImage.draw(0, ofGetHeight()-sh, sw, sh);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bCaptureBg = true;
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
