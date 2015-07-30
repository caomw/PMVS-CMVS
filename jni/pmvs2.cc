#include <jni.h>
#include <android/log.h>
#include <iostream>
#include <string>
#include "./pmvs/findMatch.h"
#include "./pmvs/option.h"

#define  LOG_TAG    "pmvs"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#ifndef JNIEXPORT
#define JNIEXPORT
#endif

#ifndef JNICALL
#define JNICALL
#endif

extern "C"{
	
using namespace PMVS3;
using namespace std;

//int main(int argc, char* argv[]) {
int pmvs() {
	int argc = 3;
    char **argv = new char* [argc];
    argv[0] = "pmvs2";
	argv[1] = "/storage/sdcard/data/pmvs/";
	argv[2] = "option-0000";
	
LOGI("enter pmvs");
	
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " prefix option_file" << endl
         << endl
         << "--------------------------------------------------" << endl
         << "level       1    csize    2" << endl
         << "threshold   0.7  wsize    7" << endl
         << "minImageNum 3    CPU      4" << endl
         << "useVisData  0    sequence -1" << endl
         << "quad        2.5  maxAngle 10.0" << endl
         << "--------------------------------------------------" << endl
         << "2 ways to specify targetting images" << endl
         << "timages  5  1 3 5 7 9 (enumeration)" << endl
         << "        -1  0 24 (range specification)" << endl
         << "--------------------------------------------------" << endl
         << "4 ways to specify other images" << endl
         << "oimages  5  0 2 4 6 8 (enumeration)" << endl
         << "        -1  24 48 (range specification)" << endl;
    exit (1);
  }
  
  PMVS3::Soption option;
  option.init(argv[1], argv[2]);  
  
  PMVS3::CfindMatch findMatch;
  findMatch.init(option);
  findMatch.run();
  
  char buffer[1024];
  sprintf(buffer, "%smodels/%s", argv[1], argv[2]);
  findMatch.write(buffer);
}


void Java_com_example_pbatest_MainActivity_pmvs(JNIEnv* env, jobject thiz )
{
	pmvs();
}
}