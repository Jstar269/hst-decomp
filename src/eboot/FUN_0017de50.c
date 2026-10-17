/* HSTMATCH module=EBOOT.BIN start=0x0017de50 end=0x0017de58 symbol=FUN_0017de50 lang=c99 */
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
typedef float undefined4;


void FUN_0017de50(undefined4 param_1,int param_2)
{
  *(undefined4 *)(param_2 + 0x34) = param_1;
  return;
}
