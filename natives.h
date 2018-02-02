
#ifndef _INCLUDE_SMCONNECT_NATIVES_H_
#define _INCLUDE_SMCONNECT_NATIVES_H_

#include "smsdk_ext.h"
#include "interfaces/natives.h"
#include <callback.h>

namespace SMConnect { namespace Natives
{
	class NativeRouter : public SMConnect::Pub::Natives::INativeRouter
	{
	public:
		NativeRouter(SMConnect::Pub::Natives::FAKE_NATIVE_FUNC* pYourCallback, void* pData);
		~NativeRouter();
		cell_t operator()(SourcePawn::IPluginContext* pContext, const cell_t* pParameters) const;
		SPVM_NATIVE_FUNC* GetWrapper() const;
	private:
		void MakeWrapper();
		void DeallocateWrapper();
		callback_t m_Wrapper;
		struct {
			SMConnect::Pub::Natives::FAKE_NATIVE_FUNC* m_pCallback;
			void* m_pData;
		} m_WrapperData;
		static void Router(void* pData, va_alist argumentList);
	};
} }

#endif //_INCLUDE_SMCONNECT_NATIVES_H_
