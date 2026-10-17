/* HSTMATCH module=hstp_trans_main.prx start=0x0008eec4 end=0x0008ef48 symbol=FUN_0008eec4 lang=c99 */
/* Clone of src/eboot/FUN_0008d72c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
extern int FUN_000dbb20();

int FUN_0008eec4(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 + 0x280 != 0) {
      FUN_000dbb20(param_1 + 0x280,0xffffffff);
    }
    if (param_1 + 0x160 != 0) {
      FUN_000dbb20(param_1 + 0x160,0xffffffff);
    }
    if (param_1 + 0x40 != 0) {
      FUN_000dbb20(param_1 + 0x40,0xffffffff);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
