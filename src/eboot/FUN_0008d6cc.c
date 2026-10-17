/* HSTMATCH module=EBOOT.BIN start=0x0008d6cc end=0x0008d72c symbol=FUN_0008d6cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
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

extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008d4e0();

int FUN_0008d6cc(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_00000788(param_1 + 0x94,FUN_0008d4e0,0xf4,4), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
