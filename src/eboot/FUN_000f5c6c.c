/* HSTMATCH module=EBOOT.BIN start=0x000f5c6c end=0x000f5cd8 symbol=FUN_000f5c6c lang=c99 */
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

extern undefined DAT_003077e0;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000510c0();

undefined4 * FUN_000f5c6c(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003077e0);
    FUN_00000788(param_1 + 1,FUN_000510c0,0x48,2);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
