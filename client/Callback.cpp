#include <binder/Parcel.h>
#include <binder/IPCThreadState.h>
#include <utils/String16.h>
#include <utils/threads.h>
#include <utils/Atomic.h>

//#include <cutils/bitops.h>
#include <cutils/properties.h>
#include <cutils/compiler.h>
#include "Callback.h"
#include <utils/Log.h>
#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: client-Callback"
#endif

namespace android {
  int Callback::notifyCallback(int a) {
    ALOGD("Callback::notifyCallback, Actually, come from XXXXService.., the callback value:  %d", a);
    return 1;
  }

}

