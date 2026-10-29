/* Instance object of the 0x1b7000 sources: two linked lists, a parameter block, a countdown and a target. */
#ifndef HST_INST_OBJ_H
#define HST_INST_OBJ_H

#include "hst/types.h"
#include "hst/list_head.h"

/* Target record referenced by InstObj (only the named fields are used). */
typedef struct InstTarget {
    char pad00[4];
    int unk4;               /* 0x04 */
    char pad08[8];
    float vec[4];           /* 0x10 */
} InstTarget;

typedef struct InstObj {
    char pad00[0x3c];
    DListHead list3c;       /* 0x3c */
    char pad48[0x58 - 0x48];
    int unk58;              /* 0x58 */
    char pad5c[0x68 - 0x5c];
    int unk68;              /* 0x68 */
    int countdown;          /* 0x6c frames left, decremented while running */
    u8 ramp_mode;           /* 0x70 */
    u8 unk71;               /* 0x71 */
    char pad72[2];
    InstTarget *target;     /* 0x74 */
    u8 unk78;               /* 0x78 */
    char pad79[0x90 - 0x79];
    u8 unk90;               /* 0x90 */
    char pad91[2];
    u8 unk93;               /* 0x93 */
    char pad94[0xf0 - 0x94];
    DListHead listf0;       /* 0xf0 */
} InstObj;

#endif
