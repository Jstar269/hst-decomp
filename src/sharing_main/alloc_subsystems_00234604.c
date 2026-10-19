/* HSTMATCH module=hstp_trans_main.prx start=0x00234604 end=0x002347fc symbol=FUN_00234604 lang=c99 */
/* Clone of src/eboot/alloc_subsystems_00225090.c (hstclone.py tag s10181937g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern uint FUN_00000bcc();
extern uint FUN_00196cf4();
extern uint FUN_00229fa8();
extern uint FUN_0022a434();
extern uint FUN_0022a89c();
extern uint FUN_0022a9ec();
extern uint FUN_0022b078();
extern uint FUN_0022eb38();
extern uint FUN_0022fb80();
extern uint FUN_00231c28();
extern uint FUN_00232f60();
extern uint FUN_002339dc();
extern uint FUN_00233f9c();
extern void FUN_002a3198();
extern void FUN_002a47fc(float, uint, int);
extern uint FUN_002a4a08();

extern uint DAT_003f3b50;

typedef struct {
    uint f0;
    uint f1;
    uint f2;
    uint f3;
    uint f4;
    uint f5;
    uint f6;
    uint f7;
    uint f8;
    uint f9;
    uint f10;
    uint f11;
    uint f12;
} Obj;

Obj *FUN_00234604(Obj *p)
{
    uint m;

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
