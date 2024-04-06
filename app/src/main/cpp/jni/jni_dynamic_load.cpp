//
// Created by Handler on 2024-04-06 006.
//

#include <jni.h>
#include "jni_dynamic_load.h"


/**
 * 这里的方法名可以与JNIDynamicLoad类中的方法名不同，方法返回值，参数类型跟个数必须得是一致的
 *
 */
jstring getMessage(JNIEnv *env, jobject jobj) {
    return env->NewStringUTF("this is msg");
}

jint plus(JNIEnv *env, jobject jobj, int x, int y) {
    return x + y;
}

// 这里定义一个宏，表示动态注册方法所在的类
#define JAVA_CLASS "com/example/myapplication/load/JNIDynamicLoad"

/**
 * 这里是需要动态加载的方法，
 * .name必须跟JNIDynamicLoad类中的native方法名一致;
 * .signature表示方法的返回值
 * 最后一个表示的是函数指针，指向前面定义的JNI方法
 */
static JNINativeMethod getMethods[] = {
        {"getNativeString", "()Ljava/lang/String;", (void *) getMessage},
        {"sum",             "(II)I",                (void *) plus}
};



/**
 * @param name 类名
 * @param methods 表示方法的结构体
 * @param nMethods 方法个数
 */
int registerNativeMethods(JNIEnv *env, const char *name, JNINativeMethod *methods,
                          jint nMethods) {
    jclass jcls;
    jcls = env->FindClass(name);
    if (jcls == nullptr) {
        return JNI_FALSE;
    }
    // 调用RegisterNatives()函数去注册，小于0表示注册不成功
    if (env->RegisterNatives(jcls, methods, nMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/**
 * 这里就是函数动态注册的逻辑
 * 封装了registerNativeMethods方法实现动态注册
 */
JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_FALSE;
    }
    registerNativeMethods(env, JAVA_CLASS, getMethods, 2);

    return JNI_VERSION_1_6;
}