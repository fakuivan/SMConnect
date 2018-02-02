
#ifndef _INCLUDE_SMCONNECT_FILE_H_
#define _INCLUDE_SMCONNECT_FILE_H_

#include <IShareSys.h>

#define SMINTERFACE_SMCONNECT_NAME		"ISMConnect"
#define SMINTERFACE_SMCONNECT_VERSION	0

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
	};
} }


#endif //_INCLUDE_SMCONNECT_FILE_H_
