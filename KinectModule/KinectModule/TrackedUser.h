#include <Windows.h>

#include <NuiApi.h>
#include <KinectInteraction.h>

#include "Coordinate.h"

#ifndef KINECTMODULE_TRACKEDUSER_H
#define KINECTMODULE_TRACKEDUSER_H

class TrackedUser
{
public:
	TrackedUser();
	TrackedUser(NUI_USER_INFO userInfo);
	~TrackedUser();

	void updateHands(NUI_USER_INFO userInfo);

	int getID();
	bool getGripped(NUI_HAND_TYPE hand);
	Coordinate getCurrPos(NUI_HAND_TYPE hand);
	Coordinate getPrevPos(NUI_HAND_TYPE hand);

private:
	int ID;

	bool handEventLeft;
	bool handEventRight;

	Coordinate prevLeft;
	Coordinate prevRight;

	Coordinate currLeft;
	Coordinate currRight;
};

#endif // !KINECTMODULE_TRACKEDUSER_H