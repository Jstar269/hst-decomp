/* HSTMATCH module=hstp_trans_main.prx start=0x001329f8 end=0x00132a58 symbol=FUN_001329f8 lang=c99 */
/* Clone of src/eboot/FUN_00127788.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e47e8;
extern undefined4 DAT_003e47ec;
extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_000569f4();

void FUN_001329f8(void)
{
  if (DAT_003e47ec != 0) {
    if (DAT_003e47ec != 0) {
      FUN_000009e4(DAT_003e47ec + -0x10);
    }
    DAT_003e47ec = 0;
  }
  if (DAT_003e47e8 != 0) {
    FUN_000006e8(DAT_003e47e8,FUN_000569f4);
    DAT_003e47e8 = 0;
  }
  return;
}
