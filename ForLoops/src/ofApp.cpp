#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(232, 180, 150);
    
    
    // add 10 numbers to the vector
    for(int i=0; i<10; i++) {
        numbers.push_back(ofRandomf());
    }
    
    int num = 10;
    
    // a normal forward loop ++
    cout << "forward loop" << endl;
    for(int i=0; i<num; i++) {
        cout << i << endl;
    }
    
    // a reverse loop --
    cout << "reverse loop" << endl;
    for(int i=num-1; i>=0; i--) {
        cout << i << endl;
    }
    
    // step by (x) loop
    cout << "step by x loop" << endl;
    for(int i=0; i<num; i+=2) {
        cout << i << endl;
    }
    
    // a float loop (0.0 - 1.0)
    cout << "float loop 0.0 - 1.0" << endl;
    for(float f=0.0; f<=1.001; f+=0.1) {
        int i = f * num;
        cout << f << " -- " << i << endl;
    }
    
    // a auto loop for vectors (iterators)
    cout << "auto for loop" << endl;
    vector <float> values = {0.0, 2.0, 4.0, 6.0};
    for(auto &n : values) {
        cout << n << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // we have a vector of random numbers when we click
    // we get a new one we are going to loop through them in many ways
    
    
    // 01
    // a very simple for loop
    ofDrawBitmapStringHighlight("simple loop ++", 10, 20);
    for(int i=0; i<numbers.size(); i++) {
        ofDrawBitmapStringHighlight(ofToString(i) + " | " + ofToString(numbers[i]), 10, 45 + i * 22);
    }
    
    // 02
    // we can loop backwards in the loop
    ofDrawBitmapStringHighlight("backwards --", 10+200, 20);
    for(int i=numbers.size()-1; i>=0; i--) {
        
        // reverse i since we are using that
        // to move in y direction
        int revi = (numbers.size()-1) - i;
        
        ofDrawBitmapStringHighlight(ofToString(i) + " | " + ofToString(numbers[i]), 200+10, 45 + revi * 22);
    }
    
    // 03
    // step by 2
    ofDrawBitmapStringHighlight("step x 2", 10+400, 20);
    for(int i=0; i<numbers.size(); i+=2) {
        ofDrawBitmapStringHighlight(ofToString(i) + " | " + ofToString(numbers[i]), 400+10, 45 + i * 22);
    }
    
    
    // 04
    // use a float
    ofDrawBitmapStringHighlight("float loop 0.0 - 1.0", 10+600, 20);
    float y = 0;
    for(float f=0; f<=1.0; f+=0.05) {
        
        int index = f * (numbers.size()-1);
        
        ofDrawBitmapStringHighlight(ofToString(f) + " | " + ofToString(numbers[index]), 600+10, 45 + y);
        
        y += 22;
    }
    
    // 05
    // using a auto loop
    ofDrawBitmapStringHighlight("auto loop", 10+800, 20);
    y = 0;
    for(auto & num : numbers) {
        ofDrawBitmapStringHighlight(ofToString(num), 800+10, 45 + y);
        y += 22;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'c') {
        numbers.clear();
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
    
    // add a random float
    numbers.push_back(ofRandomf());
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
