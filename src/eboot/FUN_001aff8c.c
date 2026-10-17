/* HSTMATCH module=EBOOT.BIN start=0x001aff8c end=0x001affe4 symbol=FUN_001aff8c lang=c99 */
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

extern void FUN_001b052c();
extern void FUN_001b0610();

void FUN_001aff8c(undefined4 param_1)
{
  FUN_001b0610(param_1,0);
  FUN_001b052c(param_1,3);
  FUN_001b052c(param_1,2);
  FUN_001b052c(param_1,1);
  FUN_001b052c(param_1,0);
  return;
}
