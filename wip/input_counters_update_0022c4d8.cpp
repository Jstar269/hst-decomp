/* HSTMATCH module=EBOOT.BIN start=0x0022c4d8 end=0x0022c834 symbol=FUN_0022c4d8 lang=c++ */
extern char *DAT_003415a8;
extern unsigned char DAT_003417cc;
extern int DAT_00341c50;
extern signed char DAT_00341d7d;
extern short DAT_003417d0;
extern int DAT_002f2bd0;
struct Ent {
    char pad[0x138];
    int f138;
};
extern "C" Ent *FUN_0022cd60();

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
static inline int Sign(bool b) { return b ? 1 : -1; }

extern "C" void FUN_0022c4d8(int a, int b)
{
    *(unsigned char *)(DAT_003415a8 + 0xe04d) = 1;
    int *p1 = (int *)(DAT_003415a8 + 0xe044);
    *p1 = Max(a, *p1);
    int *p2 = (int *)(DAT_003415a8 + 0xe048);
    *p2 = Max(b, *p2);
    unsigned char flag = 0;
    if (FUN_0022cd60() != 0 && FUN_0022cd60()->f138 == 0) {
        flag = 1;
    }
    *(unsigned char *)(DAT_003415a8 + 0xe04e) = flag;
    bool inRange = false;
    if (2 < a && a < 6) {
        inRange = true;
    }
    int *pc = (int *)(DAT_003415a8 + 0xd4d0);
    int c = *pc;
    if (c <= 0) {
        if (c < 0) {
            if (Sign(inRange) < 0) {
                c = c + Sign(inRange);
            } else {
                c = Sign(inRange);
            }
            *pc = c;
        } else {
            *pc = Sign(inRange);
        }
    } else {
        if (Sign(inRange) <= 0) {
            c = Sign(inRange);
        } else {
            c = c + Sign(inRange);
        }
        *pc = c;
    }
    *(unsigned *)(DAT_003415a8 + 0xd4d8) = DAT_003417cc;
    *(int *)(DAT_003415a8 + 0xd4dc) = DAT_00341c50;
    int k = DAT_00341d7d;
    if (k >= 0 && k < 15) {
        char *q = DAT_003415a8 + k * 2;
        int v = *(short *)(q + 0xd4e6);
        if (v < 0) {
            v += 1;
        }
        *(short *)(q + 0xd4e6) = (short)(v >> 1);
    }
    int n = 0;
    int off = 0;
    do {
        short *ps = (short *)(DAT_003415a8 + off + 0xd4e6);
        int v = *ps + 1;
        short r = (short)DAT_002f2bd0;
        if (DAT_002f2bd0 <= v) {
            if (200 < v) {
                v = 200;
            }
            r = (short)v;
        }
        n++;
        *ps = r;
        off += 2;
    } while (n < 15);
    {
        char *q = DAT_003415a8 + DAT_003417d0 * 2;
        *(short *)(q + 0xd4e6) = 0;
    }
    {
        char *b = DAT_003415a8;
        if ((*(unsigned short *)(b + 0xd504) & 1) != 0) {
            *(short *)(b + 0xd4e4) = *(short *)(b + 0xd4e4) + 1;
        }
    }
    {
        char *b = DAT_003415a8;
        *(unsigned short *)(b + 0xd504) = *(unsigned short *)(b + 0xd504) & 0xfffe;
    }
    {
        char *b = DAT_003415a8;
        *(unsigned short *)(b + 0xd504) = *(unsigned short *)(b + 0xd504) & 0xfffd;
    }
    *(int *)(DAT_003415a8 + 0xd4e0) = 0;
}
// lane sn6: 207/215 words, shift-tolerant ~100; first pass with the address-form findings. Semantics: Env at DAT_003415a8 (char* base; offsets above 0x7fff). a/b (the two params) are stored to
// sp+24/28 (const-ref Max: `*p = Max(a, *p)` -> `slt at,a,*p; beqzl; addiu v0,sp,24`), e04d = 1, e04e = (FUN_0022cd60() && FUN_0022cd60()->f138 == 0), inRange = 2 < a && a < 6, signed run counter at
// +0xd4d0 (c > 0: s > 0 ? c + s : s; c < 0: s < 0 ? c + s : s; else s with s = inRange ? 1 : -1), d4d8 = (unsigned)DAT_003417cc, d4dc = DAT_00341c50, a 15-entry short table at +0xd4e6 (entry
// DAT_00341d7d, if 0..14, is halved toward zero; every entry is incremented and clamped to [DAT_002f2bd0, 200]; entry [DAT_003417d0] = 0), +0xd504 bit 0 -> +0xd4e4++, then bits 0 and 1 cleared,
// +0xd4e0 = 0.
// Address forms found: constant-offset accesses through a `char *` base give the retail `lui v1,1; addu v1,base,v1; sh x,-11034(v1)`; computing `char *q = base + idx*2;` first and accessing
// `*(short *)(q + 0xd4e6)` twice keeps that form for the load AND the store (the first table update is exact in the address part); the loop uses a `short *ps` pointer (`addiu 21742; addiu 32760`)
// with separate counter and byte offset (n, off); an int-typed base (Ghidra's _DAT_003415a8) gives lwr/lwl and `addiu 32767` chains instead.
// Open: the Sign() chain (retail evaluates `s ? 1 : -1` as `beqzl a2,L; li v1,-1; li v1,1` separately per use and ours folds), `lb` for DAT_00341d7d, the `s0` flag register for e04e
// (`move s0,zero ... li s0,1` with `bnez v1`), and the d504 statements (retail reloads the base for each access of the three statements and keeps a lui form).
// near miss from lane sn6 (unreviewed)
