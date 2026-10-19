/* HSTMATCH module=EBOOT.BIN start=0x00225090 end=0x00225288 symbol=FUN_00225090 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern uint FUN_00000bcc();
extern uint FUN_0018a5a8();
extern uint FUN_0021aa34();
extern uint FUN_0021aec0();
extern uint FUN_0021b328();
extern uint FUN_0021b478();
extern uint FUN_0021bb04();
extern uint FUN_0021f5c4();
extern uint FUN_0022060c();
extern uint FUN_002226b4();
extern uint FUN_002239ec();
extern uint FUN_00224468();
extern uint FUN_00224a28();
extern void FUN_00291b8c();
extern void FUN_002931f0(float, uint, int);
extern uint FUN_002933fc();

extern uint DAT_0034a820;

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

Obj *FUN_00225090(Obj *p)
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
    if (m != 0) m = FUN_0021aec0(m);
    p->f0 = m;

    m = FUN_00000bcc(0x60);
    if (m != 0) m = FUN_0021b328(m);
    p->f1 = m;

    m = FUN_00000bcc(0x19c);
    if (m != 0) m = FUN_0021b478(m);
    p->f2 = m;

    m = FUN_00000bcc(0xe8);
    if (m != 0) m = FUN_0021bb04(m, 1);
    p->f3 = m;

    m = FUN_00000bcc(0x90);
    if (m != 0) m = FUN_0021f5c4(m);
    p->f4 = m;

    m = FUN_00000bcc(0xcc);
    if (m != 0) m = FUN_002226b4(m, 0);
    p->f6 = m;

    m = FUN_00000bcc(0x78);
    if (m != 0) m = FUN_0022060c(m);
    p->f7 = m;

    m = FUN_00000bcc(0xb4);
    if (m != 0) m = FUN_002239ec(m);
    p->f8 = m;

    m = FUN_00000bcc(0x11c);
    if (m != 0) m = FUN_00224468(m);
    p->f9 = m;

    m = FUN_00000bcc(8);
    if (m != 0) m = FUN_0021aa34(m);
    p->f10 = m;

    m = FUN_00000bcc(0xc9c);
    if (m != 0) m = FUN_0018a5a8(m);
    p->f11 = m;

    m = FUN_00000bcc(0x880);
    if (m != 0) m = FUN_00224a28(m);
    p->f12 = m;

    if (DAT_0034a820 != 0) {
        FUN_00291b8c(DAT_0034a820, 1);
        if (FUN_002933fc(DAT_0034a820) != 0) {
            FUN_002931f0(65535.0f, DAT_0034a820, -1);
        }
    }
    return p;
}
