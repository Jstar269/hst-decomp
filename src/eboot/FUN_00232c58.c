/* HSTMATCH module=EBOOT.BIN start=0x00232c58 end=0x00232cc4 symbol=FUN_00232c58 lang=c99 */
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

extern undefined4 DAT_0034a664;
extern void FUN_00000a00();
extern void FUN_00232e2c();
extern void FUN_00233384();
extern void FUN_002afd2c();

int FUN_00232c58(int param_1,short param_2)
{
  if (param_1 != 0) {
    DAT_0034a664 = 0;
    FUN_002afd2c();
    FUN_00232e2c(param_1);
    FUN_00233384(param_1,0xf0,0x88);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
