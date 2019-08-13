#pragma once
#ifdef EVENTTYPES_H
#define EVENTTYPES_H
#endif

enum class KEY_EVENT_TYPES {
    KEY_PRESS = 1,
    KEY_RELEASE = 2,
    KEY_DOUBLE_PRESS = 3,
    KEY_HOLD = 4,
};

typedef struct SvarogKey {
    int key;
};

typedef struct LayerType {
    const char* EvtType;
    int id;
};

enum class AUDIO_EVENT_TYPES {
    AUDIO_STREAM = 1,
    AUDIO_ENTRY = 2,
};