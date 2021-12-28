#include "IXXXXService.h"
#include <binder/Parcel.h>
#include <binder/IInterface.h>

#include <binder/IPCThreadState.h>
#include <utils/threads.h>

#include "ICallback.h"
#include <utils/Log.h>

#ifdef LOG_NDEBUG
#undef LOG_NDEBUG
#define LOG_NDEBUG 0
#endif

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "chenxf: IXXXXService"
#endif

namespace android {

enum {
    SET_SOMETHING = IBinder::FIRST_CALL_TRANSACTION,
    GET_SOMETHING,
    SET_CALLBACK
};

//------------------------------------proxy side--------------------------------

class BpXXXXService : public BpInterface<IXXXXService> {
public:
    BpXXXXService(const sp<IBinder>& impl)
        : BpInterface<IXXXXService>(impl) {
    }
    virtual int setSomething(int a) {
        ALOGD(" BpXXXXService::setSomething a = %d ", a);
        Parcel data,reply;
        data.writeInt32(a);
        remote()->transact(SET_SOMETHING,data,&reply);
        return reply.readInt32();
    }
    virtual int getSomething() {
        ALOGD(" BpXXXXService::getSomething ");
        Parcel data,reply;
        data.writeInterfaceToken(IXXXXService::getInterfaceDescriptor());
        remote()->transact(GET_SOMETHING,data,&reply);
        return reply.readInt32();
    }
    virtual int setCallback(const sp<ICallback>& callback) {
      ALOGD("BpXXXXService::setCallback");
      Parcel data, reply;
      data.writeStrongBinder(callback->asBinder(callback));// TODO: important
      remote()->transact(SET_CALLBACK, data, &reply);
      return reply.readInt32();
    }

};

IMPLEMENT_META_INTERFACE(XXXXService, "chenxf.binder.IXXXXService");

//------------------------------------server side--------------------------------
status_t BnXXXXService::onTransact (
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags){
    switch (code) {
        case SET_SOMETHING: {
            ALOGD("BnXXXXService::onTransact  SET_SOMETHING ");
            reply->writeInt32(setSomething((int) data.readInt32()));
            return NO_ERROR;
        } break;
        case GET_SOMETHING: {
            ALOGD("BnXXXXService::onTransact  GET_SOMETHING ");
            reply->writeInt32(getSomething());
            return NO_ERROR;
        } break;
        case SET_CALLBACK: {
            ALOGD("BnXXXXService::onTransact  SET_CALLBACK ");
            sp<ICallback> callback = interface_cast<ICallback>(data.readStrongBinder());// TODO: important!
            reply->writeInt32(setCallback(callback));
            return NO_ERROR;
        }
    }

    return BBinder::onTransact(code, data, reply, flags);
}

}

