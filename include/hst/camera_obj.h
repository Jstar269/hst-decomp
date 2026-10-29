/* Camera object: sub-objects, mode state, source object and the blend factor. */
#ifndef HST_CAMERA_OBJ_H
#define HST_CAMERA_OBJ_H

#include "hst/types.h"

struct CameraSource;

/* Camera mode, selected by CameraObj::state. */
enum {
    CAM_STATE_QUERY_MANAGER = 0, /* ask the manager object for the target */
    CAM_STATE_FOLLOW = 1,        /* also the default */
    CAM_STATE_FROM_SOURCE = 2,   /* take the basis from the source object */
    CAM_STATE_BLEND = 3          /* blend towards the source over several frames */
};

typedef struct CameraObj {
    const void *vtable;       /* 0x00 */
    char pad04[0x38];
    int unk3c;                /* 0x3c */
    int unk40;                /* 0x40, -1 when unset */
    int unk44;                /* 0x44 */
    int unk48;                /* 0x48 */
    u8 unk4c;                 /* 0x4c */
    char pad4d[3];
    float unk50[11];          /* 0x50 all start at 1.0 */
    void *parts[3];           /* 0x7c owned sub-objects, registered with the base object */
    int unk88;                /* 0x88 */
    int unk8c;                /* 0x8c */
    int unk90;                /* 0x90 */
    char pad94[0xc];
    int unka0;                /* 0xa0 */
    int unka4;                /* 0xa4 */
    int unka8;                /* 0xa8 */
    float unkac;              /* 0xac starts at 1.0 */
    int unkb0;                /* 0xb0 */
    int unkb4;                /* 0xb4 */
    char padb8[8];
    int unkc0;                /* 0xc0 */
    int unkc4;                /* 0xc4 */
    int unkc8;                /* 0xc8 */
    float unkcc;              /* 0xcc starts at 1.0 */
    int unkd0;                /* 0xd0 */
    char padd4[0xc];
    int unke0;                /* 0xe0 */
    int unke4;                /* 0xe4 */
    int unke8;                /* 0xe8 */
    float unkec;              /* 0xec starts at 1.0 */
    int state;                /* 0xf0 CAM_STATE_*; the constructor stores it byte by byte */
    int unkf4;                /* 0xf4 */
    struct CameraSource *src; /* 0xf8 */
    int unkfc;                /* 0xfc */
    int unk100;               /* 0x100 start of a 0x140-byte block handed to the key interpolation */
    char pad104[0xc];
    int unk110;               /* 0x110 */
    int unk114;               /* 0x114 */
    int unk118;               /* 0x118 */
    float unk11c;             /* 0x11c starts at 1.0 */
    int unk120;               /* 0x120, -1 when unset */
    int unk124;               /* 0x124, -1 when unset */
    int unk128;               /* 0x128 */
    int unk12c;               /* 0x12c */
    int unk130;               /* 0x130 */
    u8 unk134;                /* 0x134 */
    char pad135[0x240 - 0x135];
    float t;                  /* 0x240 blend factor, 0..1 */
} CameraObj;

#endif
