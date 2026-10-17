/* HSTMATCH module=EBOOT.BIN start=0x00266714 end=0x0026672c symbol=FUN_00266714 lang=c99 */
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


void FUN_00266714(undefined4 param_1,int param_2)
{
  if (*(int *)(param_2 + 0x70) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x70) + 0xc4) = param_1;
  }
  return;
}
