/* HSTMATCH module=hstp_trans_main.prx start=0x001c41bc end=0x001c437c symbol=FUN_001c41bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the inline Clamp takes the value by const reference too (a by-value argument is loaded before the first lo load), and the switch cases are written 0x2a, 0x44, 0x35 (tests are emitted in reverse source order). */
extern "C" {
extern int DAT_003f39a8;
extern int DAT_00391588;
extern int DAT_0039158c;
extern char DAT_003eaf88;
extern char DAT_003eaf89;
extern unsigned char DAT_003e19f8;
extern int DAT_003eb004;
extern int DAT_003eaafc;
extern char DAT_003eaad8;
void FUN_001c1d6c(void *p, int v);
void FUN_001c1f3c(void *p, int a, int b);
void FUN_001c2a10(int v);
unsigned char FUN_0023c334(void);
unsigned char FUN_0023c34c(void);
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

extern "C" void FUN_001c41bc(Obj *o)
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
    switch (DAT_003f39a8) {
    case 0x2a:
        o->b90 = 1;
        o->b93 = FUN_0023c334();
        o->b94 = FUN_0023c34c();
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
    FUN_001c1d6c(&DAT_003eaad8, mode);
    idx = DAT_003eaf88;
    cnt = (char)Clamp(DAT_003eaf89, DAT_00391588, DAT_0039158c);
    if (DAT_003e19f8 != 0) {
        cnt = 0;
        FUN_001c2a10(DAT_003eaafc);
    } else {
        if (o->b93 != 0 || o->b94 != 0) {
            cnt = 1;
        } else if (*(char *)(idx + DAT_003eb004 + 0x104a) < 5) {
            cnt = 1;
        }
    }
    FUN_001c1f3c(&DAT_003eaad8, idx, cnt);
    o->i4c = -1;
    o->i50 = -1;
    o->i54 = -1;
    o->i58 = -1;
    o->i64 = -1;
    o->i80 = 0;
}
