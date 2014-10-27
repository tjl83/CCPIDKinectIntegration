#include <vector>
#include <Windows.h>

#include <NuiApi.h>
#include <KinectInteraction.h>

#include "MyInteractionClient.h"

#ifndef KINECTINTERFACE_H
#define KINECTINTERFACE_H

class KinectInterface
{
public:
	KinectInterface();

	int init();
	int close();
	bool hasNextFrame();
	std::vector<NUI_USER_INFO> getUsers();
	enum errStatus{ OKAY = 0, FAIL_SENSOR_NOT_FOUND = -1, FAIL_NUI_INIT = -2, FAIL_DEPTH_STREAM = -4, FAIL_SKELE_STREAM = -8,  FAIL_INTERACTION_STREAM = -9};

private:
	INuiSensor				*m_pNuiSensor;
	INuiInteractionStream	*m_nuiIStream;
	MyInteractionClient		 m_nuiIClient;
	//--------------------------------------------------------------------
	HANDLE m_pDepthStreamHandle;

	HANDLE m_hNextDepthFrameEvent;
	HANDLE m_hNextSkeletonEvent;
	HANDLE m_hNextInteractionEvent;
	HANDLE m_hEvNuiProcessStop;
	HANDLE hEvents[4];
	//--------------------------------------------------------------------
	std::vector<NUI_USER_INFO> users;

	int processDepth(HANDLE h);
	int processSkeleton();
	int processInteraction();

	HRESULT ConnectKinect();
};

#endif