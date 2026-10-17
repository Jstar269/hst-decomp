/* HSTMATCH module=hstp_trans_main.prx start=0x00104d94 end=0x00104de0 symbol=FUN_00104d94 lang=c99 */
/* Clone of src/eboot/FUN_000ff4fc.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b0c40;
extern int FUN_00010184();

undefined4 * FUN_00104d94(undefined4 *param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  *param_1 = (unsigned int)(&DAT_003b0c40);
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar1 = FUN_00010184(0x40);
  param_1[1] = uVar1;
  return param_1;
}
