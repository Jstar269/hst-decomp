/* HSTMATCH module=hstp_trans_main.prx start=0x0008f7c8 end=0x0008f8c0 symbol=FUN_0008f7c8 lang=c99 */
/* Clone of src/eboot/FUN_0008df24.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b04f8;
extern undefined DAT_003b0504;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001ed28();
extern undefined4 * FUN_000519d4();
extern undefined4 * FUN_00057904();
extern int FUN_0006f6ec();
extern int * FUN_00092f18();
extern undefined4 * FUN_000c5c78();
extern void FUN_0005bbd8();

undefined4 * FUN_0008f7c8(undefined4 *param_1,short param_2)
{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b04f8);
    param_1[0x78] = (unsigned int)(&DAT_003b0504);
    FUN_00000788(param_1 + 0x128,FUN_0005bbd8,0x70,2);
    FUN_000519d4(param_1 + 0x114,0xffffffff);
    FUN_0006f6ec(param_1 + 0x112,0xffffffff);
    FUN_00057904(param_1 + 0xa4,0xffffffff);
    if ((char *)param_1 + 0x26c != (char *)0) {
      puVar1 = param_1 + 0x9e;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00092f18(puVar1,0);
      }
      puVar1 = param_1 + 0x9b;
      if ((puVar1 != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
        FUN_00092f18(puVar1,0);
      }
    }
    FUN_0001ed28(param_1 + 0x78,0);
    FUN_000c5c78(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
