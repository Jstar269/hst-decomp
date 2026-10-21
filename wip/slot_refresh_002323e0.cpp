/* HSTMATCH module=EBOOT.BIN start=0x002323e0 end=0x00232558 symbol=FUN_002323e0 lang=c++ */
extern char *DAT_003415a8;
extern int DAT_002f3668;
extern "C" bool FUN_0022c928(int);
extern "C" bool FUN_0022c988(int);
extern "C" bool FUN_0022c8b4(int);
extern "C" bool FUN_0022c1f4(int);

struct Slots {
    char pad[0x200];
    int f200[10];
    int f228[10];
    int f250[10];
    int f278[10];
};

extern "C" void FUN_002323e0(Slots *self) {
    char *tab = DAT_003415a8 + 13568;
    int last = DAT_002f3668 - 1;
    for (int i = 0; i < 10; i++) {
        self->f228[i] = 0;
        unsigned char flag = 0;
        if (i == 8 && FUN_0022c928(7)) flag = !FUN_0022c988(8);
        unsigned char lastFlag = (i == last) | flag;
        if (!FUN_0022c8b4(i)) {
            self->f200[i] = 0;
        } else if (!lastFlag) {
            self->f200[i] = 0;
        } else if (FUN_0022c1f4(i)) {
            self->f200[i] = 1;
        } else if (FUN_0022c988(i)) {
            self->f200[i] = 2;
        } else if (self->f228[i] < 100) {
            self->f200[i] = 3;
        } else {
            self->f200[i] = 5;
        }
        if (i != 0 && self->f200[i] == 2 && (tab[i + 36096] & 0x80) == 0) {
            self->f200[i] = 4;
        }
        self->f250[i] = 0;
        self->f278[i] = 0;
    }
}
// NEAR 1 word (93/94). Structure, calls and the four int[10] arrays at 0x200/0x228/0x250/0x278 all match.
// Retail keeps the `(i == lastIndex)` result materialised as 0/1 in s0 across the 0x22c928 call
// (`sltu s0,zero,v1` in the beqz delay) and then merges it with the flag as bytes
// (`andi v0,s0,0xff; or v0,v0,v1; sltu s0,zero,v0`); MWCC here keeps lastIndex in s0 and re-derives
// `i == lastIndex` twice with `xor`, and parks the flag in an extra saved register s4 (5 saved regs vs 4).
// Ruled out: `unsigned char` locals (extra s4), named `bool eight/bool lastFlag` (induction variable moves to s4),
// and `extern char DAT[]` vs `extern char *DAT` for the 0x3415a8 global (it is a pointer, `lw` + `addiu`).
// near miss from lane ds10 (unreviewed)
