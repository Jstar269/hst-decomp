/* HSTMATCH module=EBOOT.BIN start=0x0018b86c end=0x0018b8b8 symbol=FUN_0018b86c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define CELL_ROWS 15
#define CELL_COLS 4

/* Returns 1 when the cell [row][col] of a 15x4 byte table is set; out-of-range cells read as 0. */
int FUN_0018b86c(unsigned char tab[][CELL_COLS], int row, int col)
{
  int r;

  if (0 <= row && row < CELL_ROWS && 0 <= col && col < CELL_COLS)
    r = tab[row][col] != 0;
  else
    r = 0;
  return r;
}
