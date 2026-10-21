/* HSTMATCH module=EBOOT.BIN start=0x001bbd30 end=0x001bbe8c symbol=FUN_001bbd30 lang=c++ */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

extern unsigned DAT_00310fc8;
extern "C" void FUN_002b7d28(void *p);

static inline int Rand() {
    DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
    return (DAT_00310fc8 >> 16) & 0x7fff;
}

extern "C" void FUN_001bbd30(u8 *p, int mode, int flag) {
    if (mode != 0) {
        if (mode == 5) {
            *p = 5;
            return;
        }
        if (mode == 4 && (unsigned)(*p - 4) >= 2) {
            *p = 4;
            if (flag == 0) {
                FUN_002b7d28(p + 4);
            } else {
                u16 v;
                FUN_002b7d28(&v);
                *(u16 *)(p + 4) = v;
                *(s16 *)(p + 6) = Rand() % 12 + 1;
                *(s16 *)(p + 8) = Rand() % 28 + 1;
                *(s16 *)(p + 10) = Rand() % 24;
                *(s16 *)(p + 12) = Rand() % 60;
            }
        }
    } else {
        *p = 0;
    }
}
// NEAR MISS (71 differing words, 87/87 size). Logic matches: mode 0 stores 0, mode 5 stores 5, mode 4 with
// an out-of-range id stores 4 and either calls FUN_002b7d28 on the field or fills four halfwords from the
// inline LCG (`seed = seed*0x343fd + 0x269ec3; (seed>>16)&0x7fff`, then %12+1, %28+1, %24, %60).
// What differs is block layout only: retail treats the mode==5 store as `beql a1,5,end` with the store in
// the delay slot, our build emits `bnel` + `b`. Ruled out: if/else-if chain with early returns, a plain
// chain, a switch, and `if (mode != 0) {...} else {...}` (closest, kept here).
// near miss from lane ds10 (unreviewed)
