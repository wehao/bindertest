#include "IMyService.h"

namespace android {
	IMPLEMENT_META_INTERFACE(MyService, "android.demo.IMyService")

	BpMyService::BpMyService(const sp<IBinder>& impl) :
			BpInterface<IMyService>(impl) {
		
	}

	void BpMyService::sayHello() {
		printf("BpMyService::sayHello\n");
		Parcel data, reply;
		data.writeInterfaceTokenm(IMyService::getInterfaceDescriptor());
		remote()->transact(HELLO, data, &reply);
		printf("get num from BnMyService: %d \n", reply.readInt32());
	}

	status_t BnMyService::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t falgs) {
		switch (code) {
			case HELLO: {
				printf("BnMyService:: got the client hello\n");
				CHECK_INTERFACE(IMyService, data, reply);
				sayHello();
				reply->writeInt32(2019);
				return NO_ERROR;
			} 	break;
			default:
				break;	
		}
		return NO_ERROR;
	}

	void BnMyService::sayHello() {
		printf("BnMyService::sayHello\n");
	}
}