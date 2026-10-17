/* HSTMATCH module=hstp_trans_main.prx start=0x00225dec end=0x00225e04 symbol=FUN_00225dec lang=c99 */
/* Clone of src/eboot/FUN_00216de8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


int FUN_00225dec(uint param_1)
{
  int iVar1;
  
  iVar1 = (int)param_1 >> 1;
  if ((param_1 & 1) != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}
