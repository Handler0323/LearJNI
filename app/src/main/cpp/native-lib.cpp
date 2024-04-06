#include <jni.h>
#include <string>
/**
 * 这里如果要使用#incloud <people.h>语法，
 * 需要在CmakeLists.txt文件中加入include_directories(people/)
 */
#include "people/people.h"

extern "C" JNIEXPORT jstring
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    People people;
    return env->NewStringUTF(people.getString().c_str());
}