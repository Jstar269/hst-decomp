/* HSTMATCH module=hstp_trans_main.prx start=0x002411d0 end=0x00241214 symbol=FUN_002411d0 lang=c99 */
/* Clone of src/eboot/FUN_002310d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f398c;
extern void FUN_00241268();
extern void FUN_00241348();

undefined4 * FUN_002411d0(undefined4 *param_1,undefined1 param_2)
{
  *param_1 = 0;
  DAT_003f398c = (unsigned int)(param_1);
  *(undefined1 *)(param_1 + 2) = param_2;
  FUN_00241268();
  FUN_00241348(param_1,1);
  return param_1;
}
