#include <Windows.h>

#include <NuiApi.h>
#include <KinectInteraction.h>

#ifndef MYINTERACTIONCLIENT_H
#define MYINTERACTIONCLIENT_H

class MyInteractionClient:public INuiInteractionClient{
public:
	MyInteractionClient();
	~MyInteractionClient();

	STDMETHODIMP_(ULONG)    AddRef();
	STDMETHODIMP_(ULONG)    Release();
	STDMETHODIMP            QueryInterface(REFIID riid, void **ppv);

	STDMETHOD(GetInteractionInfoAtLocation)(THIS_ DWORD skeletonTrackingId, NUI_HAND_TYPE handType, FLOAT x, FLOAT y, _Out_ NUI_INTERACTION_INFO *pInteractionInfo);
};

#endif