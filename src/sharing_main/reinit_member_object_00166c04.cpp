/* HSTMATCH module=hstp_trans_main.prx start=0x00166c04 end=0x00166d00 symbol=FUN_00166c04 lang=c++ */
/* Clone of src/eboot/reinit_member_object_0015a62c.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
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
extern undefined DAT_00385668;
extern char DAT_00385648[];
extern char DAT_0038566c[];
extern char DAT_00385674[];
extern int FUN_00000bcc(...);
extern void FUN_00105470(...);
extern int FUN_00108124(...);
extern undefined4 * FUN_0010873c(...);
extern int FUN_00109304(...);
extern void FUN_00109a44(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_00166c04(int param_1)
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
    iVar1 = (int)(FUN_0010873c(iVar1));
  }
  uVar2 = iVar1;
  *(undefined4 *)(param_1 + 0x24) = uVar2;
  FUN_00109a44(uVar2,DAT_00385648,0);
  iVar1 = FUN_00109304(*(undefined4 *)(param_1 + 0x24),&DAT_00385668,0);
  if (iVar1 != 0) {
    iVar3 = FUN_00108124(iVar1,DAT_0038566c);
    if (iVar3 != 0) {
      *(int *)(param_1 + 0x2c) = iVar3;
      FUN_00105470(iVar3,1);
    }
    iVar1 = FUN_00108124(iVar1,DAT_00385674);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x30) = iVar1;
      FUN_00105470(iVar1,1);
    }
  }
  return;
}
