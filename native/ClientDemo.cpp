#include "IMyService.h"

int main() {
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("service.myservice"));
	sp<IMyService> cs = interface_cast<IMyService>(binder);
	cs->sayHello();
	return 0;
}