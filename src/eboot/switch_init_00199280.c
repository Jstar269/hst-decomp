/* HSTMATCH module=EBOOT.BIN start=0x00199280 end=0x00199310 symbol=FUN_00199280 lang=c99 rodata=0x002c2aac */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0r) corrected by hand: the switch cases are written in retail body order (2, 4, 5, 3, 9, 10); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003417a4;

void FUN_00199280(int param_1)
{
  *(undefined4 *)(param_1 + 8) = 1;
  switch(DAT_003417a4) {
  case 0:
  case 1:
  case 6:
  case 7:
  case 8:
  default:
    *(undefined4 *)(param_1 + 4) = 1;
    break;
  case 2:
    *(undefined4 *)(param_1 + 4) = 2;
    break;
  case 4:
    *(undefined4 *)(param_1 + 4) = 4;
    break;
  case 5:
    *(undefined4 *)(param_1 + 4) = 5;
    break;
  case 3:
    *(undefined4 *)(param_1 + 4) = 3;
    break;
  case 9:
    *(undefined4 *)(param_1 + 4) = 9;
    break;
  case 10:
    *(undefined4 *)(param_1 + 4) = 10;
  }
  return;
}
