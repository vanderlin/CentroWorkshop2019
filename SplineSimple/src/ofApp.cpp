#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(232, 180, 150);
    bClosePoints = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
glm::vec2 ofApp::getPointAtPct(float pct, ofPolyline &points, bool bClose) {
    
    // the total control points (points array)
    int num = points.size()-1;
    
    // get the float index based on percent
    float indexf = (float)num * pct;
    float indexI = floor(indexf);

    // the differance from the index float and the rounded index
    float f = indexf - indexI;
    
    glm::vec2 p0, p1, p2, p3;
    
    if (!bClose) {
        p0 = points[ ofClamp( indexI-1, 0, num) ];
        p1 = points[ indexI ];
        p2 = points[ ofClamp( indexI+1, 0, num) ];
        p3 = points[ ofClamp( indexI+2, 0, num) ];
    }
    else {
        
        // we are wrapping index using the modulus operator
        int i = (int)indexI;
        
        p0 = points[i % num];
        p1 = points[(i+1) % num];
        p2 = points[(i+2) % num];
        p3 = points[(i+3) % num];
    }
    
    // this where we can try other spline interpolations see SplineUtils.h for
    auto pt = SplineUtils::cubic(p0, p1, p2, p3, f);
   
    // we can also use ofCurvePoint
    // auto pt = ofCurvePoint(p0, p1, p2, p3, f);
  
    return pt;
}
//--------------------------------------------------------------
void ofApp::draw(){

    // draw the polyline
    ofSetColor(0, 100);
    points.draw();
    for(auto &pnt : points) {
        ofDrawCircle(pnt, 3);
    }
    
    // we need at least one point to start
    if (points.size() > 1) {
        
        // create a temporary polyline for all the points
        ofPolyline temp(points);
        
        // if we want to close these points we add the first point to the front
        if (bClosePoints) {
            temp.addVertex(points[0]);
        }
        
        // polyline to hold all of our points
        ofPolyline splinePoints;
        
        // we now subdivide the polyline points so that we can
        // interpolate the spline. We multiply the total amount
        // of points by a subdivide amount. x * points.size()
        int n = 10 * temp.size();
        
        float step = 1.0 / (n-1);
        for(int i=0; i<n; i++) {
            
            // normalize i so that it is a percent
            float pct = ofMap(i, 0, n-1, 0.0, 1.0);

            // get the curve point based on the percentage
            // from the total subdivide amount.
            auto curvePoint = getPointAtPct(pct, temp, bClosePoints);
            
            // add point to spline points
            splinePoints.addVertex(curvePoint.x, curvePoint.y);
            
        }
        
        ofSetColor(255);
        splinePoints.draw();
        for(auto &pnt : splinePoints) {
            
            ofDrawCircle(pnt, 3);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') points.clear();
    if (key == ' ') bClosePoints = !bClosePoints;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    // try this
    // points.addVertex(x, y);
    
    // this will make a snake!
    // points = points.getResampledByCount(30);
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
