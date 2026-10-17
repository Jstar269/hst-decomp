/* HSTMATCH module=hstp_trans_main.prx start=0x0013a414 end=0x0013a450 symbol=FUN_0013a414 lang=c99 */
/* Clone of src/eboot/FUN_0012eebc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e48b8;
extern void FUN_0016be80();

void FUN_0013a414(int param_1)
{
  if ((*(int *)(param_1 + 0xe0) != 0) && (DAT_003e48b8 == 1)) {
    FUN_0016be80(*(int *)(param_1 + 0xe0));
  }
  return;
}
