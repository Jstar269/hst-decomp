/* HSTMATCH module=EBOOT.BIN start=0x002b56ec end=0x002b5778 symbol=FUN_002b56ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_002b56ec.c; exact match verified; names and types await human review. */
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

extern undefined DAT_00309fd4;
extern undefined4 DAT_0034b5dc;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern undefined4 * FUN_000510c0();
extern void FUN_0005aeac();

undefined4 * FUN_002b56ec(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00309fd4);
    DAT_0034b5dc = 0;
    FUN_00000788(param_1 + 0x24,FUN_0005aeac,0x70,0x14);
    FUN_000510c0(param_1 + 0x10,0xffffffff);
    FUN_0001f0f0(param_1,0);
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
