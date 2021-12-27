#include <stdio.h>
#include <binder/IServiceManager.h>
#include <cutils/log.h>
#include <android/log.h>
#include "../interface/IXXXXService.h"

#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: Client-main"
#endif

using namespace android;

sp<IXXXXService> mXXXXService;

void initXXXXServiceClient() {
    int count = 10;
    if (mXXXXService == 0) {
        sp<IServiceManager> sm = defaultServiceManager();
        sp<IBinder> binder;
        do {
            binder = sm->getService(String16("XXXXService"));
            if (binder != 0)
            break;
            ALOGW("XXXXService not published, waiting...");
            sleep(1); // 1 s
            count++;
        } while (count < 20);
        mXXXXService = interface_cast<IXXXXService>(binder);
    }
}

int main(int argc, char* argv[]) {
    initXXXXServiceClient();
    if(mXXXXService ==NULL) {
        ALOGW("cannot find XXXXService");
        return 0;
    }

    while(1) {
        mXXXXService->setSomething(1);
        sleep(1);
        ALOGD("getSomething %d", mXXXXService->getSomething());
    }
    return 0;
}
