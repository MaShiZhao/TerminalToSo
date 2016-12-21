so shared object jni java native interface ndk native developmentit

Android Studio 生成so文件的两种方法

gradle 插件可用 比较方便 http://www.jianshu.com/p/2690c9964110

脚本执行 eclipse 可用 比较麻烦 
http://www.jianshu.com/p/3494741f0ad1
http://blog.csdn.net/u012858313/article/details/51307275

此demo是方式2

1. local.properties 添加ndk配置：
   ndk.dir=/Users/~/Android/sdk/ndk-bundle
   sdk.dir=/Users/~/Android/sdk
   gradle.properties 添加配置：
   android.useDeprecatedNdk=true
2. 创建java 以及用到方法
  public class JniUtil
  {
    static {
        //jniutil so文件名字 区分大小写
        System.loadLibrary("jniutil");
    }
    //报错忽略
    public static native String jniUtilTest();
       
  }
 3. build —— make project 在build目录下生出JniUtil.class文件（查看上面文件）
 4. Terminal 中执行 
  javah -d jni -classpath sdk-jar的路径：class的到debug路径 com.~.jniUtil.class 
  javah -d jni -classpath /Users/~/Android/sdk/platforms/android-21/android.jar： /Users/~/Desktop/AllBaseDemo/MyApplication/app/build/intermediates/classes/debug com.example.mashizhao.myapplication.JniUtil
  注意：jar文件后面是冒号不是分好
       com.example~.class 这个目录需要知道 后面调用jniUtilTest 需要用到新建java文件目录需要保持一致
 5.创建 C++ .class  需要cpp文件即可 
   main.cpp 
    #include "com_example_mashizhao_myapplication_JniUtil.h"
    #include <jni.h>
    #include <android/log.h>

    extern "C" {
    JNIEXPORT jstring JNICALL Java_com_example_mashizhao_myapplication_JniUtil_jniUtilTest
        (JNIEnv *env, jobject) {
      return env->NewStringUTF("Hello JNI");
      }
     }
     
  6.创建 Android.mk Application.mk 文件
    LOCAL_PATH := $(call my-dir)
    include $(CLEAR_VARS)
    LOCAL_MODULE := jniutil //需要修改
    LOCAL_SRC_FILES := main.cpp //需要修改
    LOCAL_LDLIBS +=-L$(SYSROOT)/usr/lib -lm -llog
    include $(BUILD_SHARED_LIBRARY) 
    
    APP_ABI := all      #这句是设置生成的cpu指令类型，提示，目前绝大部分安卓手机支持armeabi，libs下太多类型，编译进去 apk 包会过大
    APP_PLATFORM := android-8    
   
   7  在main-jni 目录下执行
      ndk-build
    
     
     
     
     
