/* Set of seven lazily created slot objects (plus owned helpers) that sits behind one vtable. */
#ifndef HST_MATERIAL_SET_H
#define HST_MATERIAL_SET_H

enum { MATERIAL_SET_SLOTS = 7 };

typedef struct MaterialSet {
    void *vtable;                       /* 0x00 */
    int unk4;                           /* 0x04 */
    int unk8;                           /* 0x08 */
    void *owned;                        /* 0x0c: deleted through its virtual destructor */
    void *res;                          /* 0x10: released with the count-down destructor call */
    int unk14;                          /* 0x14 */
    void *slot[MATERIAL_SET_SLOTS];     /* 0x18: created on demand, null until then */
    int unk34;                          /* 0x34 */
    int unk38;                          /* 0x38 */
    unsigned int unk3c;                 /* 0x3c: starts as the bit pattern of 1.0f */
    unsigned char unk40;                /* 0x40 */
    unsigned char unk41;                /* 0x41 */
    int mode;                           /* 0x44: starts as 2 */
    int unk48;                          /* 0x48 */
} MaterialSet;

#endif
