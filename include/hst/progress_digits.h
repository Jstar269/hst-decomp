/* Progress-bar digit object: a sprite-set host reached through a base pointer, plus per-digit cell values and flags. */
#ifndef HST_PROGRESS_DIGITS_H
#define HST_PROGRESS_DIGITS_H

#include "hst/types.h"

#define PROGRESS_DIGITS_MAX 15       /* most cells one object can hold */
#define PROGRESS_DIGIT_UNSET (-999)  /* value of a cell that has not been read yet */

/* One sprite cell; only the value read by the digit setup is named. */
typedef struct SpriteCell {
    char pad00[0x24];
    int value;                /* 0x24 */
} SpriteCell;

/* Embedded base object holding the sprite cell table. */
typedef struct SpriteHost {
    const void *vtable;       /* 0x00 */
    char pad04[0x10 - 4];
    SpriteCell **cells;       /* 0x10, table of cell pointers */
    int count;                /* 0x14, cells in the table */
    char pad18[0x30 - 0x18];
    char sub30[0x40];         /* 0x30, nested object */
    int unk70;                /* 0x70 */
    int unk74;                /* 0x74 */
    u32 unk78;                /* 0x78 */
    u32 unk7c;                /* 0x7c */
    char sub80[0x40];         /* 0x80, nested object */
    const void *vtablec0;     /* 0xc0 */
    char padc4[0xd0 - 0xc4];
    int unkd0;                /* 0xd0 */
} SpriteHost;

typedef struct ProgressDigits {
    SpriteHost *host;         /* 0x00, points at the embedded base object */
    int first;                /* 0x04, first cell index */
    int stride;               /* 0x08, cells per step (at most PROGRESS_DIGITS_MAX) */
    int count;                /* 0x0c, steps */
    int values[PROGRESS_DIGITS_MAX];  /* 0x10 */
    u8 unk4c[PROGRESS_DIGITS_MAX];    /* 0x4c, set to 1 on construction */
    u8 unk5b[PROGRESS_DIGITS_MAX];    /* 0x5b */
    u8 unk6a[PROGRESS_DIGITS_MAX];    /* 0x6a */
    char pad79[3];
    const void *vtable7c;     /* 0x7c */
    SpriteHost base;          /* 0x80, embedded base object (built only when the in-charge flag is set) */
} ProgressDigits;

#endif
