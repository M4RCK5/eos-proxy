#pragma once

#if defined(NO_LOGGING)
    #define InitLog(x)
    #define EndLog()
    #define LogCall(x)
    static void LogText(const char* _, ...) {}
#else
    void InitLog(const char* name);
    void EndLog();

    #if !defined(_MSC_VER)
      __attribute__ (( format(printf, 1, 2) ))
    #endif
    void LogText(const char* fmt, ...);

    #include <intrin.h>   // _ReturnAddress
    #define LogCall(funcName) LogText("%-60s  caller=0x%p", funcName, _ReturnAddress())
#endif
