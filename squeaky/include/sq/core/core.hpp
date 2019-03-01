#pragma once
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_SQUEAKY
    #define SQUEAKY_PUBLIC __declspec(dllexport)
  #else
    #define SQUEAKY_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_SQUEAKY
      #define SQUEAKY_PUBLIC __attribute__ ((visibility ("default")))
  #else
      #define SQUEAKY_PUBLIC
  #endif
#endif

namespace sq {



}

