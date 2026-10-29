/* HSTMATCH module=EBOOT.BIN start=0x0022ad48 end=0x0022ada4 symbol=FUN_0022ad48 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_table.h"

extern SideTable *DAT_003415a8;

/* Returns entry col of array b on the selected side of a table row. */
u8 FUN_0022ad48(int row,int col,int side)
{
  if (side == SIDE_SECOND) {
    return *(unsigned char *)((char *)&DAT_003415a8->rows[0] + row * (int)sizeof(SideRow) + (col + ((int)sizeof(SideEntry) + SIDE_COLS)));
  }
  return *(unsigned char *)((char *)&DAT_003415a8->rows[0] + row * (int)sizeof(SideRow) + (col + SIDE_COLS));
}
