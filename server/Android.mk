LOCAL_PATH:= $(call my-dir)
#LOCAL_CFLAGS_ALL :=-I. -I$(LOCAL_PATH)/..

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
        main_XXXXService.cpp \
        XXXXService.cpp \
        ../interface/IXXXXService.cpp \
        ../interface/ICallback.cpp

LOCAL_SHARED_LIBRARIES := \
        libcutils libutils libbinder libdl liblog

LOCAL_C_INCLUDES := \
    frameworks/base/include \
    frameworks/native/include \
    $(VENDOR_SDK_INCLUDES)

LOCAL_CFLAGS += -Wall -Wno-unused-parameter

#LOCAL_LDLIBS :=  -llog

LOCAL_MODULE:= test_binder_server
#LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
