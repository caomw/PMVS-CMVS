LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
export GRACLUS_TOP:= $(LOCAL_PATH)
subdirs := $(addprefix $(LOCAL_PATH)/,$(addsuffix /Android.mk, \
				METIS \
				MULTILEVEL \
        ))
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/INCLUDE
include $(subdirs)