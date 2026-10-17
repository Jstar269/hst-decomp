/* HSTMATCH module=hstp_trans_main.prx start=0x000959b4 end=0x00095a24 symbol=FUN_000959b4 lang=c99 */
/* Clone of src/eboot/FUN_00093a90.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: float[16] out-buffer (frame 80), the two callee arguments Ghidra dropped typed FUN_00055d60(void*, int f64, int f20) and passed both fields, zero tail merged into one block by the && form; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern void FUN_00055d60(void *, int, int);

void FUN_000959b4(float *param_1, int param_2)
{
  float local[16];

  if (*(int *)(param_2 + 0x20) >= 0 && *(int *)(param_2 + 100) != 0) {
    FUN_00055d60(local, *(int *)(param_2 + 100), *(int *)(param_2 + 0x20));
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
