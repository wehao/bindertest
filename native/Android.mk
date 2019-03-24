LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ServiceDemo

LOCAL_C_INCLUDES := ./

LOCAL_SRC_FILES := ServiceDemo.cpp

LOCAL_SHARE_LIBRARIES := libutils \
	libbinder \

include $(BUILD_EXECUTABLE)