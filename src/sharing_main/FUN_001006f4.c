/* HSTMATCH module=hstp_trans_main.prx start=0x001006f4 end=0x00100728 symbol=FUN_001006f4 lang=c99 */
/* Clone of src/eboot/FUN_000fafb8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern void FUN_000fe984();

void FUN_001006f4(int param_1)
{
  if (*(int *)(DAT_003e19f0 + 0x3c) != 9) {
    FUN_000fe984(*(undefined4 *)(param_1 + 0x3c));
  }
  return;
}
