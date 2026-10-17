/* HSTMATCH module=EBOOT.BIN start=0x000462a0 end=0x00046300 symbol=FUN_000462a0 lang=c99 */
/* Clone of src/sharing_main/FUN_000463a0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00000a00();

uint * FUN_000462a0(uint *param_1,short param_2)
{
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 1) != 0) {
      FUN_00000a00(param_1[2]);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
