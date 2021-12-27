#include "../interface/IXXXXService.h"
#include <binder/BinderService.h>

namespace android {
class XXXXService : public BinderService<XXXXService>, public BnXXXXService {
public:
    XXXXService();
    static const char* getServiceName() { return "XXXXService"; }//will be the service name
    virtual int setSomething(int a);
    virtual int getSomething();
protected:
    int myParam;
  };
}
