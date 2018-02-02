
#ifndef _INCLUDE_SMCONNECT_FILE_H_
#define _INCLUDE_SMCONNECT_FILE_H_

#include <IShareSys.h>
#include "natives.h"

#define SMINTERFACE_SMCONNECT_NAME		"ISMConnect"
#define SMINTERFACE_SMCONNECT_VERSION	1

namespace SMConnect { namespace Pub {
	class ISMConnect : public SourceMod::SMInterface {
	public:
		virtual const char *GetInterfaceName()
		{
			return SMINTERFACE_SMCONNECT_NAME;
		}
		virtual unsigned int GetInterfaceVersion()
		{
			return SMINTERFACE_SMCONNECT_VERSION;
		}

	public:
		/**
		 * @brief Constructs a "fake native" router.
		 *
		 * @param pYourCallback	Callback function to .
		 * @param pData			Arbitrary parameter passed as ``pData`` to ``pYourCallback``.
		 * @return				A new router.
		 */
		virtual Natives::INativeRouter* MakeNativeRouter(Natives::FAKE_NATIVE_FUNC* pYourCallback, void* pData) =0;
	};
} }


#endif //_INCLUDE_SMCONNECT_FILE_H_
