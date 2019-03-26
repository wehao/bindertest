LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# LOCAL_LDFLAGS += -shared

# LOCAL_CFLAGS += $(svc_c_flags)

# LOCAL_MODULE := ServiceDemo
LOCAL_MODULE := ClientDemo

LOCAL_C_INCLUDES := ./

# LOCAL_SRC_FILES := ServiceDemo.cpp IMyService.cpp
LOCAL_SRC_FILES := ClientDemo.cpp IMyService.cpp

LOCAL_SHARED_LIBRARIES := \
	libcutils \
	libutils \
    libui \
    libgui \
    libbinder

include $(BUILD_EXECUTABLE)