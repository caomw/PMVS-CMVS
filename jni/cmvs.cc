#include <jni.h>
#include <android/log.h>
#include <iostream>
#include <vector>
#include <list>
#include "./cmvs/bundle.h"

#define  LOG_TAG    "cmvs"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C"{
using namespace std;

//int main(int argc, char* argv[]) {
int cmvs() {
	int argc = 2;
    char **argv = new char* [argc];
    argv[0] = "cmvs";
	argv[1] = "/storage/sdcard/data/pmvs/";
	
	LOGI("enter cmvs");
	
  if (argc < 2) {
	LOGI("cmvs error");
    cerr << "Usage: " << argv[0] << " prefix maximage[=100] CPU[=4]" << endl
         << endl
         << "You should choose maximage based on the amount of memory in your machine." << endl
         << "CPU should be the number of (virtual) CPUs or cores in your machine." << endl
         << "If you want more control of the program, look into the comments inside program/main/cmvs.cc" << endl;
    exit (1);
  }  
  
  int maximage = 100;
  if (3 <= argc)
    maximage = atoi(argv[2]);

  int CPU = 4;
  if (4 <= argc)
    CPU = atoi(argv[3]);

  //----------------------------------------------------------------------
  // If you want more control of the program, you can also change the
  // following two parameters.
  // scoreRatioThreshold, and coverageThreshold correspond to
  // \\lambda and \\delta in our CVPR 2010 paper.
  // Please refer to the paper for their definitions. The following are
  // brief explanations.
  //
  // CMVS tries to make sure that multi-view stereo (MVS)
  // reconstruction accuracy will be more than a certain threshold at
  // Structure-from-Motion (SfM) points. scoreRatioThreshold is this
  // threshold on the reconstruction accuracy [0, 1.0]. CMVS makes
  // sure that the ratio of "satisfied" SfM points is more than
  // coverageThreshold [0 1.0].
  //
  // Intuitively, increasing thsse parameters lead to more images and
  // clusters in the output.
  const float scoreRatioThreshold = 0.7f;
  const float coverageThreshold = 0.7f;
  

  const int iNumForScore = 4;
  const int pnumThreshold = 0;
  CMVS::Cbundle bundle;
  bundle.run(argv[1], maximage, iNumForScore,
             scoreRatioThreshold, coverageThreshold,
             pnumThreshold, CPU);
}

void Java_com_example_pbatest_MainActivity_cmvs(JNIEnv* env, jobject thiz )
{
	cmvs();
}
}