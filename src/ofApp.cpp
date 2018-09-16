#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  strangeMesh.setMode(OF_PRIMITIVE_POINTS);
  strangeMesh.enableColors();

  gui.setup();
  gui.add(Prandtl.setup("Prandtl", 10, 0, 20));
  gui.add(Rayleigh.setup("Rayleigh", 28, 0, 50));
  gui.add(b.setup("b", 2.666666, 2, 3));

  iterations = 500000;

  initialZoomFactor = 5.0;

  x = 1.0;
  y = 1.0;
  z = 1.0;
  bHide = true;

}

//--------------------------------------------------------------
void ofApp::update(){
  strangeMesh.clear();
  for(int i=0;i<iterations;i++){
    float dx = Prandtl*(y - x);
    float dy = Rayleigh*x - y - x*z;
    float dz = x*y - b*z;

    x += dx/100;
    y += dy/100;
    z += dz/100;

    ofVec3f Position3d(x*initialZoomFactor, y*initialZoomFactor, z*initialZoomFactor);

    strangeMesh.addVertex(Position3d);
    strangeMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 0.025));
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  cam.begin();
  strangeMesh.draw();
  cam.end();

  if(bHide){
    gui.draw();
  }

  string info;
  info += "FPS = " + ofToString(ofGetFrameRate(), 4);
  ofDrawBitmapString(info, 30, ofGetHeight()-30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'h'){
		bHide = !bHide;
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
