/* HSTMATCH module=EBOOT.BIN start=0x00063c14 end=0x00063d08 symbol=FUN_00063c14 lang=c99 */
typedef unsigned int uint;
typedef struct { float x; float y; float z; float w; } Vec4;
typedef struct { uint x; uint y; uint z; uint w; } UInt4;
extern int FUN_00063a0c(void);
extern void FUN_00063554(Vec4 *, int);
extern Vec4 FUN_0004c644(const Vec4 *);
extern void FUN_000513a0(uint, int);
void FUN_00063c14(int param_1, float param_2, int param_3)
{
  Vec4 transformed;
  UInt4 identity;
  Vec4 input;
  Vec4 *source;
  identity.x = 0x3f800000;
  identity.y = 0x3f800000;
  identity.z = 0x3f800000;
  identity.w = 0x3f800000;
  if (FUN_00063a0c() != 0) {
    source = (Vec4 *)&identity;
  } else {
    FUN_00063554(&input, param_1);
    source = &input;
  }
  transformed = FUN_0004c644(source);
  *(float *)(param_1 + 0x20) = transformed.x;
  *(float *)(param_1 + 0x24) = transformed.y;
  *(float *)(param_1 + 0x28) = transformed.z;
  *(float *)(param_1 + 0x2c) = transformed.w;
  *(uint *)(param_1 + 0x30) = 0x3f800000;
  *(uint *)(param_1 + 0x34) = 0x3f800000;
  *(uint *)(param_1 + 0x38) = 0x3f800000;
  *(uint *)(param_1 + 0x3c) = 0;
  *(float *)(param_1 + 8) = (float)param_3;
  *(float *)(param_1 + 0xc) = (float)param_3;
  *(uint *)(param_1 + 0x10) = 0xbf800000;
  FUN_000513a0(*(uint *)(param_1 + 4), 0);
  *(unsigned char *)(param_1 + 0x40) = 0;
  *(unsigned char *)(param_1 + 0x41) = 0;
  *(uint *)(param_1 + 0x44) = 0x457a0000;
  *(unsigned char *)(param_1 + 0x50) = 0;
  *(unsigned char *)(param_1 + 0x51) = 0;
  *(unsigned char *)(param_1 + 0x52) = 1;
  *(unsigned char *)(param_1 + 0x53) = 1;
  *(float *)(param_1 + 0x54) = param_2;
}
// Near miss: 2 words differ at 0x00064af0 and 0x00064af8; the saved integer argument copies occur in the opposite order.
// near miss from lane s10171846c1r2-2 (unreviewed)

// NEAR MISS (61/61 words, 2 differ at +0x18/+0x20; op1 lane 2026-10-21, converted from the Sharing twin wip/setup_transform_00064ad8.c).
// Same 2-word parameter-copy order as its twin 0x00063b20 (retail `move s1,a1; mov.s $f20,$f12; move s0,a0`).
// near miss from lane op1 (unreviewed)
