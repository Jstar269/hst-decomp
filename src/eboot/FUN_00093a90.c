/* HSTMATCH module=EBOOT.BIN start=0x00093a90 end=0x00093b00 symbol=FUN_00093a90 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: float[16] out-buffer (frame 80), the two callee arguments Ghidra dropped typed FUN_00055240(void*, int f64, int f20) and passed both fields, zero tail merged into one block by the && form; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00055240(void *, ModelObj *, int);

/* Write row 3 of the matrix computed for the last model slot and index unk20 to out, or zeros when unavailable. */
void FUN_00093a90(float *out, ModelSet *self)
{
  float matrix[16];

  if (self->unk20 >= 0 && self->model[5] != 0) {
    FUN_00055240(matrix, self->model[5], self->unk20);
    out[0] = matrix[12];
    out[1] = matrix[13];
    out[2] = matrix[14];
    out[3] = matrix[15];
  }
  else {
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 0.0f;
    out[3] = 0.0f;
  }
}
