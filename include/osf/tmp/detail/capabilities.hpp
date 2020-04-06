#ifndef OSF_TMP_CAPABILITIES_HPP_INCLUDED
#define OSF_TMP_CAPABILITIES_HPP_INCLUDED

#if __clang_major__ == 3
#define OSF_TMP_CLANG_ARITY_BUG
#endif
#if __cplusplus >= 201103L
#if __cplusplus >= 201402L
#define OSF_TMP_CPP14
#define OSF_TMP_COMPLEX_CONSTEXPR constexpr
#else
#define OSF_TMP_COMPLEX_CONSTEXPR
#endif
#else
#if _MSC_VER >= 1900
#define OSF_TMP_CPP14
#define OSF_TMP_COMPLEX_CONSTEXPR constexpr
#elif _MSC_VER >= 1800

#else
#error "__cplusplus must be > 201103L (the value of C++11)"
#endif
#endif

#endif