/* HSTMATCH module=EBOOT.BIN start=0x001cc988 end=0x001cc99c symbol=FUN_001cc988 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
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

extern void FUN_001cc99c();

void FUN_001cc988(undefined4 param_1,undefined4 param_2)
{
  FUN_001cc99c(param_1,0,0,0xffffffff,param_2);
  return;
}
