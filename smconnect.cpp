
#include "smconnect.h"
#include "natives.h"

using namespace SMConnect;

Pub::Natives::INativeRouter* CSMConnect::MakeNativeRouter(Pub::Natives::FAKE_NATIVE_FUNC * pYourCallback, void * pData)
{
	return new Natives::NativeRouter(pYourCallback, pData);
}
