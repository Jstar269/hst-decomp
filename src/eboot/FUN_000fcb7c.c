/* HSTMATCH module=EBOOT.BIN start=0x000fcb7c end=0x000fcbe4 symbol=FUN_000fcb7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the object typed unsigned char * and the tested member passed to the free call (Ghidra dropped the argument); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_000104e0();

unsigned char * FUN_000fcb7c(unsigned char *param_1,short param_2)
{
  if (param_1 != (unsigned char *)0x0) {
    if ((*param_1 != '\0') && (*(int *)(param_1 + 4) != 0)) {
      FUN_000104e0(*(int *)(param_1 + 4));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
