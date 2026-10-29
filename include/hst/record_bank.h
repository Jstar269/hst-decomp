/* Root object whose owner holds two record banks (selected by a flag of the ad-hoc service object). */
#ifndef HST_RECORD_BANK_H
#define HST_RECORD_BANK_H

#include "hst/types.h"

/* Number of banks and the size of one. */
#define RECORD_BANK_COUNT 2
#define RECORD_BANK_SIZE 0x458

typedef struct RecordBank {
    char pad00[0x12d];
    u8 unk12d;               /* 0x12d nonzero when the bank is in use */
    char pad12e[0x3b0 - 0x12e];
    int unk3b0;              /* 0x3b0 */
    int unk3b4;              /* 0x3b4 */
    char pad3b8[8];
    int unk3c0;              /* 0x3c0 */
    int unk3c4;              /* 0x3c4 */
    char pad3c8[RECORD_BANK_SIZE - 0x3c8];
} RecordBank;

typedef struct RecordOwner {
    char pad00[0x1aa0];
    RecordBank banks[RECORD_BANK_COUNT];  /* 0x1aa0 */
} RecordOwner;

typedef struct RecordRoot {
    char pad00[0x40];
    RecordOwner *owner;      /* 0x40 */
} RecordRoot;

#endif
