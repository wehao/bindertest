#include "IMyService.h"
#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>

int main() {
	sp <IServiceManager> sm = defaultServiceManager();
	sm->addService(String16("service.myservice"), new BnMyService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}