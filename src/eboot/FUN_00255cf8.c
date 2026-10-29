/* HSTMATCH module=EBOOT.BIN start=0x00255cf8 end=0x00255d34 symbol=FUN_00255cf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cell_grid.h"

/* Sets both counters of the cell at (row, col) to value, when that cell exists. */
void FUN_00255cf8(CellGrid *grid,int row,int col,u32 value)
{
  GridCell *cell;
  
  cell = grid->rows[row].cells[col];
  if (cell != 0) {
    cell->unk24 = value;
    cell->unk28 = value;
  }
}
