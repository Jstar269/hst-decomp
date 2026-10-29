/* HSTMATCH module=EBOOT.BIN start=0x00255c20 end=0x00255c68 symbol=FUN_00255c20 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cell_grid.h"

extern void FUN_000ffb3c();

/* Calls the cell helper with arg on the cell at (row, col) when that cell exists. */
void FUN_00255c20(CellGrid *grid,int row,int col,u32 arg)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    FUN_000ffb3c(cell,arg);
  }
}
