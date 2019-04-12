#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(232, 180, 150);

    // intialize vector with array
    vector <string> words = {"hello", "of", "love"};
    
    // get the length
    int len = words.size();
    
    // remove the 2nd word
    words.erase(words.begin() + 1);
    
    // loop the words and print them out
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    // clear the array
    words.clear();
    
    // add 4 new words
    words.push_back("hello");
    words.push_back("world");
    words.push_back("love");
    words.push_back("openFrameworks");
    
    // print
    cout << "new words: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // reverse the array
    std::reverse(words.begin(), words.end());
    
    cout << "reversed: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // randomize the array
    std::random_shuffle(words.begin(), words.end());
    
    cout << "randomized: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // add two word and sorted alphabetally
    words.push_back("apple");
    words.push_back("zebra");
    std::sort(words.begin(), words.end());
    cout << "sorted: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // sort on word length using the of vector sort and a lambda
    // think of a lambda like a closure in javascript.
    ofSort(words, [](string &a, string &b) -> bool {
        return a.length() > b.length();
    });
    
    cout << "sorted by length: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // insert a word in the middle
    int middleIndex = words.size() / 2;
    words.insert(words.begin() + middleIndex, "ice cream");
    
    cout << "inserted in middle: ";
    for(int i=0; i<words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    
    
    // there is a ton more but that is good for now
    // read more about vectors here:
    // http://www.cplusplus.com/reference/vector/vector/
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
