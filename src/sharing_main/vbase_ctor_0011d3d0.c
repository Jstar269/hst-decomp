/* HSTMATCH module=hstp_trans_main.prx start=0x0011d3d0 end=0x0011d550 symbol=FUN_0011d3d0 lang=c99 helpers=FUN_0011cc90@0x0011cc90-0x0011cde0 */
/* Hand-written reconstruction (port of src/eboot/vbase_ctor_00113194.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002cc260;
extern u8 DAT_0037ffe4;
extern u8 DAT_003b0a68;
extern u8 DAT_003b0f4c;
extern u8 DAT_003b0f5c;
extern u8 DAT_003b0fa0;
extern u8 DAT_003b0fb0;
extern u8 DAT_003b100c;
extern u8 DAT_003b101c;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();
extern u8 DAT_003b0fbc;
extern u8 DAT_003b0fc8;
#define UNSET_VALUE (-999)  /* marks an unused table slot */

#pragma opt_strength_reduction off
/* Initialises a sub-object: optionally builds its embedded base first, then resets four 15-entry tables (5 entries per pass). */
static int * FUN_0011cc90(int *self,short construct_base,void *unused)
{
  int *base;
  int index;

  if (construct_base != 0) {
    base = self + 0x20;
    *self = (int)base;
    FUN_001017dc(base);
    FUN_00056cac(base + 0xc);
    *base = (int)&DAT_003b0a68;
    base[0x1c] = 0;
    base[0x1d] = -1;
    base[0x1e] = 0x3f800000;
    base[0x1f] = 0x3f800000;
    FUN_00056cac(base + 0x20);
    base[0x30] = (int)&DAT_0037ffe4;
    FUN_00101748(base,&DAT_002cc260);
    FUN_001016c0(base + 0x20,&DAT_002cc260);
  }
  self[0x1f] = (int)&DAT_003b0fbc;
  *(u8 **)*self = &DAT_003b0fc8;
  index = 0;
  *(int *)(*self + 0xd0) = (int)(self + 0x20) - *self;
  self[1] = 0;
  self[2] = 0;
  self[3] = 0;
  base = self;
  do {
    base[4] = UNSET_VALUE;
    *(u8 *)((int)self + index + 0x4c) = 1;
    *(u8 *)((int)self + index + 0x5b) = 0;
    *(u8 *)((int)self + index + 0x6a) = 0;
    base[5] = UNSET_VALUE;
    *(u8 *)((int)self + index + 0x4d) = 1;
    *(u8 *)((int)self + index + 0x5c) = 0;
    *(u8 *)((int)self + index + 0x6b) = 0;
    base[6] = UNSET_VALUE;
    *(u8 *)((int)self + index + 0x4e) = 1;
    *(u8 *)((int)self + index + 0x5d) = 0;
    *(u8 *)((int)self + index + 0x6c) = 0;
    base[7] = UNSET_VALUE;
    *(u8 *)((int)self + index + 0x4f) = 1;
    *(u8 *)((int)self + index + 0x5e) = 0;
    *(u8 *)((int)self + index + 0x6d) = 0;
    base[8] = UNSET_VALUE;
    *(u8 *)((int)self + index + 0x50) = 1;
    *(u8 *)((int)self + index + 0x5f) = 0;
    *(u8 *)((int)self + index + 0x6e) = 0;
    index = index + 5;
    base = base + 5;
  } while (index < 0xf);
  return self;
}

#pragma opt_strength_reduction reset

/* Constructor with virtual bases; builds the shared base and the second sub-object when construct_bases is non-zero. */
int * FUN_0011d3d0(int *self,short construct_bases)
{
  int *base;
  
  if (construct_bases != 0) {
    base = self + 0xc;
    self[0x44] = (int)base;
    self[0x4c] = (int)base;
    *self = (int)(self + 0x44);
    self[1] = (int)(self + 0x4c);
    FUN_001017dc(base);
    FUN_00056cac(base + 0xc);
    *base = (int)&DAT_003b0a68;
    base[0x1c] = 0;
    base[0x1d] = -1;
    base[0x1e] = 0x3f800000;
    base[0x1f] = 0x3f800000;
    FUN_00056cac(base + 0x20);
    base[0x30] = (int)&DAT_0037ffe4;
    FUN_00101748(base,&DAT_002cc260);
    FUN_001016c0(base + 0x20,&DAT_002cc260);
    char *t = (char *)self + 0x110;
    *(int *)(t + 4) = (int)&DAT_003b100c;
    *(u8 **)self[0x44] = &DAT_003b101c;
    *(int *)(self[0x44] + 0xd0) = (int)t + 0x10 - self[0x44];
    FUN_0011cc90(self + 0x4c,0,&DAT_003b101c);
  }
  self[2] = (int)&DAT_003b0f4c;
  *(u8 **)(*self + 4) = &DAT_003b0fa0;
  **(u32 **)*self = (unsigned int)(&DAT_003b0f5c);
  *(u8 **)(self[1] + 0x7c) = &DAT_003b0fb0;
  *(int *)(*(int *)*self + 0xd0) = (int)(self + 0xc) - *(int *)*self;
  *(int *)(*self + 0x10) = (int)(self + 0x44) - *self;
  *(int *)(self[1] + 0x80) = (int)(self + 0x4c) - self[1];
  self[3] = 0;
  self[5] = 0;
  self[6] = 0;
  self[7] = 0;
  self[8] = 0x42c80000;
  return self;
}
