/* HSTMATCH module=EBOOT.BIN start=0x00194110 end=0x00194348 symbol=FUN_00194110 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the delete calls (0xa00) take the tested global as argument (Ghidra dropped it); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_00341730;
extern u8 * DAT_00341734;
extern u8 * DAT_00341738;
extern u8 * DAT_0034173c;
extern u8 * DAT_00341740;
extern u8 * DAT_00341748;
extern void FUN_000009e4();
extern void FUN_00000a00(void *);
extern int FUN_001936f0();

void FUN_00194110(void)
{
  int iVar1;
  
  if (DAT_00341730 != 0) {
    iVar1 = *(int *)(DAT_00341730 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(u32 *)(DAT_00341730 + 4) = 0;
    }
    if (DAT_00341730 != 0) {
      FUN_00000a00(DAT_00341730);
      DAT_00341730 = 0;
    }
  }
  if (DAT_0034173c != 0) {
    iVar1 = *(int *)(DAT_0034173c + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(u32 *)(DAT_0034173c + 4) = 0;
    }
    if (DAT_0034173c != 0) {
      FUN_00000a00(DAT_0034173c);
      DAT_0034173c = 0;
    }
  }
  if (DAT_00341734 != 0) {
    iVar1 = *(int *)(DAT_00341734 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(u32 *)(DAT_00341734 + 4) = 0;
    }
    if (DAT_00341734 != 0) {
      FUN_00000a00(DAT_00341734);
      DAT_00341734 = 0;
    }
  }
  if (DAT_00341738 != 0) {
    iVar1 = *(int *)(DAT_00341738 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(u32 *)(DAT_00341738 + 4) = 0;
    }
    if (DAT_00341738 != 0) {
      FUN_00000a00(DAT_00341738);
      DAT_00341738 = 0;
    }
  }
  if (DAT_00341740 != 0) {
    iVar1 = *(int *)(DAT_00341740 + 4);
    if (iVar1 != 0) {
      if (iVar1 != 0) {
        FUN_000009e4(iVar1 + -0x10);
      }
      *(u32 *)(DAT_00341740 + 4) = 0;
    }
    if (DAT_00341740 != 0) {
      FUN_00000a00(DAT_00341740);
      DAT_00341740 = 0;
    }
  }
  iVar1 = (int)(DAT_00341748);
  if (DAT_00341748 != 0) {
    if (DAT_00341748 != 0) {
      FUN_001936f0(DAT_00341748 + 0x40,0xffffffff);
      FUN_001936f0(iVar1 + 0x30,0xffffffff);
      FUN_001936f0(iVar1 + 0x20,0xffffffff);
      FUN_001936f0(iVar1 + 0x10,0xffffffff);
      FUN_001936f0(iVar1,0xffffffff);
      FUN_00000a00((void *)iVar1);
    }
    DAT_00341748 = 0;
  }
}
