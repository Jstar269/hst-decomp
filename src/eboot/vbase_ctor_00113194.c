/* HSTMATCH module=EBOOT.BIN start=0x00113194 end=0x00113314 symbol=FUN_00113194 lang=c99 helpers=FUN_00112cc0@0x00112cc0-0x00112e10 */
/* Ghidra pseudocode (hstgen.py tag from the lane-fm7 near miss) corrected by hand: base = self + 0xc for the sub-object members, vbase offsets through a char * local t = (char *)self + 0x110, FUN_00112cc0 defined static in front (placed by helpers=, hand-copied from src/eboot/obj_init_00112cc0.c) with an unused third parameter and the dummy argument &DAT_00307d50; matching idioms: the char * t used for the +4 store, the dummy third argument; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_002d9210;
extern u8 DAT_0030779c;
extern u8 DAT_00307c80;
extern u8 DAT_00307c90;
extern u8 DAT_00307cd4;
extern u8 DAT_00307ce4;
extern u8 DAT_00307d40;
extern u8 DAT_00307d50;
extern u32 FUN_00056098();
extern u32 * FUN_000fbf84();
extern u32 * FUN_000fc00c();
extern u32 * FUN_000fc0a0();
extern u8 DAT_00307cf0;
extern u8 DAT_00307cfc;
#define UNSET_VALUE (-999)  /* marks an unused table slot */

#pragma opt_strength_reduction off
/* Initialises a sub-object: optionally builds its embedded base first, then resets four 15-entry tables (5 entries per pass). */
static int * FUN_00112cc0(int *self,short construct_base,void *unused)
{
  int *base;
  int index;

  if (construct_base != 0) {
    base = self + 0x20;
    *self = (int)base;
    FUN_000fc0a0(base);
    FUN_00056098(base + 0xc);
    *base = (int)&DAT_0030779c;
    base[0x1c] = 0;
    base[0x1d] = -1;
    base[0x1e] = 0x3f800000;
    base[0x1f] = 0x3f800000;
    FUN_00056098(base + 0x20);
    base[0x30] = (int)&DAT_002d9210;
    FUN_000fc00c(base,&DAT_002bc410);
    FUN_000fbf84(base + 0x20,&DAT_002bc410);
  }
  self[0x1f] = (int)&DAT_00307cf0;
  *(u8 **)*self = &DAT_00307cfc;
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
int * FUN_00113194(int *self,short construct_bases)
{
  int *base;
  
  if (construct_bases != 0) {
    base = self + 0xc;
    self[0x44] = (int)base;
    self[0x4c] = (int)base;
    *self = (int)(self + 0x44);
    self[1] = (int)(self + 0x4c);
    FUN_000fc0a0(base);
    FUN_00056098(base + 0xc);
    *base = (int)&DAT_0030779c;
    base[0x1c] = 0;
    base[0x1d] = -1;
    base[0x1e] = 0x3f800000;
    base[0x1f] = 0x3f800000;
    FUN_00056098(base + 0x20);
    base[0x30] = (int)&DAT_002d9210;
    FUN_000fc00c(base,&DAT_002bc410);
    FUN_000fbf84(base + 0x20,&DAT_002bc410);
    char *t = (char *)self + 0x110;
    *(int *)(t + 4) = (int)&DAT_00307d40;
    *(u8 **)self[0x44] = &DAT_00307d50;
    *(int *)(self[0x44] + 0xd0) = (int)t + 0x10 - self[0x44];
    FUN_00112cc0(self + 0x4c,0,&DAT_00307d50);
  }
  self[2] = (int)&DAT_00307c80;
  *(u8 **)(*self + 4) = &DAT_00307cd4;
  **(u32 **)*self = (unsigned int)(&DAT_00307c90);
  *(u8 **)(self[1] + 0x7c) = &DAT_00307ce4;
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
