/* HSTMATCH module=EBOOT.BIN start=0x00192d8c end=0x00192e18 symbol=FUN_00192d8c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r02/f0247_00192d8c_m04.c); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00000a00();
extern void FUN_00192e18();
extern void FUN_00192f18();

int FUN_00192d8c(int param_1,short param_2)
{
  int iVar1;
  undefined1 auStack_4 [4];
  undefined4 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_00192e18();
    iVar1 = param_1 + 4;
    if (((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) {
      local_c = param_1 + 8;
      local_8 = *(undefined4 *)(0xc + param_1);
      FUN_00192f18(auStack_4,iVar1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
