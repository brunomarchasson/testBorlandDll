#pragma once
#include <napi.h>

using namespace Napi;

class SimpleAsyncWorker : public AsyncWorker {
 public:
  SimpleAsyncWorker(Napi::Env &, int );
  virtual ~SimpleAsyncWorker(){};
  Napi::Promise GetPromise();
  void Execute();
  void OnOK();
  void OnError(Napi::Error const &error);

 private:
  int runTime;
  Napi::Promise::Deferred deferred;
};