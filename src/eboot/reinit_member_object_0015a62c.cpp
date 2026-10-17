/* HSTMATCH module=EBOOT.BIN start=0x0015a62c end=0x0015a728 symbol=FUN_0015a62c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem); m = mem;` (no zero-initialised temp), so the ctor result stays in v0 at the join; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002de0ac;
extern char DAT_002de08c[];
extern char DAT_002de0b0[];
extern char DAT_002de0b8[];
extern int FUN_00000bcc(...);
extern void FUN_000ffb3c(...);
extern int FUN_001026b8(...);
extern undefined4 * FUN_00102e38(...);
extern int FUN_001039d8(...);
extern void FUN_00104118(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0015a62c(int param_1)
{
  int iVar1;
  int uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x24);
  if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0x0)) {
    delete ((VC_0 *)(piVar4));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  iVar1 = FUN_00000bcc(0x54);
  if (iVar1 != 0) {
    iVar1 = (int)(FUN_00102e38(iVar1));
  }
  uVar2 = iVar1;
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  FUN_00104118(uVar2,DAT_002de08c,0);
  iVar1 = FUN_001039d8(*(undefined4 *)(param_1 + 0x24),&DAT_002de0ac,0);
  if (iVar1 != 0) {
    iVar3 = FUN_001026b8(iVar1,DAT_002de0b0);
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x2c) = iVar3;
      FUN_000ffb3c(iVar3,1);
    }
    iVar1 = FUN_001026b8(iVar1,DAT_002de0b8);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x30) = iVar1;
      FUN_000ffb3c(iVar1,1);
    }
  }
  return;
}
