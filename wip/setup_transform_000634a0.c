/* HSTMATCH module=EBOOT.BIN start=0x000634a0 end=0x00063554 symbol=FUN_000634a0 lang=c99 */
extern void FUN_000513a0();

void FUN_000634a0(int param_1, float param_2, float param_3, float *param_4, float *param_5,
                  unsigned param_6, unsigned char param_7)
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

// NEAR MISS (45/45 words, 2 differ at +0x28; op1 lane 2026-10-21, converted from the Sharing twin wip/FUN_00064364_00064364.c).
// Retail copies `move s1,a0; move s0,t0; mov.s $f20,$f13`; we emit the float copy before the t0 copy (a0 then f13 then t0).
// Ruled out: reordering the declarations (param_6 before param_3, both legal because ints and floats take independent EBOOT
// registers), `void *`/`int` types for param_6, a local copy of the flag. Same wall as 0x00063b20/0x00063c14/0x0006391c.
// near miss from lane op1 (unreviewed)
