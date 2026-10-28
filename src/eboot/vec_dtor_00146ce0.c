/* HSTMATCH module=EBOOT.BIN start=0x00146ce0 end=0x00146d44 symbol=FUN_00146ce0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the delete call (0xa00) takes *param_1 as argument (Ghidra dropped it); exact match verified; names and types await human review. */

extern void FUN_00000a00(void *);
extern void FUN_00146d44();

int * FUN_00146ce0(int *param_1,short param_2)
{
  if (param_1 != (int *)0x0) {
    FUN_00146d44(param_1,param_1[1]);
    if (*param_1 != 0) {
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
