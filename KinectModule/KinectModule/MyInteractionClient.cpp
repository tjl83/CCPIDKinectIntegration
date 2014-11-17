#include "MyInteractionClient.h"


MyInteractionClient::MyInteractionClient(){}
MyInteractionClient::~MyInteractionClient(){}

STDMETHODIMP_(ULONG)    MyInteractionClient::AddRef()                                    { return 2; }
STDMETHODIMP_(ULONG)    MyInteractionClient::Release()                                   { return 1; }
STDMETHODIMP            MyInteractionClient::QueryInterface(REFIID riid, void **ppv)     { return S_OK; }

HRESULT					MyInteractionClient::GetInteractionInfoAtLocation(THIS_ DWORD skeletonTrackingId, NUI_HAND_TYPE handType, FLOAT x, FLOAT y, _Out_ NUI_INTERACTION_INFO *pInteractionInfo)
{
	if (pInteractionInfo)
	{
		pInteractionInfo->PressTargetControlId = 0;
		pInteractionInfo->PressAttractionPointX = 0.f;
		pInteractionInfo->PressAttractionPointY = 0.f;
		pInteractionInfo->IsPressTarget = false;
		pInteractionInfo->IsGripTarget = true;
		return S_OK;
	}
	return E_POINTER;
}