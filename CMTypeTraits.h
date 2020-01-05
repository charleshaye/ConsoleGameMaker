#pragma once
#include <type_traits>
#include <utility>
#include "CMDefines.h"
BEGIN_CM_NAMESPACE

template <class _Base, typename _Derived>
struct is_derived
    : public STD bool_constant<STD is_convertible_v<
          STD add_pointer_t<_Derived>, STD add_pointer_t<_Base>>> {};

template <class _Base, typename _Derived>
INLINE_VARIABLE constexpr bool is_derived_v =
    is_derived<_Base, _Derived>::value;

template <class _Base, typename _Derived>
using is_derived_t = STD enable_if_t<is_derived_v<_Base, _Derived>, _Derived>;

END_CM_NAMESPACE