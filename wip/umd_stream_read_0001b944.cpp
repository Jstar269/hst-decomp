/* HSTMATCH module=EBOOT.BIN start=0x0001b944 end=0x0001bc3c symbol=FUN_0001b944 lang=c++ */
struct Task {
    char pad[0x28];
    int state;
};
extern "C" {
extern char DAT_002cfb08[];
extern char DAT_002cfb20[];
extern Task *DAT_00338ac4;
extern unsigned DAT_0030ebd0;
extern unsigned char DAT_0030ebd8;
extern int DAT_0030ebdc;
extern unsigned DAT_0030ebe0;
extern int DAT_0030ebe4;
extern unsigned char DAT_0030ab8c;
extern unsigned FUN_002b7cf8(void);
extern void FUN_0001b918(char *);
extern int FUN_000464ec(void);
extern void FUN_000bb190(Task *);
extern void FUN_002b7958(int);
extern int FUN_002b7790(char *, int, int);
extern int FUN_002b77a0(int, long long, int);
extern unsigned FUN_002b7720(int, int, unsigned);
extern int FUN_002b7738(int);

}
static inline void WaitUmd(void)
{
    while ((FUN_002b7cf8() & 0x20) == 0) {
        FUN_0001b918(DAT_002cfb08);
        if (FUN_000464ec()) {
            Task *t = DAT_00338ac4;
            if (t && t->state == 11)
                FUN_000bb190(t);
        }
        FUN_002b7958(1000000);
    }
    FUN_002b7958(100);
}

extern "C" void FUN_0001b944(void)
{
    int fd;
    unsigned n;
    unsigned got;
    while ((fd = FUN_002b7790(DAT_002cfb20, 1, 0)) < 0)
        WaitUmd();
    while (FUN_002b77a0(fd, DAT_0030ebdc, 0) < 0)
        WaitUmd();
    while (DAT_0030ebe0 != 0 && !DAT_0030ebd8) {
    retry:
        WaitUmd();
        DAT_0030ab8c = 1;
        n = DAT_0030ebe0;
        if (n > 64)
            n = 64;
        got = FUN_002b7720(fd, DAT_0030ebe4 + DAT_0030ebd0, n);
        DAT_0030ab8c = 0;
        if (got == n) {
            DAT_0030ebe0 -= got;
            DAT_0030ebdc += got;
            DAT_0030ebd0 += got * 0x800;
        } else {
            FUN_002b7958(1000000);
            goto retry;
        }
    }
    while (FUN_002b7738(fd) < 0)
        FUN_002b7958(1000000);
    if (!DAT_0030ebd8)
        DAT_0030ebd0 = 0x7fffffff;
}
// NEAR ~2 words (69 by position after a one-word shift): retail clamps n with 'sltiu at,s0,65; beqzl at; li s0,64' (branch-likely, li in delay slot).
// Ours emits 'bnez at; nop; li s0,64'. Tried if/else, ternary, >=65, !(n<65), C and C++ modes. Everything else matches.
// near miss from lane ol3 (unreviewed)
