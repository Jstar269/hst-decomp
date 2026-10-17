/* HSTMATCH module=hstp_trans_main.prx start=0x00002df8 end=0x00002e7c symbol=FUN_00002df8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
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
extern undefined4 FUN_00002c34();
extern void FUN_00002e7c();
extern undefined4 FUN_00002e98();

int FUN_00002df8(int param_1,short param_2)
{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1 != 0) {
    piVar1 = (int *)FUN_00002c34();
    if (*piVar1 != 0) {
      uVar2 = FUN_00002e98(param_1);
      puVar3 = (undefined4 *)FUN_00002c34(param_1);
      FUN_00002e7c(uVar2,*puVar3);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
