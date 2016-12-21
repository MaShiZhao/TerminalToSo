LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := jniutil
LOCAL_SRC_FILES := main.cpp
LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog

include $(BUILD_SHARED_LIBRARY)