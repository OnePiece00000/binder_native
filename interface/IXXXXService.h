#ifndef IXXXXService_H  
#define IXXXXService_H 

#include <binder/IInterface.h>
#include "ICallback.h"

namespace android {

class IXXXXService : public IInterface {
public:
    DECLARE_META_INTERFACE(XXXXService);
    virtual int setSomething(int a) = 0;
    virtual int getSomething() = 0;
    virtual int setCallback(const sp<ICallback>& callback) = 0;
};

class BnXXXXService : public BnInterface<IXXXXService> {
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

}

#endif
