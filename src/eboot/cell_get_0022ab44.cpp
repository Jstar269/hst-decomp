/* HSTMATCH module=EBOOT.BIN start=0x0022ab44 end=0x0022abdc symbol=FUN_0022ab44 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag fm3 wip near miss) corrected by hand: rewritten with a typed table struct (0x3d00 pad, 20-byte rows); readability pass, full prototype for FUN_0022a9a8 (args passed on), and the column+10 kept in a local; exact match verified; names and types await human review. */
#include "hst/side_table.h"

/* Table rows as flat bytes (the four five-byte arrays of SideRow). */
struct FlatRow { unsigned char cell[sizeof(SideRow)]; };
struct FlatTable { char pad[SIDE_TABLE_ROW_OFFSET]; FlatRow rows[1]; };
extern FlatTable *DAT_003415a8;
extern "C" int FUN_0022a9a8(int, int);

/* Returns the a entry of a table row at column col, from the second side when the status helper returns 1 (the
   status is also stored through status_out when it is not null). */
extern "C" unsigned char FUN_0022ab44(int row, int col, int *status_out)
{
    int status = FUN_0022a9a8(row, col);
    if (status_out != 0) {
        *status_out = status;
    }
    if (status == SIDE_SECOND) {
        int col2 = col + SIDE1_A_OFFSET;
        return DAT_003415a8->rows[row].cell[col2];
    }
    return DAT_003415a8->rows[row].cell[col];
}
