/* HSTMATCH module=EBOOT.BIN start=0x001f1e8c end=0x001f1ea8 symbol=FUN_001f1e8c lang=c99 */
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


void FUN_001f1e8c(int param_1)
{
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined1 *)(param_1 + 0x515) = 1;
  }
  return;
}
