/* HSTMATCH module=EBOOT.BIN start=0x000ef978 end=0x000ef9a8 symbol=FUN_000ef978 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_000ef564();
extern void FUN_000ef9d8();

void FUN_000ef978(undefined4 param_1)
{
  FUN_000ef9d8();
  FUN_000ef564(param_1,0);
  return;
}
