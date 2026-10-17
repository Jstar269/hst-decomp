/* HSTMATCH module=EBOOT.BIN start=0x001a47e8 end=0x001a4824 symbol=FUN_001a47e8 lang=c99 */
/* Hand-written reconstruction from the disassembly (range check written as one && condition); exact match verified; names and types await human review. */
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


void FUN_001a47e8(int param_1,int param_2)
{
  if (param_2 == 0xff) {
    *(int *)(param_1 + 0x2f4) = 0;
  }
  else if (param_2 >= 0 && param_2 < 2) {
    *(int *)(param_1 + 0x2f4) = param_2;
  }
  else {
    *(int *)(param_1 + 0x2f4) = 0;
  }
}
