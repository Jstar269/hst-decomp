/* HSTMATCH module=hstp_trans_main.prx start=0x000d8a24 end=0x000d8acc symbol=FUN_000d8a24 lang=c99 */
/* Clone of src/eboot/FUN_000d4d34.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0718;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern int FUN_000541d8();
extern int FUN_000569f4();
extern void FUN_00057904();

undefined4 * FUN_000d8a24(undefined4 *param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0718);
    if (param_1[0xf] != 0) {
      FUN_000541d8(param_1[0xf],1);
      param_1[0xf] = 0;
    }
    iVar1 = param_1[0x10];
    if (iVar1 != 0) {
      FUN_000569f4(iVar1,1);
      param_1[0x10] = 0;
    }
    FUN_00000788(param_1 + 0x14,FUN_00057904,0x1b0,4);
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
