/* HSTMATCH module=hstp_trans_main.prx start=0x00131e9c end=0x00131f8c symbol=FUN_00131e9c lang=c99 */
/* Clone of src/eboot/FUN_00126c2c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the member sub-object null test restored (Ghidra folded its offset into the compared constant); exact match verified; names and types await human review. */
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

extern undefined DAT_003b131c;
extern undefined DAT_003b1330;
extern char DAT_00381854[];
extern void FUN_00000a00();
extern undefined4 * FUN_00093544();
extern int FUN_000dbb20();
extern int * FUN_000ed9b8();
extern void FUN_00131f8c();
extern undefined4 * FUN_00297f98();

undefined4 * FUN_00131e9c(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b131c);
    param_1[0x38] = (unsigned int)(&DAT_003b1330);
    FUN_00131f8c(DAT_00381854);
    puVar1 = param_1 + 0x105;
    if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
      FUN_000ed9b8(puVar1,0);
    }
    puVar1 = param_1 + 0xdc;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1 = param_1 + 0xfd;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_000ed9b8(puVar1,0);
      }
      puVar1 = param_1 + 0xf8;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_000ed9b8(puVar1,0);
      }
    }
    FUN_000dbb20(param_1 + 0x96,0xffffffff);
    FUN_00297f98(param_1 + 0x38,0);
    FUN_00093544(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
