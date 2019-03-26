#ifndef IMYSERVICE_H
#define IMYSERVICE_H

#include <binder/IInterface.h>
#include <utils/String16.h>
#include <utils/Vector.h>
#include <binder/Parcel.h>
#include <utils/RefBase.h>

namespace android {
	class IMyService : public IInterface {
	public:
		DECLARE_META_INTERFACE(MyService);
		virtual void sayHello() = 0;
		// IMyService();
		// ~IMyService();
		enum {
			HELLO = 1,
		};
	};

	

	class BpMyService: public BpInterface<IMyService>
	{
	public:
		BpMyService(const sp<IBinder>& impl);
		virtual void sayHello();
		// BpMyService();
		// ~BpMyService();
		
	};

	class BnMyService : public BnInterface<IMyService>
	{
	public:
		virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t falgs = 0);
		virtual void sayHello();
	};
};

#endif