#include "asyncWorker.h"
#include <chrono>
#include <thread>

SimpleAsyncWorker::SimpleAsyncWorker(Napi::Env &env, int runTime)
    : AsyncWorker(env), runTime(runTime), deferred(Napi::Promise::Deferred::New(env)){};

void SimpleAsyncWorker::Execute()
{
    std::this_thread::sleep_for(std::chrono::seconds(runTime));
    if (runTime == 4)
        SetError("Oops! Failed after 'working' 4 seconds.");
};

void SimpleAsyncWorker::OnOK()
{
    std::string msg = "SimpleAsyncWorker returning after 'working' " +
                      std::to_string(runTime) + " seconds.";
    //   Callback().Call({Env().Null(), String::New(Env(), msg)});
    deferred.Resolve(String::New(Env(), msg));
};
void SimpleAsyncWorker::OnError(Napi::Error const &error)
{
    deferred.Reject(error.Value());
}

Napi::Promise SimpleAsyncWorker::GetPromise() { return deferred.Promise(); }