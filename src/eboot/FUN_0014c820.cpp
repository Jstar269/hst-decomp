/* HSTMATCH module=EBOOT.BIN start=0x0014c820 end=0x0014c8cc symbol=FUN_0014c820 lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a5); exact match verified; names and types await human review. */
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
extern void FUN_00000a00(...);
extern void FUN_0014f32c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int FUN_0014c820(int param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  undefined1 auStack_4 [4];
  undefined4 local_8;
  int local_c;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 8);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(undefined4 *)(param_1 + 8) = 0;
    }
    iVar2 = param_1 + 0x18;
    if (((iVar2 != 0) && (iVar2 != 0)) && (iVar2 != 0)) {
      local_c = param_1 + 0x1c;
      local_8 = *(undefined4 *)(param_1 + 0x20);
      FUN_0014f32c(auStack_4,iVar2,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
