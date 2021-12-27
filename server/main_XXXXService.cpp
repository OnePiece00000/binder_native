#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "XXXXService.h"
#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif
#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: XXXXService-main"
#endif

#define EASY_START_BINDER_SERVICE 0

using namespace android;

int main(int argc, char** argv)
{
#if EASY_START_BINDER_SERVICE
    XXXXService::publishAndJoinThreadPool();//使用了父类BinderService的函数
#else
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm(defaultServiceManager());
    sm->addService(String16(XXXXService::getServiceName()), new XXXXService());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
#endif

    return 0;
}
