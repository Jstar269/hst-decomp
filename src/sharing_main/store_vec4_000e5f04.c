/* HSTMATCH module=hstp_trans_main.prx start=0x000e5f04 end=0x000e5f4c symbol=FUN_000e5f04 lang=c99 */
/* Clone of src/eboot/store_vec4_000e193c.c (hstclone.py tag c1707b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: replaced the four loose undefined4 locals with a float v[4] array the callee fills, and stored it as four indexed float member writes; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern void FUN_0001d430(float *param_1, uint param_2);

void FUN_000e5f04(float *param_1, uint param_2)
{
  float v[4];

  FUN_0001d430(v, param_2);
  param_1[32] = v[0];
  param_1[33] = v[1];
  param_1[34] = v[2];
  param_1[35] = v[3];
}
