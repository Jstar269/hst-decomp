/* HSTMATCH module=hstp_trans_main.prx start=0x0020c850 end=0x0020c8ac symbol=FUN_0020c850 lang=c99 */
/* Clone of src/eboot/FUN_001fe080.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003751d4;
extern bool FUN_0001e6b0();

undefined1 FUN_0020c850(undefined4 param_1,undefined4 param_2,uint param_3)
{
  undefined1 uVar1;
  
  uVar1 = FUN_0001e6b0(DAT_003751d4,param_1,param_2,2,9);
  if ((*(uint *)(DAT_003751d4 + 0x80) & param_3) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}
