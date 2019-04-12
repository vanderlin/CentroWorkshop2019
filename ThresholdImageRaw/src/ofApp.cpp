#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(232, 180, 150);
    ofSetFrameRate(60);
    video.load("two-finders-drawing-480.mov");
    video.play();
    
    // we need to allocate the image to be the
    // same size as the video but only one channel
    thresholdImage.allocate(video.getWidth(), video.getHeight(), OF_IMAGE_GRAYSCALE);
    
    threshold = 222;
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
    
    if (video.isFrameNew()) {
        
        int vw = video.getWidth();
        int vh = video.getHeight();
        for(int i=0; i<vw; i++) {
            for(int j=0; j<vh; j++) {
                
                
                int index = i + j * vw;
                
                auto r = video.getPixels().getData()[index * 3 + 0];
                auto g = video.getPixels().getData()[index * 3 + 1];
                auto b = video.getPixels().getData()[index * 3 + 2];
                
                auto gray = (r + g + b) / 3;
                
                if (gray > threshold) {
                    gray = 0;
                }
                else {
                    gray = 255;
                }
                
                thresholdImage.getPixels().getData()[index] = gray;
            }
        }

        thresholdImage.update();

    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // draw the thresholded image
    ofSetColor(255);
    video.draw(0, 0);
    thresholdImage.draw(video.getWidth(), 0);
    
    // draw the fps & threshold
    ofDrawBitmapStringHighlight("fps "+ofToString(ofGetFrameRate(), 1) + "\nThreshold "+ofToString(threshold), 20, ofGetHeight()-30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP && threshold < 255) threshold ++;
    if (key == OF_KEY_DOWN && threshold > 0) threshold --;
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
