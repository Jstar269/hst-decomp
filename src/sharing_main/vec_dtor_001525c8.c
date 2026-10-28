/* HSTMATCH module=hstp_trans_main.prx start=0x001525c8 end=0x0015262c symbol=FUN_001525c8 lang=c99 */
/* Clone of src/eboot/vec_dtor_00146ce0.c (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the delete call (0xa00) takes *param_1 as argument (Ghidra dropped it); exact match verified; names and types await human review. */

extern void FUN_00000a00(void *);
extern void FUN_0015262c();

int * FUN_001525c8(int *param_1,short param_2)
{
  if (param_1 != (int *)0x0) {
    FUN_0015262c(param_1,param_1[1]);
    if (*param_1 != 0) {
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
