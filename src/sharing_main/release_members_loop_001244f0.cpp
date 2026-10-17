/* HSTMATCH module=hstp_trans_main.prx start=0x001244f0 end=0x00124590 symbol=FUN_001244f0 lang=c++ */
/* Clone of src/eboot/release_members_loop_0011931c.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the member pointer (s-register order); exact match verified; names and types await human review. */
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
extern int * FUN_00125c58(...);
extern int * FUN_00126798(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001244f0(int param_1)
{
  int iVar3;
  int iVar2;
  int *piVar1;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    piVar1 = *(int **)(iVar2 + 0x48);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(undefined4 *)(iVar2 + 0x48) = 0;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0x1b);
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_00125c58(*(int *)(param_1 + 0x3c),1);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x40);
  if (iVar2 != 0) {
    FUN_00126798(iVar2,1);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  return;
}
