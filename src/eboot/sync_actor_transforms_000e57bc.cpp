/* HSTMATCH module=EBOOT.BIN start=0x000e57bc end=0x000e5948 symbol=FUN_000e57bc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7/v20) corrected by hand: typed the copied transform fields and count member; exact match verified; names and types await human review. */
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
extern undefined * DAT_003386b0;
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct ObjCount { char pad[0x80]; int count; };

extern "C" void FUN_000e57bc(char *param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 != 0) {
    *(float *)(iVar1 + 0x70) = *(float *)(param_1 + 0x50);
    *(float *)(iVar1 + 0x74) = *(float *)(param_1 + 0x54);
    *(float *)(iVar1 + 0x78) = *(float *)(param_1 + 0x58);
    *(float *)(iVar1 + 0x7c) = *(float *)(param_1 + 0x5c);
    *(float *)(iVar1 + 0x80) = *(float *)(param_1 + 0x60);
    *(float *)(iVar1 + 0x84) = *(float *)(param_1 + 100);
    *(float *)(iVar1 + 0x88) = *(float *)(param_1 + 0x68);
    *(float *)(iVar1 + 0x8c) = *(float *)(param_1 + 0x6c);
    *(float *)(iVar1 + 0x90) = *(float *)(param_1 + 0x70);
    *(float *)(iVar1 + 0x94) = *(float *)(param_1 + 0x74);
    *(float *)(iVar1 + 0x98) = *(float *)(param_1 + 0x78);
    *(float *)(iVar1 + 0x9c) = *(float *)(param_1 + 0x7c);
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (iVar1 != 0) {
    *(float *)(iVar1 + 0x70) = *(float *)(param_1 + 0x50);
    *(float *)(iVar1 + 0x74) = *(float *)(param_1 + 0x54);
    *(float *)(iVar1 + 0x78) = *(float *)(param_1 + 0x58);
    *(float *)(iVar1 + 0x7c) = *(float *)(param_1 + 0x5c);
    *(float *)(iVar1 + 0x80) = *(float *)(param_1 + 0x60);
    *(float *)(iVar1 + 0x84) = *(float *)(param_1 + 100);
    *(float *)(iVar1 + 0x88) = *(float *)(param_1 + 0x68);
    *(float *)(iVar1 + 0x8c) = *(float *)(param_1 + 0x6c);
    *(float *)(iVar1 + 0x90) = *(float *)(param_1 + 0x70);
    *(float *)(iVar1 + 0x94) = *(float *)(param_1 + 0x74);
    *(float *)(iVar1 + 0x98) = *(float *)(param_1 + 0x78);
    *(float *)(iVar1 + 0x9c) = *(float *)(param_1 + 0x7c);
  }
  iVar1 = *(int *)(param_1 + 0x80);
  if (0 < iVar1) {
    iVar1 = iVar1 + 1;
    ((ObjCount *)param_1)->count = iVar1;
    if (iVar1 < 3) {
    }
    else {
      piVar2 = *(int **)(param_1 + 0x40);
      if (piVar2 != (int *)0x0) {
        delete ((VC_0 *)(piVar2));
        *(undefined4 *)(param_1 + 0x40) = 0;
      }
      piVar2 = *(int **)(param_1 + 0x44);
      if (piVar2 != (int *)0x0) {
        delete ((VC_1 *)(piVar2));
        *(undefined4 *)(param_1 + 0x44) = 0;
      }
    }
  }
  if (*(int *)(*(int *)(DAT_003386b0 + 0x88) + 4) == 1) {
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + 1;
  }
  return;
}
