 #include "CalDev.h"

 #define MAX_SIZE 30
 #define INDEX_OUT_OF_BOUNDS_EXCEPTION 1
 #define EMPTY_STACK 2

 // Stack constructor
 CalDev::CalDev(const wchar_t* n) {
		 this->name = String(n);
 }

   CalDev::CalDev(Type type, const wchar_t* id) {
		 this->name = String(id);
 }

 // Stack destructor
 CalDev::~CalDev() {

 }

 // Returns the top of the stack
 wchar_t* CalDev::sayHi() {
	return ("Hello "+this->name).c_str();
 }

