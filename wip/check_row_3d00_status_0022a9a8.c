/* HSTMATCH module=EBOOT.BIN start=0x0022a9a8 end=0x0022aae8 symbol=FUN_0022a9a8 lang=c99 */
/* Derived from: try/gen-a2/v0/FUN_0022a9a8.c (tag: a2) */
extern char *DAT_003415a8;
extern unsigned char *FUN_0022cd60(void);

static inline char *GetRow3d00(int idx)
{
    int off = idx * 0x14;
    return (char *)(((int)(DAT_003415a8 + 0x3500) + 0x800) + off);
}

int FUN_0022a9a8(int param_1, int param_2)
{
    int uVar4 = 0;
    if (FUN_0022cd60() != 0 && *(int *)(FUN_0022cd60() + 0x138) == 0) {
        int base = (int)GetRow3d00(param_1);
        if (*(unsigned char *)(base + (param_2 + 10)) > 0 && *(unsigned char *)(base + param_2) == 0) {
            uVar4 = 1;
        } else if (*(unsigned char *)(base + (param_2 + 5)) < *(unsigned char *)(base + (param_2 + 15))) {
            uVar4 = 1;
        }
    } else {
        int base = param_1 * 0x14 + (int)DAT_003415a8 + 0x3d00;
        unsigned char b = *(unsigned char *)(base + (param_2 + 10));
        if (b > 0 && *(unsigned char *)(base + param_2) == 0) {
            uVar4 = 1;
        } else if (*(unsigned char *)(base + param_2) < 4 && b >= 4) {
            uVar4 = 1;
        }
    }
    return uVar4;
}

// 80/80 words; 9 words differ at +0x40..+0x60 (instruction scheduling in the first branch):
// - Retail computes `param_1 * 0x14` (`sll/addu/sll a0,v0,2`) before loading `DAT_003415a8`
//   and adding `+0x3500` then `+0x800` via two separate `addiu` instructions (`(int)(DAT_003415a8 + 0x3500) + 0x800`).
// - With the `+0x3500` / `+0x800` pointer-cast split, `mwccpsp` schedules `lui/lw` of `DAT_003415a8`
//   before the `sll/addu/sll` multiply; folding `+0x3d00` schedules `sll/addu/sll a0,v0,2` first
//   (matching instruction order everywhere else) but is 1 word shorter (79/80 words).
// - Ruled out: C99 vs C++ mode, struct-array indexing (`Row20`), nested inline helpers, and local temp ordering.
// near miss from lane s10170158a1r1-0 (unreviewed)
