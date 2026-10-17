/* HSTMATCH module=EBOOT.BIN start=0x00234800 end=0x00234898 symbol=FUN_00234800 lang=c99 */
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

extern undefined DAT_00309898;
extern undefined DAT_003098a4;
extern void FUN_00000a00();
extern int * FUN_00165840();
extern int * FUN_00236fe8();

undefined4 * FUN_00234800(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = param_1 + 5;
    *param_1 = (unsigned int)(&DAT_00309898);
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_00236fe8(puVar1,0);
    }
    if (param_1 != (undefined4 *)0x0) {
      puVar1 = param_1 + 2;
      *param_1 = (unsigned int)(&DAT_003098a4);
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00165840(puVar1,0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
