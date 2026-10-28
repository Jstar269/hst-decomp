/* HSTMATCH module=EBOOT.BIN start=0x002704c0 end=0x002705fc symbol=FUN_002704c0 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* EXACT. Two levers were needed on top of the earlier %hi/%lo symbol-address fix:
   * the duplicated 3rd/4th argument must be materialised through a local (`void *dup = &DAT_002fe324;`)
     so MWCC completes `lui a2,0x30; addiu a2,a2,-7388` back to back instead of deferring the addiu
     past `lui a0/lui a1`;
   * the post-alloc null test has ONE store after the `if`, not a store before and another inside:
     `iVar3 = new(...); if (iVar3) iVar3 = ctor(iVar3); *(u4*)(this+0xf0) = iVar3;` MWCC duplicates the
     store into both paths and encodes the null path as `beqzl v0` with `sw v0,240(s0)` in the delay
     slot. Writing the store twice by hand gives a plain `beqz` and stays one word off. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_002fe2d0;
extern u8 DAT_002fe324;
extern char DAT_002fe2b4[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern u32 FUN_00279578(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_002704c0(int param_1)
{
  int cVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  int *piVar5;
  
  iVar2 = FUN_002791a4(param_1,1);
  iVar3 = FUN_00279578(param_1,1);
  iVar2 = iVar2 + iVar3 * 4;
  if (*(int *)(param_1 + 0x180) < 0) {
    return;
  }
  {
    iVar2 = iVar2 * 0x30;
    {
      void *dup;

      dup = &DAT_002fe324;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(u32 *)(*(int *)(param_1 + 0xb4) + iVar2 + 8),&DAT_002fe2d0);
    }
    piVar5 = *(int **)(param_1 + 0xf0);
    if (piVar5 != (int *)0x0) {
      delete ((VC_0 *)(piVar5));
      *(u32 *)(param_1 + 0xf0) = 0;
    }
    iVar3 = FUN_00000bcc(0x1c0);
    if (iVar3 != 0) {
      iVar3 = FUN_00094fa4(iVar3);
    }
    *(u32 *)(param_1 + 0xf0) = iVar3;
    uVar4 = iVar3;
    cVar1 = FUN_00095104(uVar4,1,*(u32 *)(*(int *)(param_1 + 0xb4) + iVar2 + 8),0,0);
    FUN_0001cb88(&DAT_0030ebf4);
    if ((cVar1 == '\0') && (piVar5 = *(int **)(param_1 + 0xf0), piVar5 != (int *)0x0)) {
      delete ((VC_1 *)(piVar5));
      *(u32 *)(param_1 + 0xf0) = 0;
    }
  }
}
