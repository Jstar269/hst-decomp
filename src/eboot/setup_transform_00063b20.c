/* HSTMATCH module=EBOOT.BIN start=0x00063b20 end=0x00063c14 symbol=FUN_00063b20 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/*
  The object pointer is a type-converted local (`unsigned int self = (unsigned int)param_1;`), which defers its
  callee-saved copy to after the parameter copies; with the parameters declared int,int,float (EABI gives the
  floats their own registers, so this is register-identical to int,float,int) the prologue copies come out
  `move s1,a1; mov.s $f20,$f12; move s0,a0` exactly as retail.
*/
#include "hst/types.h"
typedef struct { float x; float y; float z; float w; } Vec4;
typedef struct { u32 x; u32 y; u32 z; u32 w; } UInt4;
extern int FUN_00063a0c(void);
extern void FUN_00063554(Vec4 *, int);
extern Vec4 FUN_0004c644(const Vec4 *);
extern void FUN_000513a0(u32, int);
void FUN_00063b20(int param_1, int param_3, float param_2)
{
  unsigned int self = (unsigned int)param_1;
  Vec4 transformed;
  UInt4 identity;
  Vec4 input;
  Vec4 *source;
  identity.x = 0x3f800000;
  identity.y = 0x3f800000;
  identity.z = 0x3f800000;
  identity.w = 0;
  if (FUN_00063a0c() != 0) {
    source = (Vec4 *)&identity;
  } else {
    FUN_00063554(&input, self);
    source = &input;
  }
  transformed = FUN_0004c644(source);
  *(float *)(self + 0x20) = transformed.x;
  *(float *)(self + 0x24) = transformed.y;
  *(float *)(self + 0x28) = transformed.z;
  *(float *)(self + 0x2c) = transformed.w;
  *(u32 *)(self + 0x30) = 0x3f800000;
  *(u32 *)(self + 0x34) = 0x3f800000;
  *(u32 *)(self + 0x38) = 0x3f800000;
  *(u32 *)(self + 0x3c) = 0x3f800000;
  *(float *)(self + 8) = (float)param_3;
  *(float *)(self + 0xc) = (float)param_3;
  *(u32 *)(self + 0x10) = 0xbf800000;
  FUN_000513a0(*(u32 *)(self + 4), 0);
  *(unsigned char *)(self + 0x40) = 0;
  *(unsigned char *)(self + 0x41) = 0;
  *(u32 *)(self + 0x44) = 0x457a0000;
  *(unsigned char *)(self + 0x50) = 0;
  *(unsigned char *)(self + 0x51) = 0;
  *(unsigned char *)(self + 0x52) = 1;
  *(unsigned char *)(self + 0x53) = 0;
  *(float *)(self + 0x54) = param_2;
}
