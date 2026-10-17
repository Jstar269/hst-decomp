/* HSTMATCH module=hstp_trans_main.prx start=0x001340b0 end=0x001341d0 symbol=FUN_001340b0 lang=c99 */
/* Clone of src/eboot/angle_approach_00128e40.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the goto-heavy float compare chain is two if/else-if arms with variable-left compares (b >= 0 && a < 0 && b - a > pi / b < 0 && a >= 0 && a - b > pi), the clamp step is a ternary (d < 0 ? -DAT : DAT) with fabsf as the abs.s intrinsic; exact match verified; names and types await human review. */
extern float DAT_00381434;
extern float fabsf(float);

float FUN_001340b0(float a, float b)
{
  float d;
  if (b >= 0.0f && a < 0.0f && b - a > 3.1415927f) {
    a = a + 6.2831855f;
  } else if (b < 0.0f && a >= 0.0f && a - b > 3.1415927f) {
    b = b + 6.2831855f;
  }
  d = a - b;
  if (fabsf(d) > DAT_00381434) {
    a = b + (d < 0.0f ? -DAT_00381434 : DAT_00381434);
  }
  if (a > 3.1415927f) {
    a = a - 6.2831855f;
  }
  return a;
}
