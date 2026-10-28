/* HSTMATCH module=EBOOT.BIN start=0x0027028c end=0x002704c0 symbol=FUN_0027028c lang=c++ data=0x002fe2d4 */
/* Hand-written reconstruction from the disassembly (continued from lane fm8 near-miss wip/mode_replace_c_0027028c.cpp); exact match verified; matching idiom: `return;` ending the `cVar1 == 0` arm (puts MWCC's branch cleanup in retail's unthreaded mode) and `base + iVar2 + 0x14` addressing; names and types await human review. Data: its string literals (3 strings, 0x002fe2d4-0x002fe323) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_002fe2ac;
extern u8 DAT_002fe2d0;
extern char DAT_002fe2b4[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_000143b0(char *, char *, ...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern u32 FUN_00279578(...);
extern void FUN_000573a0(void *, int, char *, int, int);
extern void FUN_00057b58(void *, float, int, int);
extern void FUN_00058ec4(void *, float, int);
extern void FUN_00058ddc(void *, int, int);
extern void FUN_00059084(void *, int);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_0027028c(int param_1)
{
  char buf1[256];
  char buf2[256];
  int cVar1;
  int iVar2;
  int iVar3;
  int obj;
  int *piVar5;

  iVar2 = FUN_002791a4(param_1,2);
  iVar3 = FUN_00279578(param_1,2);
  iVar2 = iVar2 + iVar3 * 4;
  if (*(int *)(param_1 + 0x180) < 0) {
    return;
  }
  {
    iVar2 = iVar2 * 0x30;
    {
      void *dup;

      dup = &DAT_002fe2ac;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(u32 *)(*(int *)(param_1 + 0xa8) + iVar2 + 8),&DAT_002fe2d0);
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
    cVar1 = FUN_00095104(iVar3,2,*(u32 *)(*(int *)(param_1 + 0xa8) + iVar2 + 8),0,0);
    FUN_0001cb88(&DAT_0030ebf4);
    if (cVar1 == '\0') {
      piVar5 = *(int **)(param_1 + 0xf0);
      if (piVar5 != (int *)0x0) {
        delete ((VC_1 *)(piVar5));
        *(u32 *)(param_1 + 0xf0) = 0;
      }
      return;
    }
    else if (*(int *)(*(int *)(param_1 + 0xa8) + iVar2 + 0x14) == 2) {
      FUN_0001ca58(&DAT_0030ebf4,"menu/pc/face/anim%03d.xb",0);
      FUN_000143b0(buf1,"chrm_pc%02d_00",0);
      FUN_000143b0(buf2,"data/chara/menu_motion/%02d/%s.i3m",0,buf1);
      FUN_000573a0(*(void **)(param_1 + 0xf0),0,buf2,0,0);
      FUN_00057b58(*(void **)(param_1 + 0xf0),0.0f,0,0);
      obj = *(int *)(param_1 + 0xf0);
      FUN_00058ec4((void *)obj,1.0f,-1);
      *(float *)(obj + 0xc4) = 1.0f;
      obj = *(int *)(param_1 + 0xf0);
      FUN_00058ddc((void *)obj,1,-1);
      *(unsigned char *)(obj + 0xc0) = 1;
      obj = *(int *)(param_1 + 0xf0);
      FUN_00059084((void *)obj,-1);
      *(float *)(obj + 0xd0) = *(float *)(obj + 0xc4);
      FUN_0001cb88(&DAT_0030ebf4);
    }
  }
}
