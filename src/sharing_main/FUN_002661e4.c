/* HSTMATCH module=hstp_trans_main.prx start=0x002661e4 end=0x00266224 symbol=FUN_002661e4 lang=c99 */
/* Clone of src/eboot/FUN_00255d34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

#include "hst/cell_grid.h"

/* Sets unk24 of the cell at (row, col) to unk28 + delta, when that cell exists. */
void FUN_002661e4(CellGrid *grid,int row,int col,int delta)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    cell->unk24 = cell->unk28 + delta;
  }
}
