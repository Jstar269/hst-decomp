/* HSTMATCH module=hstp_trans_main.prx start=0x001303d4 end=0x001303e0 symbol=FUN_001303d4 lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e95c4;
extern void FUN_0013c750();

void FUN_001303d4(undefined4 param_1)
{
  FUN_0013c750(param_1,DAT_003e95c4);
  return;
}
