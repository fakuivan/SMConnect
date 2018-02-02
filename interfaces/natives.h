
#ifndef _INCLUDE_SMCONNECT_INTERFACES_NATIVES_H_
#define _INCLUDE_SMCONNECT_INTERFACES_NATIVES_H_

namespace SMConnect { namespace Pub { namespace Natives {
	typedef cell_t(*FAKE_NATIVE_FUNC)(SourcePawn::IPluginContext*, const cell_t*, void*);
	
	/**
	* @brief Interface to a native router, can be used to dynamically create/handle natives.
	*/
	class INativeRouter {
	public:
		/**
		 * @brief Deallocates all memory used by the wrapper function and this object.
		 * Note that calling the deallocated wrapper can cause a segmentation fault. 
		 */
		virtual ~INativeRouter() { };

		/**
		 * @brief Returns the address of the ``SPVM_NATIVE_FUNC`` wrapper.
		 *
		 * @return				A pointer to the ``SPVM_NATIVE_FUNC`` wrapper.
		 */
		virtual SPVM_NATIVE_FUNC* GetWrapper() const =0;

		/**
		 * @brief Calls the assigned ``FAKE_NATIVE_FUNC``, passing ``pData`` to it.
		 *
		 * @param pContext		First parameter passed to ``FAKE_NATIVE_FUNC``.
		 * @param pParameters	Second parameter passed to ``FAKE_NATIVE_FUNC``.
		 * @return				The return from ``FAKE_NATIVE_FUNC``.
		 */
		virtual cell_t operator()(SourcePawn::IPluginContext* pContext, const cell_t* pParameters) const =0;
	};
} } }

#endif //_INCLUDE_SMCONNECT_INTERFACES_NATIVES_H_
