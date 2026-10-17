/* HSTMATCH module=EBOOT.BIN start=0x0021badc end=0x0021bb04 symbol=FUN_0021badc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64b); exact match verified; names and types await human review. */
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

void FUN_0021badc(int param_1)
{
  if (*(uchar *)(param_1 + 0x54) == '\0') {
    FUN_001031e8();
  }
  return;
}
