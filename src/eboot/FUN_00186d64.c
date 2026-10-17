/* HSTMATCH module=EBOOT.BIN start=0x00186d64 end=0x00186d7c symbol=FUN_00186d64 lang=c99 */
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

extern void FUN_0010b980();

void FUN_00186d64(int param_1,int param_2,int param_3,int param_4)
{
  FUN_0010b980(*(undefined4 *)(param_1 + 0x285c),param_2 + (param_3 - param_4) * 4,0);
  return;
}
