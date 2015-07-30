LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
include $(LOCAL_PATH)/Config.mk
LOCAL_MODULE:= metis
LOCAL_CFLAGS:= -O3 -fPIC -w
LOCAL_SRC_FILES:= $(ALLOBJ)
include $(BUILD_STATIC_LIBRARY)
