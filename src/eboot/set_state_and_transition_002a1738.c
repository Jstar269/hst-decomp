/* HSTMATCH module=EBOOT.BIN start=0x002a1738 end=0x002a17e0 symbol=FUN_002a1738 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: corrected callee prototype argument orders for float parameters; exact match verified; names and types await human review. */
extern void FUN_00057bc0(void *self, float f1, int a, int b, float f2, float f3);
extern void FUN_00057b58(void *self, int a, int b, float f);
extern void FUN_002a1398(void *self, int a, int b);
extern void FUN_00058ddc(void *self, int a, int b);
extern void FUN_00058ec4(float f, void *self, int a);
extern void FUN_00059084(void *self, int a);

void FUN_002a1738(int *param_1, int param_2)
{
  param_1[0x78] = param_2;
  if (param_2 == 14) {
    FUN_00057bc0(param_1, 0.0f, 1, -1, 0.0f, 0.0f);
    FUN_00057b58(param_1, 1, param_2, 0.0f);
  } else {
    FUN_002a1398(param_1, 1, param_2);
  }
  FUN_00058ddc(param_1, 1, 1);
  FUN_00058ec4(1.0f, param_1, 1);
  FUN_00059084(param_1, 1);
}
