
#ifndef _INCLUDE_SMCONNECT_H_
#define _INCLUDE_SMCONNECT_H_

#include "smsdk_ext.h"
#include "interfaces/smconnect.h"

namespace SMConnect {
	class CSMConnect : public Pub::ISMConnect
	{
		Pub::Natives::INativeRouter* MakeNativeRouter(Pub::Natives::FAKE_NATIVE_FUNC* pYourCallback, void* pData);
	};
}

#endif //_INCLUDE_SMCONNECT_H_
