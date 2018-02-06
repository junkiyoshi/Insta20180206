#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(32);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 10;
	float deg = 0;

	while (radius < ofGetWidth()) {

		float noise_value = ofNoise(deg * 0.005 - ofGetFrameNum() * 0.01) + 0.5;
		ofPoint point_1(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		ofPoint point_2(radius * noise_value * cos(deg * DEG_TO_RAD), radius * noise_value * sin(deg * DEG_TO_RAD));

		ofColor line_color;
		line_color.setHsb((int)deg % 255, 200, 200);
		ofSetColor(line_color);

		ofDrawLine(point_1, point_2);

		radius += 0.1;
		deg += 1.5;
	}

}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}