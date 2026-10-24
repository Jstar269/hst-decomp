/* HSTMATCH module=EBOOT.BIN start=0x001b64fc end=0x001b66bc symbol=FUN_001b64fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the inline Clamp takes the value by const reference too (a by-value argument is loaded before the first lo load), and the switch cases are written 0x2a, 0x44, 0x35 (tests are emitted in reverse source order). */

extern "C" {
extern int DAT_0034a678;
extern int DAT_002e99cc;
extern int DAT_002e99d0;
extern char DAT_00341c50;
extern char DAT_00341c51;
extern unsigned char DAT_003386b8;
extern int DAT_003417c4;
extern int DAT_00341ccc;
extern char DAT_0034179c;
void FUN_001b38dc(void *p, int v);
void FUN_001b3bac(void *p, int a, int b);
void FUN_001b4dfc(int v);
unsigned char FUN_0022c860(void);
unsigned char FUN_0022c878(void);
}

struct Obj {
    char pad0[0x4c];
    int i4c;
    int i50;
    int i54;
    int i58;
    char pad1[0x64 - 0x5c];
    int i64;
    char pad2[0x80 - 0x68];
    int i80;
    char pad3[0x90 - 0x84];
    unsigned char b90;
    unsigned char b91;
    unsigned char b92;
    unsigned char b93;
    unsigned char b94;
};

inline int Clamp(const char &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001b64fc(Obj *o)
{
    int mode;
    int idx;
    int cnt;
    o->b90 = 0;
    o->b91 = 0;
    o->b92 = 0;
    o->b93 = 0;
    o->b94 = 0;
    mode = 0;
    switch (DAT_0034a678) {
    case 0x2a:
        o->b90 = 1;
        o->b93 = FUN_0022c860();
        o->b94 = FUN_0022c878();
        if (o->b93 != 0) {
            mode = 2;
        } else if (o->b94 != 0) {
            mode = 1;
        }
        break;
    case 0x44:
        o->b91 = 1;
        mode = 3;
        break;
    case 0x35:
        o->b92 = 1;
        break;
    }
    FUN_001b38dc(&DAT_0034179c, mode);
    idx = DAT_00341c50;
    cnt = (char)Clamp(DAT_00341c51, DAT_002e99cc, DAT_002e99d0);
    if (DAT_003386b8 != 0) {
        cnt = 0;
        FUN_001b4dfc(DAT_003417c4);
    } else {
        if (o->b93 != 0 || o->b94 != 0) {
            cnt = 1;
        } else if (*(char *)(idx + DAT_00341ccc + 0x104a) < 5) {
            cnt = 1;
        }
    }
    FUN_001b3bac(&DAT_0034179c, idx, cnt);
    o->i4c = -1;
    o->i50 = -1;
    o->i54 = -1;
    o->i58 = -1;
    o->i64 = -1;
    o->i80 = 0;
}
