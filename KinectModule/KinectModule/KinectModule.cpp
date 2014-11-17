

#include "KinectModule.h"


KinectModule::KinectModule(KinectInterface *k)
{
	kinect = k;
	int foo = kinect->init();
	if (FAILED(foo)){
		//Not sure if should throw an error here (i.e error handling required)
	}
}


KinectModule::~KinectModule()
{
}

/**
 * This function begins the loop of acquiring data. It checks if there are
 * any more frames to process and gets the first user that the sensor sees
 * and tracks it. If that user moves away then the next available user will
 * be tracked. Once each frame is processed a function will be signaled to
 * process the user data that will be passed through.
 */
void KinectModule::acquireData()
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

		/* Here is where the interaction function will be signaled and the user data will be pass through
		 * Meaning the signal here will take object "trackedUser" as a parameter.
		 * The signaled function (i.e the slot) will take the object "trackedUser" and 
		 */

	}
}
