#include <iostream>

#include "KinectInterface.h"
#include "KinectModule.h"

using namespace std;
int main(){
	KinectInterface *k = new KinectInterface();
	KinectModule *foo = new KinectModule(k);

}