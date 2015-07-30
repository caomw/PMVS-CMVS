LOCAL_PATH := $(call my-dir)
export MAINDIR:= $(LOCAL_PATH)

include $(CLEAR_VARS)
include $(MAINDIR)/clapack/Android.mk
LOCAL_PATH := $(MAINDIR)

include $(CLEAR_VARS)
include $(MAINDIR)/graclus/Android.mk
LOCAL_PATH := $(MAINDIR)

include $(CLEAR_VARS)
LOCAL_MODULE:= liblapack
LOCAL_STATIC_LIBRARIES := tmglib clapack1 clapack2 clapack3 blas f2c
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
LOCAL_EXPORT_LDLIBS := $(LOCAL_LDLIBS)
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libgraclus
LOCAL_STATIC_LIBRARIES := metis multilevel
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
LOCAL_EXPORT_LDLIBS := $(LOCAL_LDLIBS)
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libstann
LOCAL_SRC_FILES := libstann.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libgsl
LOCAL_SRC_FILES := libgsl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libgslcblas
LOCAL_SRC_FILES := libgslcblas.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libjpeg
LOCAL_SRC_FILES := libjpeg.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libboost_serialization
LOCAL_SRC_FILES := libboost_serialization.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libboost_system
LOCAL_SRC_FILES := libboost_system.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := cmvspmvs
LOCAL_MODULE_FILENAME := libcmvspmvs

LOCAL_SRC_FILES := \
    ./cmvs/graclus.cc ./cmvs/bundle.cc ./cmvs.cc ./genOption.cc \
	./image/camera.cc ./image/image.cc ./image/photo.cc ./image/photoSetS.cc \
	./numeric/mylapack.cc \
	./pmvs/detectFeatures.cc ./pmvs/detector.cc \
	./pmvs/dog.cc ./pmvs/expand.cc ./pmvs/filter.cc ./pmvs/findMatch.cc \
	./pmvs/harris.cc ./pmvs/optim.cc ./pmvs/option.cc ./pmvs/patch.cc \
	./pmvs/patchOrganizerS.cc ./pmvs/point.cc ./pmvs/seed.cc ./pmvs2.cc 
LOCAL_STATIC_LIBRARIES := \
                libstann libgraclus \
				libgsl libjpeg libgslcblas liblapack \
                libboost_serialization libboost_system \
				
				
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)