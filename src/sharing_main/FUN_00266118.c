/* HSTMATCH module=hstp_trans_main.prx start=0x00266118 end=0x00266160 symbol=FUN_00266118 lang=c99 */
/* Clone of src/eboot/FUN_00255c68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/cell_grid.h"

extern void FUN_00105470();

/* Calls the cell helper with 1 on the cell at (row, col) when that cell exists. */
void FUN_00266118(CellGrid *grid,int row,int col)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    FUN_00105470(cell,1);
  }
}
