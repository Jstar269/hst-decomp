/* HSTMATCH module=EBOOT.BIN start=0x0022aae8 end=0x0022ab44 symbol=FUN_0022aae8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0022aae8.c) corrected by hand: C++ with an inline row-address helper; readability pass; exact match verified; names and types await human review. */
#include "hst/side_table.h"

extern char *DAT_003415a8;

/* matching idiom: the row base is built with the scaled index first, as (char *)(i * 0x14) + (int)base + 0x3d00 */
static inline char *Row(int i) { return (char *)(i * (int)sizeof(SideRow)) + (int)DAT_003415a8 + SIDE_TABLE_ROW_OFFSET; }

/* Stores a_value and b_value at column col of the two arrays on the selected side of a table row. */
extern "C" void FUN_0022aae8(int row, unsigned char a_value, unsigned char b_value, int col, int side)
{
    int a_off;
    int b_off;
    if (side == SIDE_SECOND) { a_off = SIDE1_A_OFFSET; b_off = SIDE1_B_OFFSET; } else { a_off = SIDE0_A_OFFSET; b_off = SIDE0_B_OFFSET; }
    *(unsigned char *)((a_off + col) + Row(row)) = a_value;
    *(unsigned char *)((b_off + col) + Row(row)) = b_value;
}
