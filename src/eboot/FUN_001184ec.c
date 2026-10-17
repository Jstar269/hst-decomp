/* HSTMATCH module=EBOOT.BIN start=0x001184ec end=0x00118598 symbol=FUN_001184ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern undefined DAT_00307ffc;
extern undefined4 DAT_0033b460;
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern void FUN_001188c8();
extern void FUN_0011931c();
extern int FUN_0011cc1c();
extern int FUN_0011cfcc();

undefined4 * FUN_001184ec(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307ffc);
    DAT_0033b460 = 0;
    FUN_0011931c();
    FUN_001188c8(param_1);
    puVar1 = param_1 + 0xbe;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0011cfcc(puVar1,0);
    }
    puVar1 = param_1 + 0xb8;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0011cc1c(puVar1,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
