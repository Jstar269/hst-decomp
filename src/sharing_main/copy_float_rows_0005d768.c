/* HSTMATCH module=hstp_trans_main.prx start=0x0005d768 end=0x0005d7e8 symbol=FUN_0005d768 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the copied records as floats and kept both bounds checks independent; exact match verified; names and types await human review. */

void FUN_0005d768(int param_1, int param_2, float *param_3, float *param_4)
{
  if (param_2 < *(int *)(param_1 + 0x18)) {
    int offset = param_2 * 8;
    float *base = (float *)*(int *)(param_1 + 0x1c);
    float *dest = base + offset;
    dest[0] = param_3[0]; dest[1] = param_3[1];
    dest[2] = param_3[2]; dest[3] = param_3[3];
  }
  if (param_2 < *(int *)(param_1 + 0x18)) {
    int offset = param_2 * 8;
    float *base = (float *)*(int *)(param_1 + 0x1c);
    float *dest = base + offset;
    dest[4] = param_4[0]; dest[5] = param_4[1];
    dest[6] = param_4[2]; dest[7] = param_4[3];
  }
}
