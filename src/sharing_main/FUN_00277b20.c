/* HSTMATCH module=hstp_trans_main.prx start=0x00277b20 end=0x00277bc4 symbol=FUN_00277b20 lang=c99 */
/* Clone of src/eboot/FUN_00266ba4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2de4;
extern void FUN_00000a00();
extern int * FUN_000ed9b8();
extern undefined4 * FUN_00297f98();

undefined4 * FUN_00277b20(undefined4 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2de4);
    if ((char *)param_1 + 0x80 != (char *)0) {
      piVar1 = (int *)(param_1 + 0x41);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000ed9b8(piVar1,0);
      }
      piVar1 = (int *)(param_1 + 0x3c);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000ed9b8(piVar1,0);
      }
    }
    FUN_00297f98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
