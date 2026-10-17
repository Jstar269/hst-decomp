/* HSTMATCH module=hstp_trans_main.prx start=0x00297450 end=0x00297494 symbol=FUN_00297450 lang=c99 */
/* Clone of src/eboot/FUN_00285e40.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e1e04;
extern void FUN_000c0484();
extern void FUN_0029693c();

void FUN_00297450(int param_1)
{
  if (DAT_003e1e04 != 0) {
    FUN_000c0484(DAT_003e1e04);
  }
  FUN_0029693c(param_1);
  return;
}
