/* HSTMATCH module=EBOOT.BIN start=0x0022acf0 end=0x0022ad48 symbol=FUN_0022acf0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_table.h"

extern SideTable *DAT_003415a8;

/* Returns entry col of array a on the selected side of a table row. */
u8 FUN_0022acf0(int row,int col,int side)
{
  if (side == SIDE_SECOND) {
    return *(unsigned char *)((char *)&DAT_003415a8->rows[0] + row * (int)sizeof(SideRow) + (col + (int)sizeof(SideEntry)));
  }
  return *(unsigned char *)((char *)&DAT_003415a8->rows[0] + row * (int)sizeof(SideRow) + col);
}
