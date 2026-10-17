/* HSTMATCH module=EBOOT.BIN start=0x000e193c end=0x000e1984 symbol=FUN_000e193c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: replaced the four loose undefined4 locals with a float v[4] array the callee fills, and stored it as four indexed float member writes; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern void FUN_0001d7e4(float *param_1, uint param_2);

void FUN_000e193c(float *param_1, uint param_2)
{
  float v[4];

  FUN_0001d7e4(v, param_2);
  param_1[32] = v[0];
  param_1[33] = v[1];
  param_1[34] = v[2];
  param_1[35] = v[3];
}
