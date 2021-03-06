/*
 *  pjControl.h
 *
 *  Created by Noah Shibley on 8/9/10.
 *  Updated by Martial GALLORINI on 19/03/2015
 *
	Video projector control class.
 *
 *
 */

#ifndef OFXPJCONTROL_H
#define OFXPJCONTROL_H

#include "ofxNetwork.h"
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/StreamCopier.h"

using Poco::DigestEngine;
using Poco::MD5Engine;
using Poco::DigestOutputStream;
using Poco::StreamCopier;


const int NEC_PORT = 7142; //NEC projector port
const int PJLINK_PORT = 4352; //PJLink projector protocol port
const int CHRISTIE_PORT = 3002; //CHRISTIE projector protocol port
const int SANYO_PORT = 100; //SANYO projector protocol port
const int PJDESIGN_PORT = 1025; //Projectino Design projector protocol port

const int PJLINK_MODE = 0;
const int NEC_MODE = 1;
const int CHRISTIE_MODE = 2;
const int SANYO_MODE = 3;
const int PJDESIGN_MODE = 4;


class ofxPJControl
{
public:
	ofxPJControl();
	~ofxPJControl();

	//methods
	void On(); //command to turn the projector off
	void Off(); //command to turn the projector on
    string attemptConnection();
    bool getIsTCPClientConnected();
    bool pingIPAddress(string _IP);
	void sendPJLinkCommand(string command, bool sendOn); //send any PJLink command to the projector
	void setup(string IP_add="192.168.0.100",int port = 4352, int protocol=PJLINK_MODE, string password=""); //default
	void setProjectorType(int protocol); //NEC_MODE or PJLINK_MODE
	void setProjectorIP(string IP_add); //the network IP of the projector
    void setProjectorPassword(string passwd); //password for PJLink authentication
	bool getProjectorPowerStatus(); //return whether projector is on (true) or off (false)
	void setProjectorPort(int port); //the network port of the projector
	void sendCommand(string command, bool sendOn); //send any string command to the projector without password authentication
    
    void closeConnection(); //close connection after messages are sent

private:

	void nec_On();
	void nec_Off();
	void pjLink_On();
	void pjLink_Off();
	void sanyo_On();
	void sanyo_Off();
	void christie_On();
	void christie_Off();
    void pjDesign_On();
    void pjDesign_Off();

	ofxTCPClient pjClient;

	string IPAddress;
	int pjPort;
    string password;

	bool projStatus;
	string msgTx;
	string msgRx;
	bool connected;
	int commMode;

};

#endif

