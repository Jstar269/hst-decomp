/* HSTMATCH module=EBOOT.BIN start=0x001fdbb4 end=0x001fdd50 symbol=FUN_001fdbb4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct KeyBits {
    signed char k0 : 2;
    signed char k2 : 2;
    signed char k4 : 2;
    signed char k6 : 2;
} KeyBits;

typedef struct PadState {
    u8 pad[0x89];
    KeyBits f89;
    u8 gap8a;
    KeyBits f8b;
    KeyBits f8c;
} PadState;

extern PadState *DAT_002cfc8c;

typedef struct Obj {
    char pad0[0x40];
    int mode;             /* 0x40 */
    int state;            /* 0x44 */
    char pad48[8];
    int flag50;           /* 0x50 */
    int flag54;           /* 0x54 */
    char pad58[0x6c];     /* 0x58..0xc3 */
    unsigned char flagc4; /* 0xc4 */
    char padc5[3];        /* 0xc5..0xc7 */
    char subc8[0x1188];   /* 0xc8..0x124f */
    char rot[0xf4];       /* 0x1250..0x1343 */
    float angle;          /* 0x1344 */
} Obj;

extern int DAT_0034179c;
extern int FUN_001b1c44();
extern void FUN_00200df0();
extern void FUN_002014d8();
extern void FUN_002021b4(void *p, float delta);

void FUN_001fdbb4(Obj *self)
{
    float a;

    switch (self->mode) {
    case 2:
        if (DAT_002cfc8c->f8b.k4 == 0) {
            FUN_001b1c44((int *)&DAT_0034179c, 4);
            self->state = 6;
        } else if (DAT_002cfc8c->f8b.k2 == 0) {
            if (self->flag50 == 0) {
                FUN_001b1c44((int *)&DAT_0034179c, 4);
                self->state = 6;
            } else {
                FUN_001b1c44((int *)&DAT_0034179c, 3);
                self->state = 7;
            }
        } else if (DAT_002cfc8c->f8b.k0 == 0) {
            if (self->flagc4 != 0) {
                self->flag54 ^= 1;
                FUN_001b1c44((int *)&DAT_0034179c, 6);
                FUN_002014d8(self->subc8);
            }
        } else if (DAT_002cfc8c->f89.k6 == 0 || DAT_002cfc8c->f89.k2 == 0) {
            FUN_001b1c44((int *)&DAT_0034179c, 1);
            self->flag50 ^= 1;
            FUN_00200df0(self->subc8);
        }
        a = self->angle * 0.017453292f;
        if (DAT_002cfc8c->f8c.k6 == 1)
            FUN_002021b4(self->rot, a);
        else if (DAT_002cfc8c->f8c.k2 == 1)
            FUN_002021b4(self->rot, -a);
    }
}
