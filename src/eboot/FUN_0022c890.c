/* HSTMATCH module=EBOOT.BIN start=0x0022c890 end=0x0022c8b4 symbol=FUN_0022c890 lang=c99 */
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

extern undefined4 DAT_003415a8;

void FUN_0022c890(int param_1)
{
  int iVar1;
  
  iVar1 = param_1 + 0x8d00 + DAT_003415a8;
  *(byte *)(iVar1 + 0x3500) = *(byte *)(iVar1 + 0x3500) | 1;
  return;
}
