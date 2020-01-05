#pragma once


#ifdef _MSC_VER
#if _MSC_VER<1900L

#endif // _MSC_VER<1900L
#define CM_MSVC_COMPILE
#define CM_CPP_VERSION(VERSION) _MSC_VER>=1900

#define STD ::std:: 
#ifdef _HAS_EXCEPTIONS
#define CM_HAS_EXCEPTION

#endif

#endif

#ifdef __GNUC__
#define CM_GCC_COMPILE
#define CM_CPP_VERSION(VERSION) _MSC_VER>=1900

#define STD ::std::
#ifdef _HAS_EXCEPTIONS
#define CM_HAS_EXCEPTION
#define CM_BASE_EXCEPTION STD exception
#endif

#endif // __GNUC__




//#ifdef CM_CPP_VERSION(17)
//
//#define CONSTEXPR constexpr
//
//#define INLINE_VARIABLE inline
//
//#define CONSTEXPRIF constexpr
//
//#define CM_NODISCARD 
//
//#endif 
#ifdef CM_CPP_VERSION(14)

#define INLINE_VARIABLE inline

#define CONSTEXPRIF constexpr

#define CM_NODISCARD [[nodiscard]]

#endif  // _CM_CPP_VERSION(17)

#define CM_NOEXCEPT noexcept

#define CM_NOEX_TEST(EXPR) noexcept(EXPR)

#define CM_NO_COPY(CLASS)       \
  CLASS(const CLASS &) = delete; \
  CLASS &operator=(const CLASS &) = delete;

#define CM_INTERFACE(NAME)    \
  virtual ~NAME() noexcept {} \
  NAME() noexcept {}

//#define PURE=0

#define BEGIN_CM_NAMESPACE namespace CM {
#define END_CM_NAMESPACE }
#define Log(X) qDebug().noquote() << (X) << '\n'