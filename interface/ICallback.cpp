#include "IXXXXService.h"
#include <binder/Parcel.h>
#include <binder/IInterface.h>
#include <utils/Log.h>

#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: ICallback"
#endif

namespace android {

enum {
    NOTIFY_CALLBACK,
};

//////////////////client
class BpCallback : public BpInterface<ICallback> {
public:
    BpCallback(const sp<IBinder>& impl) : BpInterface<ICallback>(impl) {
    }

    virtual int notifyCallback(int a) {
        ALOGD(" BpCallback::notifyCallback, a = %d", a);
        Parcel data,reply;
        data.writeInt32(a);
        remote()->transact(NOTIFY_CALLBACK,data,&reply);
        return reply.readInt32();
    }
};

IMPLEMENT_META_INTERFACE(Callback, "chenxf.binder.ICallback");


////////////////server
status_t BnCallback::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
    switch (code) {
        case NOTIFY_CALLBACK: {
            ALOGD("BnCallback::onTransact>>NOTIFY_CALLBACK\n");
            reply->writeInt32(notifyCallback((int) data.readInt32()) );
            return NO_ERROR;
        } break;
    }

    return BBinder::onTransact(code, data, reply, flags);
}
}

