#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/threads.h>

#include <cutils/properties.h>
#include "XXXXService.h"
#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif
#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: XXXXService"
#endif

namespace android {
    XXXXService::XXXXService() {
        myParam = 0;
    }

    int XXXXService::setSomething(int a) {
        ALOGD(" XXXXService::setSomething a = %d myParam %d", a, myParam);
        myParam += a;
        //Let's trigger callback
        if(mCallback != NULL) {
            ALOGD("will notify???");
            mCallback->notifyCallback(myParam);
        } else {
            ALOGW("mCallback is NULL");
        }
        return 0;//OK
    }
    int XXXXService::getSomething() {
        ALOGD("#XXXXService::getSomething myParam = %d", myParam);
        return myParam;
    }

    int XXXXService::setCallback(const sp<ICallback>& callback) {
      ALOGD(" XXXXService::setCallback");
      mCallback = callback;
      return 0;
    }
}

