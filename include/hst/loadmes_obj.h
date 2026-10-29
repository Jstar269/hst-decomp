/* Loading-message object: a background resource and a message resource, each with a name cache and a reset vector. */
#ifndef HST_LOADMES_OBJ_H
#define HST_LOADMES_OBJ_H

#include "hst/vec.h"

/* Resource owned through a virtual destructor. */
struct LoadMesRes {
    virtual ~LoadMesRes();
};

struct LoadMesObj {
    char pad0[0x34];
    LoadMesRes *bg;       /* 0x34 background resource */
    LoadMesRes *message;  /* 0x38 message resource */
    char pad3c[4];
    Float4 bgParam;       /* 0x40 reset to (0,0,0,1) when the background is reloaded */
    Float4 msgParam;      /* 0x50 reset to (0,0,0,1) when the message is reloaded */
    char pad60[0x70 - 0x60];
    char bgCache[0x100];  /* 0x70 name cache of the background */
    char msgCache[0x200]; /* 0x170 name cache of the message */
    char nameBuf[1];      /* 0x370 path buffer, formatted before each load */
};

#endif
