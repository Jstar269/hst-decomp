/* HSTMATCH module=EBOOT.BIN start=0x000aaa74 end=0x000aaae4 symbol=FUN_000aaa74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: kept the first scaled float across the second getter and formed the second scaled term directly in the return expression; exact match verified; names and types await human review. */
extern int FUN_000b3c68(int);
float FUN_000aaa74(int self) {
  float a = *(float *)(FUN_000b3c68(self) + 0x114) * 0.01f;
  return (a + 1.0f) * -(*(float *)(FUN_000b3c68(self) + 0x24) * 0.01f);
}
