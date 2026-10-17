/* HSTMATCH module=EBOOT.BIN start=0x000c4734 end=0x000c47a0 symbol=FUN_000c4734 lang=c99 */
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

extern undefined DAT_00307430;
extern undefined4 DAT_00338af0;
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern void FUN_000c47a0();

undefined4 * FUN_000c4734(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307430);
    FUN_000c47a0();
    DAT_00338af0 = 0;
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
