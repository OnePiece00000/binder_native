#include "../interface/IXXXXService.h"
#include <binder/BinderService.h>
#include "../interface/ICallback.h"

namespace android {
class XXXXService : public BinderService<XXXXService>, public BnXXXXService {
public:
    XXXXService();
    static const char* getServiceName() { return "XXXXService"; }//will be the service name
    virtual int setSomething(int a);
    virtual int getSomething();
    virtual int setCallback(const sp<ICallback>& callback);
protected:
    int myParam;
    sp<ICallback> mCallback;
  };
}
