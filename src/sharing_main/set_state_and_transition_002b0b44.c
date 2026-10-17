/* HSTMATCH module=hstp_trans_main.prx start=0x002b0b44 end=0x002b0bec symbol=FUN_002b0b44 lang=c99 */
/* Clone of src/eboot/set_state_and_transition_002a1738.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: corrected callee prototype argument orders for float parameters; exact match verified; names and types await human review. */
extern void FUN_00058814(void *self, float f1, int a, int b, float f2, float f3);
extern void FUN_000587ac(void *self, int a, int b, float f);
extern void FUN_002b07a4(void *self, int a, int b);
extern void FUN_00059ac0(void *self, int a, int b);
extern void FUN_00059ba8(float f, void *self, int a);
extern void FUN_00059d68(void *self, int a);

void FUN_002b0b44(int *param_1, int param_2)
{
  param_1[0x78] = param_2;
  if (param_2 == 14) {
    FUN_00058814(param_1, 0.0f, 1, -1, 0.0f, 0.0f);
    FUN_000587ac(param_1, 1, param_2, 0.0f);
  } else {
    FUN_002b07a4(param_1, 1, param_2);
  }
  FUN_00059ac0(param_1, 1, 1);
  FUN_00059ba8(1.0f, param_1, 1);
  FUN_00059d68(param_1, 1);
}
