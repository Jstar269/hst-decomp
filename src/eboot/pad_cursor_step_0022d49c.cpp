/* HSTMATCH module=EBOOT.BIN start=0x0022d49c end=0x0022d67c symbol=FUN_0022d49c lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Pad cursor step: reads four held-direction tests, builds a small range container from
   the pad-state array at +0x374, and turns whichever test kept its value (the container
   keeps only the entries still held when it holds fewer than two) into a +/-1 or +/-10
   step of the cursor at +0x254, or into FUN_0022fcdc when nothing was pressed. The
   early exit reads the same analog byte twice instead of caching it, the "nothing
   pressed" test is written as an OR of the two zero cases, and the four direction
   flags are cleared with one chained assignment - all three are needed for the exact
   match. The 4th argument of FUN_000d5304 is an uninitialised empty tag local whose
   slot is re-read (lb a3,32(sp)). Header end is 0x0022d67c, not the ledger's 0x0022d65c. */


struct False_22d49c {};

struct Vec_22d49c {
    int *p;
    unsigned size;
    unsigned cap;
};

extern "C" {
extern char *DAT_002cfc8c;
extern char DAT_0034179c[];
extern unsigned char FUN_001fe080(int *p, int a, int b);
extern void FUN_000d5304(struct Vec_22d49c *v, int first, int last, False_22d49c unk);
extern void FUN_00054554(struct Vec_22d49c *v, char flag);
extern void FUN_0022fcdc(char *self, int a);
extern void FUN_001b1c44(char *p, int a);
extern int FUN_0015de34(int a, int b, int c);
}

extern "C" void FUN_0022d49c(char *self)
{
    int old;
    struct Vec_22d49c v;
    False_22d49c unk;
    unsigned char f0, f1, f2, f3;
    int cur;

    old = *(int *)(self + 0x254);
    f0 = FUN_001fe080((int *)(self + 0x234), 0x80, 0x300);
    f1 = FUN_001fe080((int *)(self + 0x238), 0x20, 0x300);
    f2 = FUN_001fe080((int *)(self + 0x23c), 0x100, 0);
    f3 = FUN_001fe080((int *)(self + 0x240), 0x200, 0);
    v.p = 0;
    v.size = 0;
    v.cap = 0;
    FUN_000d5304(&v, *(int *)(self + 0x374),
                 *(int *)(self + 0x374) + *(int *)(self + 0x378) * 4, unk);
    if (v.size < 2) {
        f0 = f1 = f2 = f3 = 0;
    }
    (void)0;
    if (f0) {
        *(int *)(self + 0x254) = *(int *)(self + 0x254) - 1;
    } else if (f1) {
        *(int *)(self + 0x254) = *(int *)(self + 0x254) + 1;
    } else if (f2) {
        *(int *)(self + 0x254) = *(int *)(self + 0x254) - 10;
    } else if (f3) {
        *(int *)(self + 0x254) = *(int *)(self + 0x254) + 10;
    } else {
        if (((*(char *)(DAT_002cfc8c + 0x8b) << 28) >> 30) == 0 ||
            ((*(char *)(DAT_002cfc8c + 0x8b) << 26) >> 30) == 0) {
            FUN_0022fcdc(self, 0);
            if (((*(char *)(DAT_002cfc8c + 0x8b) << 26) >> 30) != 0) {
            } else
                FUN_001b1c44(DAT_0034179c, 4);
        } else {
            goto done;
        }
    }
done:
    cur = *(int *)(self + 0x254);
    if (old != cur) {
        FUN_001b1c44(DAT_0034179c, 1);
        *(int *)(self + 0x254) =
            FUN_0015de34(*(int *)(self + 0x21c), *(int *)(self + 0x254), 0);
    }
    FUN_00054554(&v, 0);
}
