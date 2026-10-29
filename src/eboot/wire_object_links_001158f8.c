/* HSTMATCH module=EBOOT.BIN start=0x001158f8 end=0x00115a44 symbol=FUN_001158f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: formed relative pointers from field addresses before subtracting nested bases and corrected a nested offset; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307c80;
extern u8 DAT_00307c90;
extern u8 DAT_00307cd4;
extern u8 DAT_00307ce4;
extern u8 DAT_00307cf0;
extern u8 DAT_00307cfc;
extern u8 DAT_00307d40;
extern u8 DAT_00307d50;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Setup of the multiple-inheritance object: stores the vtables and the virtual-base offsets;
   with flags != 0 also resets the embedded sub-objects; frees the object when flags > 0. */
int * FUN_001158f8(int *self,int flags)
{
  if (self != (int *)0x0) {
    self[2] = (int)&DAT_00307c80;
    *(u8 **)(*self + 4) = &DAT_00307cd4;
    **(u32 **)*self = (unsigned int)(&DAT_00307c90);
    *(u8 **)(self[1] + 0x7c) = &DAT_00307ce4;
    *(int *)(*(int *)*self + 0xd0) = (int)((char *)self + 0x30) - *(int *)*self;
    *(int *)(*self + 0x10) = (int)((char *)self + 0x110) - *self;
    *(int *)(self[1] + 0x80) = (int)(self + 0x4c) - self[1];
    if (flags != 0) {
      if (self + 0x4c != (int *)0x0) {
        self[0x6b] = (int)&DAT_00307cf0;
        *(u8 **)self[0x4c] = &DAT_00307cfc;
        *(int *)(self[0x4c] + 0xd0) = (int)((char *)self + 0x1b0) - self[0x4c];
      }
      if (self + 0x44 != (int *)0x0) {
        self[0x45] = (int)&DAT_00307d40;
        *(u8 **)self[0x44] = &DAT_00307d50;
        *(int *)(self[0x44] + 0xd0) = (int)((char *)self + 0x120) - self[0x44];
      }
      if (self + 0xc != (int *)0x0) {
        self[0xc] = (int)&DAT_0030779c;
        FUN_00100b24(self + 0xc,0);
      }
    }
    if (0 < (short)flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
