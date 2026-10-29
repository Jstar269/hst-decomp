/* Large polymorphic host object: sub-object layout used by its destructor (FUN_001407f0) and transform upload (FUN_00140acc). */
#ifndef HST_XFORM_HOST_H
#define HST_XFORM_HOST_H

#include "hst/types.h"

/* Per-entry record: two 16-byte blocks handed to the setup calls. */
typedef struct XformEntry {
    char unk00[0x10];
    char unk10[0x10];
} XformEntry;

typedef struct XformHost {
    const void *vtable;         /* 0x00 */
    char pad04[0x10 - 0x04];
    char sub10[12];             /* 0x10, destroyed by FUN_001466dc */
    char sub1c[12];             /* 0x1c, destroyed by FUN_001466dc */
    char sub28[12];             /* 0x28, destroyed by FUN_00146788 */
    char sub34[12];             /* 0x34, destroyed by FUN_0005f688 */
    char arr40[6][12];          /* 0x40, destroyed by FUN_00132390 */
    char arr88[6][12];          /* 0x88, destroyed by FUN_00140770 */
    char arrd0[6][12];          /* 0xd0, destroyed by FUN_00132390 */
    char sub118[12];            /* 0x118, destroyed by FUN_001468e4 */
    char sub124[12];            /* 0x124, destroyed by FUN_001468e4 */
    char sub130[12];            /* 0x130, destroyed by FUN_001468e4 */
    char sub13c[12];            /* 0x13c, destroyed by FUN_001468e4 */
    char sub148[12];            /* 0x148, destroyed by FUN_001468e4 */
    char sub154[12];            /* 0x154, destroyed by FUN_00146990 */
    char sub160[0x7a4 - 0x160]; /* 0x160, destroyed by FUN_00049350 (arg -1) */
    char sub7a4[12];            /* 0x7a4, destroyed by FUN_00146adc */
    char sub7b0[12];            /* 0x7b0, destroyed by FUN_000e88e4 */
    char sub7bc[0x8c8 - 0x7bc]; /* 0x7bc, destroyed by FUN_00146ce0 */
    char sub8c8[12];            /* 0x8c8, destroyed by FUN_00147188 */
    char sub8d4[12];            /* 0x8d4, destroyed by FUN_001472c8 */
    char sub8e0[0x9ec - 0x8e0]; /* 0x8e0, destroyed by FUN_00147384 */
    char sub9ec[0xaf8 - 0x9ec]; /* 0x9ec, destroyed by FUN_001474d0 */
    char subaf8[0xc04 - 0xaf8]; /* 0xaf8, destroyed by FUN_001474d0 */
    char subc04[0xd10 - 0xc04]; /* 0xc04, destroyed by FUN_001474d0 */
    XformEntry *entries;        /* 0xd10, dynamic array released by FUN_0014757c */
    int entryCount;             /* 0xd14, read both signed and unsigned by FUN_00140acc */
    char padd18[0xdf0 - 0xd18];
    char unkdf0[0x10];          /* 0xdf0 */
    float unke00[4];            /* 0xe00 */
    char unke10[0x10];          /* 0xe10 */
    float unke20[4];            /* 0xe20 */
    char unke30[0x10];          /* 0xe30 */
    char unke40[0x10];          /* 0xe40 */
    float unke50[4];            /* 0xe50, copy of unke00 */
    char unke60[0x10];          /* 0xe60 */
    float unke70[4];            /* 0xe70, copy of unke20 */
    char unke80[0x10];          /* 0xe80 */
    char unke90[0x10];          /* 0xe90 */
    float unkea0[4];            /* 0xea0, copy of unke00 */
    char unkeb0[0x10];          /* 0xeb0 */
    float unkec0[4];            /* 0xec0, copy of unke20 */
    char unked0[0x10];          /* 0xed0 */
    char padee0[0x12e0 - 0xee0];
    float unk12e0[4];           /* 0x12e0 */
    float unk12f0[3];           /* 0x12f0 */
} XformHost;

#endif
