/* HSTMATCH module=EBOOT.BIN start=0x0022a9a8 end=0x0022aae8 symbol=FUN_0022a9a8 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane s10170158a1r1-0, hstgen tag a2 origin) restructured by hand: the first branch reads its cells through a static inline Cell3500(idx, j) that re-derives the unfolded row address (int cast keeps +0x3500 and +0x800 separate, row index multiply first), which gives retail's multiply-before-load schedule; exact match verified; names and types await human review. */
#include "hst/side_table.h"

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

/* Returns 1 when, at column col of a row, the second side's a entry is set while the first side's is clear, or
   when the b entries compare in the wanted order (first branch: first side below second side; other branch:
   first side's a entry below 4 while the second side's is 4 or more). */
int FUN_0022a9a8(int row, int col)
{
    int result = 0;
    if (FUN_0022cd60() != 0 && *(int *)(FUN_0022cd60() + 0x138) == 0) {
        if (Cell3500(row, col + SIDE1_A_OFFSET) > 0 && Cell3500(row, col) == 0) {
            result = 1;
        } else if (Cell3500(row, col + SIDE0_B_OFFSET) < Cell3500(row, col + SIDE1_B_OFFSET)) {
            result = 1;
        }
    } else {
        char *rows = DAT_003415a8 + SIDE_TABLE_ROW_OFFSET;
        int base = (int)(rows + row * 0x14);
        unsigned char second = *(unsigned char *)(base + (col + SIDE1_A_OFFSET));
        if (second > 0 && *(unsigned char *)(base + col) == 0) {
            result = 1;
        } else if (*(unsigned char *)(base + col) < 4 && second >= 4) {
            result = 1;
        }
    }
    return result;
}
