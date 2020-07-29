LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=hello.out

#values for multilib("32", "64", "both")
#LOCAL_MULTILIB:="64"

TARGET_ARCH:=arm64

SRCS:=app.c

LOCAL_SRC_FILES:=$(SRCS)

include $(BUILD_EXECUTABLE)

