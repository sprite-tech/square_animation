#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    float startX[10];
    float startY[10];
    float endX[10];
    float endY[10];
    
    float line01X;
    float line01Y;
    float line02X;
    float line02Y;
    
    float tri01PX;
    float tri01PY;
    float tri02PX;
    float tri02PY;
    float tri11PX;
    float tri11PY;
    float tri12PX;
    float tri12PY;
    
    float speed;
    float speed_size;
    float speed_lineX;
    float speed_lineY;
    float line_moveX;
    float line_moveY;
    float tri_speed01PX;
    float tri_speed01PY;
    
    bool animation;
};
