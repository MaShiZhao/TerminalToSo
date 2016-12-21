#include "com_example_mashizhao_myapplication_JniUtil.h"
#include <jni.h>
#include <android/log.h>

extern "C" {

JNIEXPORT jstring JNICALL Java_com_example_mashizhao_myapplication_JniUtil_jniUtilTest
        (JNIEnv *env, jobject) {
    return env->NewStringUTF("Hello JNI");

}

}
