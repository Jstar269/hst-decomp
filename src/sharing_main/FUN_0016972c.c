/* HSTMATCH module=hstp_trans_main.prx start=0x0016972c end=0x00169770 symbol=FUN_0016972c lang=c99 */
/* Clone of src/eboot/FUN_0015d184.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e9740;
extern undefined DAT_003ea34c;

void FUN_0016972c(undefined4 param_1,int param_2)
{
  byte bVar1;
  
  (&DAT_003ea34c)[param_2] = 1;
  bVar1 = *(byte *)(param_2 + DAT_003e9740 + 0x10);
  if (bVar1 < 0xc9) {
    *(byte *)(param_2 + DAT_003e9740 + 0x10) = bVar1 + 1;
  }
  return;
}
