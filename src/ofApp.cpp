#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(60);
    ofBackground(0, 0, 0);
    
    for (int i = 0; i < 6; i ++) {
        startX[i] = 0 + (i*3);
        startY[i] = 0 + (i*3);
        endX[i] = 0 - (i*6);
        endY[i] = 0 - (i*6);
    }
    
    speed = 1.5;
    speed_size = 3;
    speed_lineX = 2;
    speed_lineY = 2;
    
    line01X = 300;
    line01Y = -300;
    line02X = 300;
    line02Y = -300;
    
    tri01PX = 300;
    tri01PY = -300;
    tri02PX = 300;
    tri02PY = 300;
    
    tri11PX = -300;
    tri11PY = 300;
    tri12PX = -300;
    tri12PY = -300;
    
    line_moveX = 3;
    line_moveY = 3;
    
    tri_speed01PX = 3;
    tri_speed01PY = 3;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (animation == true){
        for (int i = 0; i < 3; i ++) {
            startX[i] = startX[i] - speed;
            startY[i] = startY[i] - speed;
            endX[i] = endX[i] + speed_size;
            endY[i] = endY[i] + speed_size;
        
            if(startX[i] < -300){
                speed = 0;
            }
        
            if(startY[i] < -300){
                speed = 0;
            }
        
            if(endX[i] > 600){
                speed_size = 0;
            }
        
            if(endY[i] > 600){
                speed_size = 0;
            }
     
            if (ofGetElapsedTimef() > 6.5) {
                line02X = line02X - speed_lineX;
                if (line02X < -298) {
                    speed_lineX = 0;
                }
            
                line02Y = line02Y + speed_lineY;
                if (line02Y > 298) {
                    speed_lineY = 0;
                }
            
            }
        
            if (ofGetElapsedTimef() > 9) {
                line01Y = line01Y + line_moveY;
                line02Y = line02Y - line_moveY;
                tri01PY = tri01PY + tri_speed01PY;
                tri11PY = tri11PY - tri_speed01PY;
                if (line01Y > 298) {
                    line_moveY = 0;
                    tri_speed01PY = 0;
                
                    line01X = line01X - line_moveX;
                    line02X = line02X + line_moveX;
                    tri02PX = tri02PX - tri_speed01PX;
                    tri12PX = tri12PX + tri_speed01PX;
                    if (line01X < -298) {
                        line_moveX = 0;
                        tri_speed01PX = 0;
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(255, 255, 255);
    ofDrawRectangle(startX[0], startY[0], endX[0], endY[0]);
    
    ofSetColor(0, 0, 0);
    ofDrawRectangle(startX[1], startY[1], endX[1], endY[1]);
    
    if (ofGetElapsedTimef() > 6.5) {
        ofSetColor(255, 255, 255);
        ofSetLineWidth(5);
        ofDrawLine(line01X, line01Y, line02X, line02Y);
    }
    
    if (ofGetElapsedTimef() > 9) {
        ofSetColor(255, 255, 255);
        ofSetLineWidth(5);
        ofDrawLine(line01X, line01Y, line02X, line02Y);
        
        ofSetColor(255, 140, 161);
        ofDrawTriangle(300, -300, 0, 0, tri01PX, tri01PY);
        
        ofSetColor(153, 255, 51);
        ofDrawTriangle(-300, 300, 0, 0, tri11PX, tri11PY);
        
        ofSetColor(255, 255, 255);
        ofSetLineWidth(5);
        ofDrawLine(line01X, line01Y, line02X, line02Y);
        
        ofSetColor(255, 102, 102);
        ofDrawTriangle(300, 300, 0, 0, tri02PX, tri02PY);
        
        ofSetColor(102, 255, 0);
        ofDrawTriangle(-300, -300, 0, 0, tri12PX, tri12PY);
    }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's'){
        animation = true;
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
