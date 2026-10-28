/* HSTMATCH module=EBOOT.BIN start=0x00093a90 end=0x00093b00 symbol=FUN_00093a90 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: float[16] out-buffer (frame 80), the two callee arguments Ghidra dropped typed FUN_00055240(void*, int f64, int f20) and passed both fields, zero tail merged into one block by the && form; exact match verified; names and types await human review. */

extern void FUN_00055240(void *, int, int);

void FUN_00093a90(float *param_1, int param_2)
{
  float local[16];

  if (*(int *)(param_2 + 0x20) >= 0 && *(int *)(param_2 + 100) != 0) {
    FUN_00055240(local, *(int *)(param_2 + 100), *(int *)(param_2 + 0x20));
    param_1[0] = local[12];
    param_1[1] = local[13];
    param_1[2] = local[14];
    param_1[3] = local[15];
  }
  else {
    param_1[0] = 0.0f;
    param_1[1] = 0.0f;
    param_1[2] = 0.0f;
    param_1[3] = 0.0f;
  }
}
