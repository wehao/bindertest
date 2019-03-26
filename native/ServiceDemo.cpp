#include "IMyService.h"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

// namespace android {
using namespace android;

int main(int, char**) {
	sp<IServiceManager> sm = defaultServiceManager();
	sm->addService(String16("service.myservice"), new BnMyService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}

// };