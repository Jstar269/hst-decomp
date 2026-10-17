/* HSTMATCH module=hstp_trans_main.prx start=0x000ad468 end=0x000ad4d8 symbol=FUN_000ad468 lang=c99 */
/* Clone of src/eboot/FUN_000aaa74.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: kept the first scaled float across the second getter and formed the second scaled term directly in the return expression; exact match verified; names and types await human review. */
extern int FUN_000b6e80(int);
float FUN_000ad468(int self) {
  float a = *(float *)(FUN_000b6e80(self) + 0x114) * 0.01f;
  return (a + 1.0f) * -(*(float *)(FUN_000b6e80(self) + 0x24) * 0.01f);
}
