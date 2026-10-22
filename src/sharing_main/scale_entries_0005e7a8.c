/* HSTMATCH module=hstp_trans_main.prx start=0x0005e7a8 end=0x0005e81c symbol=FUN_0005e7a8 lang=c99 */
/* Clone of src/eboot/scale_entries_0005d98c.c (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Self {
  int pad;
  int *f4;
  unsigned int f8;
};

extern void FUN_0005e30c(float a, int b);

void FUN_0005e7a8(float param_1, struct Self *self)
{
  float v = param_1 / 30.0f;
  for (unsigned int i = 0; i < self->f8; i++) {
    FUN_0005e30c(v, self->f4[i]);
  }
}
