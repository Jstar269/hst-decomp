/* HSTMATCH module=EBOOT.BIN start=0x001e59f4 end=0x001e5a34 symbol=FUN_001e59f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_001e2694 as receiver-only; exact match verified; names and types await human review. */
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

extern void FUN_001e2694(int);
extern void FUN_00222bb8();

void FUN_001e59f4(int param_1,undefined4 param_2)
{
  FUN_001e2694(param_1);
  FUN_00222bb8(*(undefined4 *)(param_1 + 0x1954),param_2,1);
  return;
}
