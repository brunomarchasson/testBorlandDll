#include <string>
extern "C" {
    typedef int (__stdcall *init_func_ptr)(const wchar_t * param1);
    typedef wchar_t* (__stdcall*hi_func_ptr)();
}
std::string helloUser( std::string name );

void init( std::wstring name );

std::wstring hi( void );
