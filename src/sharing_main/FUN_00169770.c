/* HSTMATCH module=hstp_trans_main.prx start=0x00169770 end=0x00169790 symbol=FUN_00169770 lang=c99 */
/* Clone of src/eboot/FUN_0015d1c8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

undefined1 FUN_00169770(undefined4 param_1,int param_2)
{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (DAT_003e9740 != 0) {
    uVar1 = *(undefined1 *)(param_2 + DAT_003e9740 + 0x10);
  }
  return uVar1;
}
