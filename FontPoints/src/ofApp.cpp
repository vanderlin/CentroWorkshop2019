#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
//    bool load(const std::filesystem::path& filename,
//              int fontsize,
//              bool _bAntiAliased=true,
//              bool _bFullCharacterSet=true,
//              bool makeContours=false,
//              float simplifyAmt=0.3f,
//              int dpi=0);
    font.load("Sentinel-Black.otf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto &outline : fontOutlines) {
        for(auto &pnt : outline) {
            pnt.x += ofRandom(-.2, .2);
            pnt.y += ofRandom(-.2, .2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for(auto &outline : fontOutlines) {
        ofSetColor(255);
        glLineWidth(4);
        outline.draw();
        glLineWidth(1);
    }
    
    
    ofDrawBitmapStringHighlight("press space to make font\nclick to clear\n"+word, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if ((key == OF_KEY_DEL || key == 8) && word.size()) {
        word.erase(word.end()-1);
    }
    else {
        char c = key;
        
        word += c;
        
        cout << word << endl;
    }
    
    
    if (key == ' ') {
        
        fontOutlines.clear();
        
        vector<ofPath> paths = font.getStringAsPoints(word);
        auto bounds = font.getStringBoundingBox(word, 0, 0);
        
        for(auto &path : paths) {
            
            // this will let us get outlines
            path.setPolyWindingMode(OF_POLY_WINDING_ODD);
            
            auto outlines = path.getOutline();
            
            if (outlines.size()) {
                
                auto outline = outlines[0];
                
                // move the fonts to middle of screen
                for(auto &pnt : outline) {
                    pnt.y += ofGetHeight() * 0.5;
                    pnt.x += (ofGetWidth() - bounds.width) * 0.5;
                }
                
                fontOutlines.push_back(outline);
            }
            
        }
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
    fontOutlines.clear();
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
