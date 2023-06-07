#include <napi.h>
#include <string>
#include <codecvt>
#include <locale>
#include "_caldev.h"
#include "asyncWorker.h"
// #include "calDevApi.h"

std::string ws_to_UTF8 (const wchar_t *ws)
{
    std::wstring_convert <std::codecvt_utf8 <wchar_t>, wchar_t> convert;
    return convert.to_bytes (ws);
}
std::wstring ws_from_UTF8 (const char *ws)
{
    std::wstring_convert <std::codecvt_utf8 <wchar_t>, wchar_t> convert;
    return convert.from_bytes (ws);
}


// native C++ function that is assigned to `greetHello` property on `exports` object
Napi::String greetHello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // call `helloUser` function from `greeting.cpp` file
    std::string user = (std::string) info[0].ToString();
    std::string result = helloUser( user );

    // return new `Napi::String` value
    return Napi::String::New(env, result);
}
// native C++ function that is assigned to `greetHello` property on `exports` object
Napi::String calculDev(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // call `helloUser` function from `greeting.cpp` file
    std::string user = (std::string) info[0].ToString();
    std::string result = helloUser( user );

    // return new `Napi::String` value
    return Napi::String::New(env, result);
}

// // callback method when module is registered with Node.js
// Napi::Object Init(Napi::Env env, Napi::Object exports) {

//     // set a key on `exports` object
//     exports.Set(
//         Napi::String::New(env, "greetHello"), // property name => "greetHello"
//         Napi::Function::New(env, greetHello) // property value => `greetHello` function
//     );
//     exports.Set(
//         Napi::String::New(env, "calculDev"), // property name => "greetHello"
//         Napi::Function::New(env, calculDev) // property value => `greetHello` function
//     );

//     // return `exports` object (always)
//     return exports;
// }

// // register `greet` module which calls `Init` method
// NODE_API_MODULE(caldev, Init)


//-----------------------------

Value runSimpleAsyncWorker(const CallbackInfo& info) {
  int runTime = info[0].As<Number>();
  Napi::Env env = info.Env();
//   Function callback = info[1].As<Function>();
    // Promise::Deferred deferred = Napi::Promise::Deferred::New(env);
//   SimpleAsyncWorker* asyncWorker = new SimpleAsyncWorker(callback, runTime);
  SimpleAsyncWorker* asyncWorker = new SimpleAsyncWorker(env, runTime);
  auto  promise = asyncWorker->GetPromise();
  asyncWorker->Queue();
//   std::string msg =
//       "SimpleAsyncWorker for " + std::to_string(runTime) + " seconds queued.";
    return promise;

};

Napi::String initDDd(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    printf("rr1");

    // call `helloUser` function from `greeting.cpp` file
    
    std::string user = (std::string) info[0].ToString();
    printf("rr%s", user);
    
    // CalDevApi api;
    // api.init( ws_from_UTF8(user.c_str()).c_str());
    CalDev_init( ws_from_UTF8(user.c_str()) );
    printf("rr3");

    // return new `Napi::String` value
    return Napi::String::New(env, "1");
}

Napi::String hizz(const Napi::CallbackInfo& info) {
   
    Napi::Env env = info.Env();
// call `helloUser` function from `greeting.cpp` file
    std::wstring result = CalDev_hi();
    // CalDevApi api;
    // std::wstring result = api.hi();
    std::string r = ws_to_UTF8(result.c_str());
    // return Napi::String::New(env,"1" );
    // return new `Napi::String` value
    return Napi::String::New(env, r);
    
}

Object Init(Env env, Object exports) {
     exports.Set(
        Napi::String::New(env, "greetHello"), // property name => "greetHello"
        Napi::Function::New(env, greetHello) // property value => `greetHello` function
    );
     exports.Set(
        Napi::String::New(env, "init"), // property name => "greetHello"
        Napi::Function::New(env, initDDd) // property value => `greetHello` function
    );
     exports.Set(
        Napi::String::New(env, "hi"), // property name => "greetHello"
        Napi::Function::New(env, hizz) // property value => `greetHello` function
    );
     
    exports.Set(
        Napi::String::New(env, "calculDev"), // property name => "greetHello"
        Napi::Function::New(env, calculDev) // property value => `greetHello` function
    );
  exports["runSimpleAsyncWorker"] = Function::New(
      env, runSimpleAsyncWorker, std::string("runSimpleAsyncWorker"));
  
  return exports;
}

NODE_API_MODULE(caldev, Init)