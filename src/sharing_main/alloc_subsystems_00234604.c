/* HSTMATCH module=hstp_trans_main.prx start=0x00234604 end=0x002347fc symbol=FUN_00234604 lang=c99 */
/* Clone of src/eboot/alloc_subsystems_00225090.c (hstclone.py tag s10181937g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00000bcc();
extern u32 FUN_00196cf4();
extern u32 FUN_00229fa8();
extern u32 FUN_0022a434();
extern u32 FUN_0022a89c();
extern u32 FUN_0022a9ec();
extern u32 FUN_0022b078();
extern u32 FUN_0022eb38();
extern u32 FUN_0022fb80();
extern u32 FUN_00231c28();
extern u32 FUN_00232f60();
extern u32 FUN_002339dc();
extern u32 FUN_00233f9c();
extern void FUN_002a3198();
extern void FUN_002a47fc(float, u32, int);
extern u32 FUN_002a4a08();

extern u32 DAT_003f3b50;

typedef struct {
    u32 f0;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
    u32 f5;
    u32 f6;
    u32 f7;
    u32 f8;
    u32 f9;
    u32 f10;
    u32 f11;
    u32 f12;
} Obj;

Obj *FUN_00234604(Obj *p)
{
    u32 m;

    p->f0 = 0;
    p->f1 = 0;
    p->f2 = 0;
    p->f3 = 0;
    p->f4 = 0;
    p->f5 = 0;
    p->f6 = 0;
    p->f7 = 0;
    p->f8 = 0;
    p->f9 = 0;
    p->f10 = 0;
    p->f11 = 0;
    p->f12 = 0;

    m = FUN_00000bcc(0x90);
    if (m != 0) m = FUN_0022a434(m);
    p->f0 = m;

    m = FUN_00000bcc(0x60);
    if (m != 0) m = FUN_0022a89c(m);
    p->f1 = m;

    m = FUN_00000bcc(0x19c);
    if (m != 0) m = FUN_0022a9ec(m);
    p->f2 = m;

    m = FUN_00000bcc(0xe8);
    if (m != 0) m = FUN_0022b078(m, 1);
    p->f3 = m;

    m = FUN_00000bcc(0x90);
    if (m != 0) m = FUN_0022eb38(m);
    p->f4 = m;

    m = FUN_00000bcc(0xcc);
    if (m != 0) m = FUN_00231c28(m, 0);
    p->f6 = m;

    m = FUN_00000bcc(0x78);
    if (m != 0) m = FUN_0022fb80(m);
    p->f7 = m;

    m = FUN_00000bcc(0xb4);
    if (m != 0) m = FUN_00232f60(m);
    p->f8 = m;

    m = FUN_00000bcc(0x11c);
    if (m != 0) m = FUN_002339dc(m);
    p->f9 = m;

    m = FUN_00000bcc(8);
    if (m != 0) m = FUN_00229fa8(m);
    p->f10 = m;

    m = FUN_00000bcc(0xc9c);
    if (m != 0) m = FUN_00196cf4(m);
    p->f11 = m;

    m = FUN_00000bcc(0x880);
    if (m != 0) m = FUN_00233f9c(m);
    p->f12 = m;

    if (DAT_003f3b50 != 0) {
        FUN_002a3198(DAT_003f3b50, 1);
        if (FUN_002a4a08(DAT_003f3b50) != 0) {
            FUN_002a47fc(65535.0f, DAT_003f3b50, -1);
        }
    }
    return p;
}
