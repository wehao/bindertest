#include "IMyService.h"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

using namespace android;

int main(int, char**) {
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> binder = sm->getService(String16("service.myservice"));
	sp<IMyService> cs = interface_cast<IMyService>(binder);
	cs->sayHello();
	return 0;
}