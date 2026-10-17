/* HSTMATCH module=EBOOT.BIN start=0x000d5dc8 end=0x000d5dec symbol=FUN_000d5dc8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64d); exact match verified; names and types await human review. */
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

extern int FUN_0000430c();

bool FUN_000d5dc8(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = FUN_0000430c(param_2,param_3);
  return iVar1 < 0;
}
