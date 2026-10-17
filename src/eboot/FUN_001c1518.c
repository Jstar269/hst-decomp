/* HSTMATCH module=EBOOT.BIN start=0x001c1518 end=0x001c159c symbol=FUN_001c1518 lang=c99 rodata=0x002c6340 */
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


undefined2 FUN_001c1518(char *param_1,undefined4 param_2)
{
  undefined2 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = *(undefined2 *)(param_1 + 0x8416);
    break;
  case 1:
    uVar1 = *(undefined2 *)(param_1 + 0x8418);
    break;
  case 2:
    uVar1 = *(undefined2 *)(param_1 + 0x841a);
    break;
  case 3:
  case 4:
    uVar1 = *(undefined2 *)(param_1 + 0x841c);
    break;
  case 5:
    uVar1 = *(undefined2 *)(param_1 + 0x841e);
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}
