LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := stann
LOCAL_MODULE_FILENAME := libstann
LOCAL_CFLAGS := -O2 -fPIC -w
LOCAL_SRC_FILES := assert.hpp bruteNN.hpp bsearch.hpp \
                   dpoint.hpp pair_iter.hpp qknn.hpp \
				   rand.hpp sep_float.hpp sfcnn.hpp sfcnn_knng.hpp \
	               zorder_lt.hpp zorder_type_traits.hpp
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)
include $(BUILD_STATIC_LIBRARY)
LOCAL_LDLIBS := -llog
