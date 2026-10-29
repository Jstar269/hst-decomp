/* HSTMATCH module=EBOOT.BIN start=0x00255cb0 end=0x00255cf8 symbol=FUN_00255cb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/cell_grid.h"

extern void FUN_000ffb3c();

/* Calls the cell helper with 0 on the cell at (row, col) when that cell exists. */
void FUN_00255cb0(CellGrid *grid,int row,int col)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    FUN_000ffb3c(cell,0);
  }
}
