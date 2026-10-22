/* HSTMATCH module=EBOOT.BIN start=0x0005d98c end=0x0005da00 symbol=FUN_0005d98c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self {
  int pad;
  int *f4;
  unsigned int f8;
};

extern void FUN_0005d4f0(float a, int b);

void FUN_0005d98c(float param_1, struct Self *self)
{
  float v = param_1 / 30.0f;
  for (unsigned int i = 0; i < self->f8; i++) {
    FUN_0005d4f0(v, self->f4[i]);
  }
}
