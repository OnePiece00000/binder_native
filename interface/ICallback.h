#ifndef Icallback_H
#define Icallback_H
#include <binder/IInterface.h>

namespace android {

class ICallback : public IInterface {
public:
    DECLARE_META_INTERFACE(Callback);
    virtual int notifyCallback(int a) = 0;
};

class BnCallback : public BnInterface<ICallback> {
public:
virtual status_t    onTransact( uint32_t code,
                                const Parcel& data,
                                Parcel* reply,
                                uint32_t flags = 0);
};
}
#endif

