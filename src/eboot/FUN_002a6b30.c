/* HSTMATCH module=EBOOT.BIN start=0x002a6b30 end=0x002a6b68 symbol=FUN_002a6b30 lang=c99 */
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

extern void FUN_001031e8();
extern void FUN_002a6668();

void FUN_002a6b30(int param_1)
{
  if (*(int *)(param_1 + 0x880) == 0) {
    FUN_002a6668();
  }
  FUN_001031e8(param_1);
  return;
}
