//---------------------------------------------------------------------------
#include <vcl.h>
#include "CalDevDefs.h"
#ifndef CalDevH
#define CalDevH
//---------------------------------------------------------------------------


 class CalDev{
 private:
	  String name;
 public:
		 // Stack constructor
		 CalDev(const wchar_t *);
		 CalDev( Type,const wchar_t *);
		 // Stack destructor
		 ~CalDev();
		 // Checks whether the stack is empty
		 wchar_t * sayHi();
 };
 #endif
