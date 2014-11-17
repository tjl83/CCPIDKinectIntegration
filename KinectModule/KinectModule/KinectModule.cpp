#include "KinectModule.h"


KinectModule::KinectModule(KinectInterface *k)
{
	kinect = k;
	int foo = kinect->init();
	if (FAILED(foo)){

	}
}


KinectModule::~KinectModule()
{
}

void KinectModule::aquireData()
{
	while (kinect->hasNextFrame())
	{
		if (kinect->getUsers().empty()){
			continue;
		}

		bool tracked = false;

		for (NUI_USER_INFO user : kinect->getUsers())
		{
			if (trackedUser.getID() == user.SkeletonTrackingId){
				trackedUser.updateHands(user);
				tracked = true;
				break;
			}
		}
		if (!tracked){
			trackedUser = TrackedUser(kinect->getUsers().front());
		}

		//Slot
	}
}
