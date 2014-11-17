#ifndef KINECTMODULE_KINECTMODULE_H
#define KINECTMODULE_KINECTMODULE_H

#include "KinectInterface.h"
#include "TrackedUser.h"

class KinectModule
{
public:
	KinectModule(KinectInterface *k);
	~KinectModule();

	void acquireData();
private:
	KinectInterface *kinect;
	TrackedUser trackedUser;
};

#endif // !KINECTMODULE_KINECTMODULE_H
