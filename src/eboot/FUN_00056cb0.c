/* HSTMATCH module=EBOOT.BIN start=0x00056cb0 end=0x00056d68 symbol=FUN_00056cb0 lang=c99 */
/* Clone of src/sharing_main/FUN_00057904.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_00306ff8;
extern void FUN_00000a00();
extern void FUN_00056f88();
extern void FUN_0005734c();
extern void FUN_00057730();
extern void FUN_00057f30();
extern int * FUN_000596f4();
extern int * FUN_000598c8();
extern undefined4 * FUN_0005eafc();

undefined4 * FUN_00056cb0(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00306ff8);
    FUN_00057f30(param_1,0);
    FUN_00057730(param_1);
    FUN_0005734c(param_1);
    FUN_00056f88(param_1);
    puVar1 = param_1 + 0x5d;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_000598c8(puVar1,0);
    }
    puVar1 = param_1 + 0x38;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_000596f4(puVar1,0);
    }
    FUN_0005eafc(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
