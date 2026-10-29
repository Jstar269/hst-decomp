/* HSTMATCH module=hstp_trans_main.prx start=0x002661a8 end=0x002661e4 symbol=FUN_002661a8 lang=c99 */
/* Clone of src/eboot/FUN_00255cf8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cell_grid.h"

/* Sets both counters of the cell at (row, col) to value, when that cell exists. */
void FUN_002661a8(CellGrid *grid,int row,int col,u32 value)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    cell->unk24 = value;
    cell->unk28 = value;
  }
}
