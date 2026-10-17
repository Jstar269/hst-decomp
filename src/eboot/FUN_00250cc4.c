/* HSTMATCH module=EBOOT.BIN start=0x00250cc4 end=0x00250cec symbol=FUN_00250cc4 lang=c99 */
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


undefined4 FUN_00250cc4(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 0x2f8) != 4) && (*(int *)(param_1 + 0x2f8) != 6)) {
    uVar1 = 0;
  }
  return uVar1;
}
