#define EXPORTBUILD

#include "vrpn_Connection.h"
#include "vrpn_Tracker.h"
#include "conio.h"

#include "V2U.h"

vrpn_Connection* connection;
vrpn_Tracker_Remote* tracker;
bool running = false;
float posx;
float posy;
float posz;
float quatx;
float quaty;
float quatz;
float quatw;

void VRPN_CALLBACK handle_pos(void*,const vrpn_TRACKERCB t);
void _DLLExport setUp(char*,int);
void _DLLExport vrpnRun(int);
void _DLLExport vrpnStatus();
float _DLLExport getPosX();
float _DLLExport getPosY();
float _DLLExport getPosZ();
float _DLLExport getQuatX();
float _DLLExport getQuatY();
float _DLLExport getQuatZ();
float _DLLExport getQuatW();

void VRPN_CALLBACK handle_pos(void*,const vrpn_TRACKERCB t){
	posx = t.pos[0];
	posy = t.pos[1];
	posz = t.pos[2];
	quatx = t.quat[0];
	quaty = t.quat[1];
	quatz = t.quat[2];
	quatw = t.quat[3];
}

float _DLLExport getPosX(){return posx;}
float _DLLExport getPosY(){return posy;}
float _DLLExport getPosZ(){return posz;}
float _DLLExport getQuatX(){return quatx;}
float _DLLExport getQuatY(){return quaty;}
float _DLLExport getQuatZ(){return quatz;}
float _DLLExport getQuatW(){return quatw;}

void _DLLExport setUp(char* trackerName,int port){
	char connectionName[128];
	sprintf(connectionName,"localhost:%d",port);
	connection = vrpn_get_connection_by_name(connectionName);

	tracker = new vrpn_Tracker_Remote(trackerName,connection);
	tracker->register_change_handler(NULL,handle_pos);
}

void _DLLExport vrpnRun(int sleepTime){
	if(running == true){
		tracker->mainloop();
		connection->mainloop();
		Sleep(sleepTime);
	}
}

void _DLLExport vrpnStatus(){
	running = !running;
}