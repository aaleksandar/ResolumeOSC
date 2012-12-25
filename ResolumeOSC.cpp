#include "ResolumeOSC.h"

ResolumeOSC::ResolumeOSC(string host, unsigned port) {
	sender.setup(host, port);
}

ResolumeOSC::~ResolumeOSC() {
}

char ResolumeOSC::intToChar(int i) { return i + 48; }
//int ResolumeOSC::charToInt(char c) { return c - 48; }


// Sends OSC command with INT value
void ResolumeOSC::send(string address, int value) {
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addIntArg(value);
	sender.sendMessage(msg);
}

// Sends OSC command with FLOAT value
void ResolumeOSC::send(string address, float value) {
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addFloatArg(value);
	sender.sendMessage(msg);
}

void ResolumeOSC::playClip(int layerID, int clipID) {
	string address = "/layerX/clipX/connect";
	address[6] = intToChar(layerID);
	address[12] = intToChar(clipID);

	send(address, 1);
}

void ResolumeOSC::clearLayer(int layerID) {
	string address = "/layerX/clear";
	address[6] = intToChar(layerID);

	send(address, 1);
}

void ResolumeOSC::setLayerMixerOption1(int layerID, int value) {
	string address = "/layerX/video/mixeroption1";
	address[6] = intToChar(layerID);

	send(address, value);
}

void ResolumeOSC::setLayerOpacity(int layerID, float value) {
	string address = "/layerX/video/opacity/values";
	address[6] = intToChar(layerID);

	send(address, value);
}

void ResolumeOSC::setClipAutoPilot(int layerID, int clipID, int value) {
	string address = "/layerX/clipX/autopilot/action";
	address[6] = intToChar(layerID);
	address[12] = intToChar(clipID);

	send(address, value);
}


void ResolumeOSC::setClipPlayMode(int layerID, int clipID, int value) {
	string address = "/layerX/clipX/video/position/playmode";
	address[6] = intToChar(layerID);
	address[12] = intToChar(clipID);

	send(address, value);
}