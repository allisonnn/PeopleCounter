#pragma once

#include "kinect.h"
#include "ofxOpenCv.h"

struct blob_data {
	int bid;
	float x;
	float y;
	float w;
	float h;
};

class Tracker {
public:
	void setup(Kinect* kinectRef);
	void update();
	void debugDraw();
	
	Kinect * kinect;
	
	ofxCvGrayscaleImage grayImage;
	ofxCvGrayscaleImage grayImageThreshold;
	
	ofxCvContourFinder contourFinder;
	
	int threshold;
	int movement_threshold;
	int blur;
	
	vector<blob_data> blobData;

	int next_id;

private:
	vector<blob_data> oldBlobs;
};
