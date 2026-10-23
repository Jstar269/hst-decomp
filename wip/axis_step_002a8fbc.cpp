/* HSTMATCH module=EBOOT.BIN start=0x002a8fbc end=0x002a9114 symbol=FUN_002a8fbc lang=c++ */
/* near miss: 87/86 words, 15 differ (everything but the last five instructions is exact).
   Analog-stick step: four FUN_001fe080 axis reads, then a left/right/up/down delta update
   guarded by [p+0x103c] and [p+0x30c5], with the clamp limit from an inline min returning a
   reference (`const int &Min(const int &, const int &)` -- that is what makes retail select
   the ADDRESS of p->f30d0 or of DAT_00302be0 and load it) and the second limit from the raw
   p->f30d0. Ghidra is wrong at the tail: the second comparison is `p->f30c8 == p->f30c0`,
   not against the saved f30c8. Source facts that mattered: parameter typed as a struct (raw
   offsets made MWCC build `addiu aN,s2,off; lw` address temps), the two saved values declared
   f30cc first then f30c8 (that is what puts f30cc in a2 and f30c8 in a1), and the `f30c5 == 0`
   wrapper (the `!= 0 { ...; goto }` form gives `beqz` where retail has `bnezl`). Still off:
   our tail loads p->f30c0 twice (once for the compare, once for the call) where retail reuses
   the branch-delay load; hoisting it into a local flips the branch to plain `bne` instead. */
struct Axis {
    char pad0[0x103c];
    unsigned char f103c;
    char pad1[0x30c0 - 0x103d];
    int f30c0;
    char pad2[1];
    unsigned char f30c5;
    char pad3[2];
    int f30c8;
    int f30cc;
    int f30d0;
    int f30d4;
    int f30d8;
    int f30dc;
    int f30e0;
};

extern "C" {
extern int DAT_00302be0;
extern unsigned char FUN_001fe080(int, int, int);
extern void FUN_002a9114(int, int, int);
}

static inline const int &Min(const int &a, const int &b)
{
    return a < b ? a : b;
}

extern "C" void FUN_002a8fbc(int param_1)
{
    Axis *p = (Axis *)param_1;
    int c1;
    int c2;
    int iVar5;
    int iVar7;
    int iVar3;

    c1 = FUN_001fe080((int)&p->f30d4, 0x10, 0x300);
    c2 = FUN_001fe080((int)&p->f30d8, 0x40, 0x300);
    FUN_001fe080((int)&p->f30dc, 0x80, 0x300);
    FUN_001fe080((int)&p->f30e0, 0x20, 0x300);
    iVar7 = p->f30cc;
    iVar5 = p->f30c8;
    if (p->f103c != 0) {
        if (p->f30c5 == 0) {
        if (c1 != 0) {
            if (iVar5 > 0)
                p->f30c8 = iVar5 - 1;
            else if (iVar7 > 0)
                p->f30cc = iVar7 - 1;
        } else if (c2 != 0) {
            if (iVar5 < Min(p->f30d0, DAT_00302be0) - 1)
                p->f30c8 = p->f30c8 + 1;
            else if (iVar7 < p->f30d0 - 5)
                p->f30cc = p->f30cc + 1;
        }
        }
    }
    iVar3 = p->f30cc;
check:
    if (iVar3 == iVar7 && p->f30c8 == p->f30c0)
        return;
    FUN_002a9114(param_1, p->f30c0, 1);
}
// near miss from lane fm6 (unreviewed)
