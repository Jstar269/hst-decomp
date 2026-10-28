/* HSTMATCH module=EBOOT.BIN start=0x0028dbf8 end=0x0028dd1c symbol=FUN_0028dbf8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: used address globals, returned the allocator result directly, and typed the final virtual call; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309d98;
extern u8 * DAT_003386c8;
extern char DAT_002feee4[];
extern char DAT_002feef8[];
extern u32 DAT_0030ab9c;
extern u32 DAT_0030ebf4;
extern int FUN_00000bcc(int);
extern int FUN_00010184(int,int);
extern void FUN_000104e0(int);
extern void FUN_0001bfb4(void *,unsigned int,unsigned int);
extern void FUN_0001cad0(void *,int,void *);
extern void FUN_0001cb88(void *);
extern int FUN_0001cbfc();
extern u32 FUN_0001cc54();
extern u32 * FUN_0001f06c();
extern void FUN_00253da0();
extern void FUN_00258294(int);
extern int * FUN_0028dd1c(int,char *);
}

struct Finalizer {
  virtual void slot0();
  virtual void slot1();
  virtual void slot2();
  virtual void slot3();
  virtual void slot4();
  virtual void slot5();
  virtual void finalize();
};

extern "C" u32 * FUN_0028dbf8(u32 *param_1)
{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_00309d98);
  param_1[0xf] = 0;
  iVar1 = FUN_00010184(0x40,0x300000);
  FUN_0001bfb4(&DAT_0030ab9c,iVar1,0x300000);
  FUN_0001cad0(&DAT_0030ebf4,1,DAT_002feee4);
  *(u32 *)(*(int *)(DAT_003386c8 + 0x40) + 0x5c) = 1;
  iVar2 = FUN_00000bcc(0x1bc0);
  if (iVar2 != 0) iVar2 = (int)FUN_0028dd1c(iVar2,DAT_002feef8);
  param_1[0xf] = iVar2;
  FUN_00253da0();
  FUN_0001cb88(&DAT_0030ebf4);
  uVar3 = FUN_0001cbfc();
  uVar4 = FUN_0001cc54();
  FUN_0001bfb4(&DAT_0030ab9c,uVar3,uVar4);
  if (iVar1 != 0) {
    FUN_000104e0(iVar1);
  }
  uVar3 = param_1[0xf];
  FUN_00258294(uVar3);
  ((Finalizer *)param_1[0xf])->finalize();
  return param_1;
}
