/* HSTMATCH module=EBOOT.BIN start=0x000634a0 end=0x00063554 symbol=FUN_000634a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/*
  Matching idiom: the pointer/integer parameters are declared before the floats. EABI gives int and float
  parameters independent registers, so the mapping is unchanged, but the prologue copies are emitted in
  declaration order, which is the retail order (`move s0,t0` before `mov.s $f20,$f13`).
*/
extern void FUN_000513a0();

void FUN_000634a0(int param_1, float *param_4, float *param_5, unsigned param_6, unsigned char param_7,
                  float param_2, float param_3)
{
  *(float *)(param_1 + 0x20) = param_4[0];
  *(float *)(param_1 + 0x24) = param_4[1];
  *(float *)(param_1 + 0x28) = param_4[2];
  *(float *)(param_1 + 0x2c) = param_4[3];
  *(float *)(param_1 + 0x30) = param_5[0];
  *(float *)(param_1 + 0x34) = param_5[1];
  *(float *)(param_1 + 0x38) = param_5[2];
  *(float *)(param_1 + 0x3c) = param_5[3];
  *(float *)(param_1 + 8) = param_2;
  *(float *)(param_1 + 0xc) = param_2;
  *(unsigned *)(param_1 + 0x10) = 0xbf800000;
  FUN_000513a0(*(unsigned *)(param_1 + 4), param_6);
  *(unsigned char *)(param_1 + 0x40) = param_7;
  *(unsigned char *)(param_1 + 0x41) = 0;
  if (param_3 < 0.0f) {
    param_3 = 4000.0f;
  }
  *(float *)(param_1 + 0x44) = param_3;
  return;
}
