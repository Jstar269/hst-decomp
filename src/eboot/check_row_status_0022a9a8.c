/* HSTMATCH module=EBOOT.BIN start=0x0022a9a8 end=0x0022aae8 symbol=FUN_0022a9a8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane s10170158a1r1-0, hstgen tag a2 origin) restructured by hand: the first branch reads its cells through a static inline Cell3500(idx, j) that re-derives the unfolded row address (int cast keeps +0x3500 and +0x800 separate, row index multiply first), which gives retail's multiply-before-load schedule; exact match verified; names and types await human review. */
extern char *DAT_003415a8;
extern unsigned char *FUN_0022cd60(void);

static inline int Row3500(int idx)
{
    return ((int)(DAT_003415a8 + 0x3500) + 0x800) + idx * 0x14;
}

static inline unsigned char Cell3500(int idx, int j)
{
    int base = Row3500(idx);
    return *(unsigned char *)(base + j);
}

int FUN_0022a9a8(int param_1, int param_2)
{
    int uVar4 = 0;
    if (FUN_0022cd60() != 0 && *(int *)(FUN_0022cd60() + 0x138) == 0) {
        if (Cell3500(param_1, param_2 + 10) > 0 && Cell3500(param_1, param_2) == 0) {
            uVar4 = 1;
        } else if (Cell3500(param_1, param_2 + 5) < Cell3500(param_1, param_2 + 15)) {
            uVar4 = 1;
        }
    } else {
        char *rows = DAT_003415a8 + 0x3d00;
        int base = (int)(rows + param_1 * 0x14);
        unsigned char b = *(unsigned char *)(base + (param_2 + 10));
        if (b > 0 && *(unsigned char *)(base + param_2) == 0) {
            uVar4 = 1;
        } else if (*(unsigned char *)(base + param_2) < 4 && b >= 4) {
            uVar4 = 1;
        }
    }
    return uVar4;
}
