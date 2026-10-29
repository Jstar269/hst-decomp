/* HSTMATCH module=EBOOT.BIN start=0x00255d34 end=0x00255d74 symbol=FUN_00255d34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

#include "hst/cell_grid.h"

/* Sets unk24 of the cell at (row, col) to unk28 + delta, when that cell exists. */
void FUN_00255d34(CellGrid *grid,int row,int col,int delta)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    cell->unk24 = cell->unk28 + delta;
  }
}
