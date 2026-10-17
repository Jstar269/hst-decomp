/* HSTMATCH module=EBOOT.BIN start=0x0005eafc end=0x0005eb98 symbol=FUN_0005eafc lang=c99 */
/* Clone of src/sharing_main/FUN_0005f8ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0030704c;
extern void FUN_00000a00();
extern int * FUN_00054f4c();
extern void FUN_0005ef18();
extern int * FUN_0005f47c();
extern int * FUN_0005f688();

undefined4 * FUN_0005eafc(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030704c);
    FUN_0005ef18();
    puVar1 = param_1 + 0x2d;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0005f47c(puVar1,0);
    }
    puVar1 = param_1 + 0x2a;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_0005f688(puVar1,0);
    }
    FUN_00054f4c(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
