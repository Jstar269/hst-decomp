/* HSTMATCH module=EBOOT.BIN start=0x001fe010 end=0x001fe04c symbol=FUN_001fe010 lang=c99 */
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

extern void FUN_001fdbb4();
extern void FUN_001fdd50();
extern void FUN_00201910();
extern void FUN_00201dc8();

void FUN_001fe010(int param_1)
{
  FUN_001fdd50();
  FUN_001fdbb4(param_1);
  FUN_00201910(param_1 + 200);
  FUN_00201dc8(param_1 + 0x1250);
  return;
}
