/* HSTMATCH module=hstp_trans_main.prx start=0x000bf57c end=0x000bf5b0 symbol=FUN_000bf57c lang=c99 */
/* Clone of src/eboot/FUN_000bc108.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined4 DAT_003e1e04;
extern void FUN_000bf8a8();

void FUN_000bf57c(undefined4 param_1,undefined4 param_2)
{
  if (DAT_003e1e04 != 0) {
    FUN_000bf8a8(DAT_003e1e04,param_1,param_2);
  }
  return;
}
