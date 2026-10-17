/* HSTMATCH module=EBOOT.BIN start=0x0017e654 end=0x0017e6c0 symbol=FUN_0017e654 lang=c99 */
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

extern undefined DAT_003090d4;
extern void FUN_00000a00();
extern int FUN_0005ba00();

undefined4 * FUN_0017e654(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003090d4);
    FUN_0005ba00(param_1 + 0xb8,0xffffffff);
    FUN_0005ba00(param_1 + 4,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
