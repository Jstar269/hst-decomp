/* HSTMATCH module=EBOOT.BIN start=0x0008d4e0 end=0x0008d530 symbol=FUN_0008d4e0 lang=c99 */
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

extern void FUN_00000a00();
extern int FUN_000d7e30();

int FUN_0008d4e0(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_000d7e30(param_1,0xffffffff), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
