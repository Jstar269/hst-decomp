/* HSTMATCH module=EBOOT.BIN start=0x002934ec end=0x00293564 symbol=FUN_002934ec lang=c++ */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a7); exact match verified; names and types await human review. */
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
extern int FUN_00053718(...);
extern int FUN_00055e48(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_002934ec(int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x78);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x74);
  if (iVar2 != 0) {
    FUN_00055e48(iVar2,1);
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x70);
  if (iVar2 != 0) {
    FUN_00053718(iVar2,1);
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return;
}
