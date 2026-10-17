/* HSTMATCH module=EBOOT.BIN start=0x002ade80 end=0x002adec4 symbol=FUN_002ade80 lang=c99 */
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

extern undefined4 DAT_0034b5d0;
extern void FUN_00000a00();

int FUN_002ade80(int param_1,short param_2)
{
  if ((param_1 != 0) && (DAT_0034b5d0 = 0, 0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
