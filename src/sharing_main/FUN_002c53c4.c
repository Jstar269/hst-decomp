/* HSTMATCH module=hstp_trans_main.prx start=0x002c53c4 end=0x002c5450 symbol=FUN_002c53c4 lang=c99 */
/* Clone of src/eboot/FUN_002b56ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b32a0;
extern undefined4 DAT_003f491c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern undefined4 * FUN_000519d4();
extern void FUN_0005bbd8();

undefined4 * FUN_002c53c4(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b32a0);
    DAT_003f491c = 0;
    FUN_00000788(param_1 + 0x24,FUN_0005bbd8,0x70,0x14);
    FUN_000519d4(param_1 + 0x10,0xffffffff);
    FUN_0001ed28(param_1,0);
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
