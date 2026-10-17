/* HSTMATCH module=EBOOT.BIN start=0x0018f14c end=0x0018f1ac symbol=FUN_0018f14c lang=c99 */
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
extern int FUN_00004138();
extern uint * FUN_000462a0();

int FUN_0018f14c(int param_1,short param_2)
{
  if (param_1 != 0) {
    FUN_000462a0(param_1 + 0xc,0xffffffff);
    FUN_00004138(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
