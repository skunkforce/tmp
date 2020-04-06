#ifndef OSF_TMP_FUSION_REBIND_HPP_INCLUDED
#define OSF_TMP_FUSION_REBIND_HPP_INCLUDED

#include "capabilities.hpp"
namespace osf {
	namespace tmp {
#ifdef OSF_TMP_CPP14
		namespace fusion {
			// to make a metafunction fusion capable this traits must be specialized
			// with the rebound version of the metafunction to be used in fusion context
			template <typename T>
			struct rebind;
		} // namespace fusion
#endif
	} // namespace tmp
} // namespace osf

#endif