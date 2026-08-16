#pragma once
// Disclaimer: AI generated code

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

static char    g_LogPath[1024];
static HANDLE  g_hLog = INVALID_HANDLE_VALUE;
static CRITICAL_SECTION g_cs;

void InitLog(const char* name) {
    InitializeCriticalSection(&g_cs);

    _snprintf_s(g_LogPath, sizeof(g_LogPath), _TRUNCATE,
                "%s_proxy.log", name);

    g_hLog = CreateFileA(
        g_LogPath,
        GENERIC_WRITE, FILE_SHARE_READ,
        NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (g_hLog != INVALID_HANDLE_VALUE)
        SetFilePointer(g_hLog, 0, NULL, FILE_END);

    char msg[512];
    _snprintf_s(msg, sizeof(msg), _TRUNCATE,
        "\r\n[PROXY] ===== Session start %s =====\r\n", name);

    DWORD written;
    if (g_hLog != INVALID_HANDLE_VALUE)
        WriteFile(g_hLog, msg, (DWORD)strlen(msg), &written, NULL);
    OutputDebugStringA(msg);
}

void EndLog() {
    if (g_hLog != INVALID_HANDLE_VALUE) CloseHandle(g_hLog);
    DeleteCriticalSection(&g_cs);
}

#define LogCall(funcName) LogText("%-60s  caller=0x%p", funcName, _ReturnAddress())

#if !defined(_MSC_VER)
__attribute__ (( format(printf, 1, 2) ))
#endif
void LogText(const char* fmt, ...) {
    // Format the message
    char msg[1024];
    va_list args;
    va_start(args, fmt);
    _vsnprintf_s(msg, sizeof(msg), _TRUNCATE, fmt, args);
    va_end(args);

    // Prepend timestamp + TID
    SYSTEMTIME st;
    GetLocalTime(&st);
    char line[1280];
    _snprintf_s(line, sizeof(line), _TRUNCATE,
        "[%04d-%02d-%02d %02d:%02d:%02d.%03d] TID=%5lu  %s\r\n",
        st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
        GetCurrentThreadId(), msg);

    EnterCriticalSection(&g_cs);
    DWORD w;
    if (g_hLog != INVALID_HANDLE_VALUE)
        WriteFile(g_hLog, line, (DWORD)strlen(line), &w, NULL);
    OutputDebugStringA(line);
    LeaveCriticalSection(&g_cs);
}
