/* HSTMATCH module=EBOOT.BIN start=0x00179348 end=0x001793e8 symbol=FUN_00179348 lang=c99 rodata=0x002c1f90 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
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


undefined4 FUN_00179348(int param_1,undefined4 param_2,int param_3)
{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
    uVar1 = **(undefined4 **)(*(int *)(param_1 + 0x1e4) + param_3 * 4);
    break;
  case 2:
    uVar1 = **(undefined4 **)(*(int *)(param_1 + 0x1fc) + param_3 * 4);
    break;
  case 3:
  case 4:
    uVar1 = **(undefined4 **)(*(int *)(param_1 + 0x208) + param_3 * 4);
    break;
  case 5:
    uVar1 = **(undefined4 **)(**(int **)(param_1 + 0x1d4) + param_3 * 4);
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}
