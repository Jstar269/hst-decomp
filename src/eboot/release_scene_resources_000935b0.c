/* HSTMATCH module=EBOOT.BIN start=0x000935b0 end=0x00093654 symbol=FUN_000935b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: restored the float parameter and typed both helper calls; exact match verified; names and types await human review. */
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

extern void FUN_00058f38(int, float, int);
extern void FUN_0005f110(int, float);

void FUN_000935b0(int param_1,float param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00058f38(iVar1,param_2,0xffffffff);
    FUN_0005f110(iVar1,param_2);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00058f38(iVar1,param_2,0xffffffff);
    FUN_0005f110(iVar1,param_2);
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00058f38(iVar1,param_2,0xffffffff);
    FUN_0005f110(iVar1,param_2);
  }
  return;
}
