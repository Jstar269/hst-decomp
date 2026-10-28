/* HSTMATCH module=EBOOT.BIN start=0x000b33d0 end=0x000b342c symbol=FUN_000b33d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: separated the inner pointer from its loaded value and kept the nested positive range checks; exact match verified; names and types await human review. */

extern int FUN_00093b00();

int FUN_000b33d0(int param_1)
{
  int outer = *(int *)(param_1 + 0x5bc);
  int inner = *(int *)(outer + 0x58);
  int value;
  if (inner != 0) value = *(int *)(inner + 0xf0);
  else value = -1;
  if (value >= 5) {
    if (value < 9) {
      if (FUN_00093b00(outer,0) == 0) return 1;
    }
  }
  return 0;
}
