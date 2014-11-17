#include "TrackedUser.h"

TrackedUser::TrackedUser(){}

TrackedUser::TrackedUser(NUI_USER_INFO userInfo){
	ID = userInfo.SkeletonTrackingId;
	updateHands(userInfo);
	handEventLeft = false;
	handEventRight = false;
}

TrackedUser::~TrackedUser(){}

void TrackedUser::updateHands(NUI_USER_INFO userInfo){
	for (NUI_HANDPOINTER_INFO hand : userInfo.HandPointerInfos){
		switch (hand.HandType){
		case NUI_HAND_TYPE_LEFT:
			if (hand.HandEventType == NUI_HAND_EVENT_TYPE_GRIP)
				handEventLeft = true;
			else if (hand.HandEventType == NUI_HAND_EVENT_TYPE_GRIPRELEASE)
				handEventLeft = false;

			prevLeft = currLeft;
			currLeft = Coordinate(hand.RawX, hand.RawY, hand.RawZ);
			break;
		case NUI_HAND_TYPE_RIGHT:
			if (hand.HandEventType == NUI_HAND_EVENT_TYPE_GRIP)
				handEventRight = true;
			else if (hand.HandEventType == NUI_HAND_EVENT_TYPE_GRIPRELEASE)
				handEventRight = false;

			prevRight = currRight;
			currRight = Coordinate(hand.RawX, hand.RawY, hand.RawZ);
			break;
		default:
			break;
		}
	}
}

int TrackedUser::getID(){
	return ID;
}

bool TrackedUser::getGripped(NUI_HAND_TYPE hand){
	switch (hand)
	{
	case NUI_HAND_TYPE_LEFT:
		return handEventLeft;
		break;
	case NUI_HAND_TYPE_RIGHT:
		return handEventRight;
		break;
	default:
		break;
	}
	return false;
}

Coordinate TrackedUser::getCurrPos(NUI_HAND_TYPE hand){
	switch (hand)
	{
	case NUI_HAND_TYPE_LEFT:
		return currLeft;
	case NUI_HAND_TYPE_RIGHT:
		return currRight;
	default:
		break;
	}
	return Coordinate();
}

Coordinate TrackedUser::getPrevPos(NUI_HAND_TYPE hand){
	switch (hand)
	{
	case NUI_HAND_TYPE_LEFT:
		return prevLeft;
	case NUI_HAND_TYPE_RIGHT:
		return prevRight;
	default:
		break;
	}
	return Coordinate();
}