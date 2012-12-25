#pragma once

#include "ofxOsc.h"


/**
  * OSC communication with Resolume, using openFrameworks.
  */
class ResolumeOSC {
private:
	ofxOscSender sender;
//	ofxOscReceiver receiver;

	char intToChar(int i);
//	int charToInt(char c);

	void send(string address, int value);
	void send(string address, float value);

public:
	ResolumeOSC(string host = "127.0.0.1", unsigned port = 7000);
	~ResolumeOSC();
	
	// Layer parameters
	void setLayerTransitionTime(float value);
	void setLayerMixerOption1(int layerID, int value);
	void setLayerOpacity(int layerID, float value);

	// Layer actions
	void clearLayer(int layerID);

	// Clip parameters
	void setClipAutoPilot(int layerID, int clipID, int value);
	void setClipPlayMode(int layerID, int clipID, int value);

	// Clip actions
	void playClip(int layerID, int clipID);
};