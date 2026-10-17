/* HSTMATCH module=EBOOT.BIN start=0x002af224 end=0x002af26c symbol=FUN_002af224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
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

extern uint * FUN_000114c0();
extern uint * FUN_000149a8();

void FUN_002af224(int param_1,undefined4 param_2)
{
  FUN_000114c0(param_1 + 0x1c,0,0x4b);
  FUN_000149a8(param_1 + 0x1c,param_2);
  return;
}
