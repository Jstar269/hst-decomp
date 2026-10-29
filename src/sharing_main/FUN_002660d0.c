/* HSTMATCH module=hstp_trans_main.prx start=0x002660d0 end=0x00266118 symbol=FUN_002660d0 lang=c99 */
/* Clone of src/eboot/FUN_00255c20.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cell_grid.h"

extern void FUN_00105470();

/* Calls the cell helper with arg on the cell at (row, col) when that cell exists. */
void FUN_002660d0(CellGrid *grid,int row,int col,u32 arg)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    FUN_00105470(cell,arg);
  }
}
