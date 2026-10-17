/* HSTMATCH module=hstp_trans_main.prx start=0x00198190 end=0x00198214 symbol=FUN_00198190 lang=c99 */
/* Clone of src/eboot/FUN_0018b9e0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2428;
extern undefined4 DAT_003ea86c;
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern int FUN_0005c688();
extern void FUN_00198e40();

undefined4 * FUN_00198190(undefined4 *param_1,short param_2)
{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2428);
    FUN_00198e40();
    DAT_003ea86c = 0;
    if (param_1[0xf] != 0) {
      FUN_0005c688(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
