
#include "CalDevDefs.h"
#ifndef CalDevLibH
#define CalDevLibH

#ifdef CALDEVLIBRARY_EXPORTS
#define CALDEVLIBRARY_API __declspec(dllexport)
#else
#define CALDEVLIBRARY_API
#endif

extern "C" CALDEVLIBRARY_API void __stdcall CalDev_init(const wchar_t * name);

 extern "C" CALDEVLIBRARY_API wchar_t* __stdcall CalDev_hi() ;

 extern "C" CALDEVLIBRARY_API wchar_t* __stdcall CalDev_hello() ;


  extern "C" CALDEVLIBRARY_API  void __stdcall CalDev_load(Type type,const wchar_t * id );

 extern "C" CALDEVLIBRARY_API  void __stdcall CalDev_set( );

 extern "C" CALDEVLIBRARY_API  P_RESULT __stdcall CalDev_compute(P_OPTIONS opts );
 #endif
