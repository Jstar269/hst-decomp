/* HSTMATCH module=EBOOT.BIN start=0x001c1efc end=0x001c1f44 symbol=FUN_001c1efc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern signed char DAT_003420de[2][2];

#define TABLE_DIM 2

/* Store value at [row][col] of the 2x2 byte table; out-of-range indices are ignored. */
void FUN_001c1efc(int row, int col, signed char value)
{
  if (row < 0)
    return;
  if (row >= TABLE_DIM)
    return;
  if (col < 0)
    return;
  if (col >= TABLE_DIM)
    return;
  DAT_003420de[row][col] = value;
}
