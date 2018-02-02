
#include "natives.h"

using namespace SMConnect::Natives;

NativeRouter::NativeRouter(SMConnect::Pub::Natives::FAKE_NATIVE_FUNC* pYourCallback, void* pData)
{
	m_WrapperData.m_pCallback = pYourCallback;
	m_WrapperData.m_pData = pData;
	MakeWrapper();
}

NativeRouter::~NativeRouter()
{
	DeallocateWrapper();
}

cell_t NativeRouter::operator()(SourcePawn::IPluginContext* pContext, const cell_t* pParameters) const
{
	return (*m_WrapperData.m_pCallback)(pContext, pParameters, m_WrapperData.m_pData);
}

SPVM_NATIVE_FUNC* NativeRouter::GetWrapper() const
{
	return (SPVM_NATIVE_FUNC*)&m_Wrapper;
}

void NativeRouter::MakeWrapper()
{
	m_Wrapper = alloc_callback(NativeRouter::Router, (void*)this);
}

void NativeRouter::DeallocateWrapper()
{
	free_callback(m_Wrapper);
}

void NativeRouter::Router(void* pData, va_alist argumentList)
{
	const NativeRouter* pThis = (NativeRouter*)pData;
	SourcePawn::IPluginContext* pContext;
	const cell_t* pParameters;
	cell_t result;

	va_start_int(argumentList);
	pContext = va_arg_ptr(argumentList, SourcePawn::IPluginContext*);
	pParameters = va_arg_ptr(argumentList, const cell_t*);
	result = (*pThis)(pContext, pParameters);
	va_return_int(argumentList, result);
}
