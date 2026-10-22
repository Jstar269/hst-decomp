/* HSTMATCH module=EBOOT.BIN start=0x0008d9ac end=0x0008d9f8 symbol=FUN_0008d9ac lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x0008d9ac.c, no hstgen tag) corrected by hand: the float store through char-pointer arithmetic and the returned pointer as an address; exact match verified; names and types await human review. */
extern char DAT_002d2780;
extern char DAT_002d277c;
extern char DAT_0034179c;
extern float FUN_001b2ad8(int, int);

int FUN_0008d9ac(int param_1)
{
  *(float *)(&DAT_002d2780 + param_1 * 8) = FUN_001b2ad8((int)&DAT_0034179c, param_1);
  return (int)&DAT_002d277c + param_1 * 8;
}
