/* HSTMATCH module=EBOOT.BIN start=0x00128e40 end=0x00128f60 symbol=FUN_00128e40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the goto-heavy float compare chain is two if/else-if arms with variable-left compares (b >= 0 && a < 0 && b - a > pi / b < 0 && a >= 0 && a - b > pi), the clamp step is a ternary (d < 0 ? -DAT : DAT) with fabsf as the abs.s intrinsic; exact match verified; names and types await human review. */
extern float DAT_002da3b4;
extern float fabsf(float);

float FUN_00128e40(float a, float b)
{
  float d;
  if (b >= 0.0f && a < 0.0f && b - a > 3.1415927f) {
    a = a + 6.2831855f;
  } else if (b < 0.0f && a >= 0.0f && a - b > 3.1415927f) {
    b = b + 6.2831855f;
  }
  d = a - b;
  if (fabsf(d) > DAT_002da3b4) {
    a = b + (d < 0.0f ? -DAT_002da3b4 : DAT_002da3b4);
  }
  if (a > 3.1415927f) {
    a = a - 6.2831855f;
  }
  return a;
}
