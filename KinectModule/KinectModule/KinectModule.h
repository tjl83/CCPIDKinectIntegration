#ifndef KINECTMODULE_KINECTMODULE_H
#define KINECTMODULE_KINECTMODULE_H

#include "KinectInterface.h"
#include "TrackedUser.h"

class KinectModule
{
public:
	KinectModule(KinectInterface *k);
	~KinectModule();

	void aquireData();
private:
	KinectInterface *kinect;
	TrackedUser trackedUser;
};

#endif // !KINECTMODULE_KINECTMODULE_H
