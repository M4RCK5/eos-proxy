#include <stdint.h>
#include "logger.h"

extern __declspec(dllexport) void* EOS_Platform_GetAntiCheatClientInterface(void* Handle) {
    LogCall("EOS_Platform_GetAntiCheatClientInterface");
    return (void *) 1;
}

extern __declspec(dllexport) uint64_t EOS_AntiCheatClient_AddNotifyMessageToServer(void* Handle, void* Options, void* ClientData, void* NotificationFn) {
    LogCall("EOS_AntiCheatClient_AddNotifyMessageToServer");
    return 1;
}

extern __declspec(dllexport) void EOS_AntiCheatClient_RemoveNotifyMessageToServer(void* Handle, uint64_t NotificationId) {
    LogCall("EOS_AntiCheatClient_RemoveNotifyMessageToServer");
}

extern __declspec(dllexport) uint64_t EOS_AntiCheatClient_AddNotifyMessageToPeer(void* Handle, void* Options, void* ClientData, void* NotificationFn) {
    LogCall("EOS_AntiCheatClient_AddNotifyMessageToPeer");
    return 1;
}

extern __declspec(dllexport) void EOS_AntiCheatClient_RemoveNotifyMessageToPeer(void* Handle, uint64_t NotificationId) {
    LogCall("EOS_AntiCheatClient_RemoveNotifyMessageToPeer");
}

extern __declspec(dllexport) uint64_t EOS_AntiCheatClient_AddNotifyPeerActionRequired(void* Handle, void* Options, void* ClientData, void* NotificationFn) {
    LogCall("EOS_AntiCheatClient_AddNotifyPeerActionRequired");
    return 1;
}

extern __declspec(dllexport) void EOS_AntiCheatClient_RemoveNotifyPeerActionRequired(void* Handle, uint64_t NotificationId) {
    LogCall("EOS_AntiCheatClient_RemoveNotifyPeerActionRequired");
}

extern __declspec(dllexport) uint64_t EOS_AntiCheatClient_AddNotifyPeerAuthStatusChanged(void* Handle, void* Options, void* ClientData, void* NotificationFn) {
    LogCall("EOS_AntiCheatClient_AddNotifyPeerAuthStatusChanged");
    return 1;
}

extern __declspec(dllexport) void EOS_AntiCheatClient_RemoveNotifyPeerAuthStatusChanged(void* Handle, uint64_t NotificationId) {
    LogCall("EOS_AntiCheatClient_RemoveNotifyPeerAuthStatusChanged");
}

extern __declspec(dllexport) uint64_t EOS_AntiCheatClient_AddNotifyClientIntegrityViolated(void* Handle, void* Options, void* ClientData, void* NotificationFn) {
    LogCall("EOS_AntiCheatClient_AddNotifyClientIntegrityViolated");
    return 1;
}

extern __declspec(dllexport) void EOS_AntiCheatClient_RemoveNotifyClientIntegrityViolated(void* Handle, uint64_t NotificationId) {
    LogCall("EOS_AntiCheatClient_RemoveNotifyClientIntegrityViolated");
}

extern __declspec(dllexport) int EOS_AntiCheatClient_BeginSession(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_BeginSession");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_EndSession(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_EndSession");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_PollStatus(void* Handle, void* Options, int32_t* OutViolationType, char* OutMessage) {
    return 18; // EOS_NotFound
}

extern __declspec(dllexport) int EOS_AntiCheatClient_AddExternalIntegrityCatalog(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_AddExternalIntegrityCatalog");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_ReceiveMessageFromServer(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_ReceiveMessageFromServer");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_RegisterPeer(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_RegisterPeer");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_UnregisterPeer(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_UnregisterPeer");
    return 0;
}

extern __declspec(dllexport) int EOS_AntiCheatClient_ReceiveMessageFromPeer(void* Handle, void* Options) {
    LogCall("EOS_AntiCheatClient_ReceiveMessageFromPeer");
    return 0;
}

// A few functions need a basic "implementation"

// -----------------------------------------
// EOS_AntiCheatClient_UnprotectMessage

typedef struct {
    int32_t ApiVersion;
    uint32_t DataLengthBytes;
    const void* Data;
    uint32_t OutBufferSizeBytes;
} EOS_AntiCheatClient_UnprotectMessageOptions;

extern __declspec(dllexport) int EOS_AntiCheatClient_UnprotectMessage(void* Handle, EOS_AntiCheatClient_UnprotectMessageOptions* Options, void* OutBuffer, uint32_t* OutBytesWritten) {
    LogCall("EOS_AntiCheatClient_UnprotectMessage");
    LogText("--- Struct: ApiVersion: %d | DataLengthBytes: %u | OutBufferSizeBytes: %u",
        Options->ApiVersion, Options->DataLengthBytes, Options->OutBufferSizeBytes);
    if (OutBuffer && Options->Data && Options->DataLengthBytes <= Options->OutBufferSizeBytes) {
        memcpy(OutBuffer, Options->Data, Options->DataLengthBytes);
        if (OutBytesWritten) *OutBytesWritten = Options->DataLengthBytes;
    }
    return 0;
}

// -----------------------------------------
// EOS_AntiCheatClient_ProtectMessage

typedef struct {
    int32_t ApiVersion;
    uint32_t DataLengthBytes;
    const void* Data;
    uint32_t OutBufferSizeBytes;
} EOS_AntiCheatClient_ProtectMessageOptions;

extern __declspec(dllexport) int EOS_AntiCheatClient_ProtectMessage(void* Handle, EOS_AntiCheatClient_ProtectMessageOptions* Options, void* OutBuffer, uint32_t* OutBytesWritten) {
    LogCall("EOS_AntiCheatClient_ProtectMessage");
    LogText("--- Struct: ApiVersion: %d | DataLengthBytes: %u | OutBufferSizeBytes: %u",
        Options->ApiVersion, Options->DataLengthBytes, Options->OutBufferSizeBytes);
    if (OutBuffer && Options->Data && Options->DataLengthBytes <= Options->OutBufferSizeBytes) {
        memcpy(OutBuffer, Options->Data, Options->DataLengthBytes);
        if (OutBytesWritten) *OutBytesWritten = Options->DataLengthBytes;
    }
    return 0;
}

// -----------------------------------------
// EOS_AntiCheatClient_GetProtectMessageOutputLength

typedef struct {
    int32_t ApiVersion;
    uint32_t DataLengthBytes;
} EOS_AntiCheatClient_GetProtectMessageOutputLengthOptions;

extern __declspec(dllexport) int EOS_AntiCheatClient_GetProtectMessageOutputLength(void* Handle, EOS_AntiCheatClient_GetProtectMessageOutputLengthOptions* Options, uint32_t* OutBufferSizeBytes) {
    LogCall("EOS_AntiCheatClient_GetProtectMessageOutputLength");
    LogText("--- Struct: ApiVersion: %d | DataLengthBytes: %u", Options->ApiVersion, Options->DataLengthBytes);
    if (OutBufferSizeBytes) *OutBufferSizeBytes = Options->DataLengthBytes;
    return 0;
}

// -----------------------------------------
// EOS_AntiCheatClient_GetModuleBuildId

extern __declspec(dllexport) int EOS_AntiCheatClient_GetModuleBuildId(void* Handle, void* Options, uint32_t* OutModuleBuildId) {
    if (OutModuleBuildId) *OutModuleBuildId = 0x539;
    return 0;
}
