/* HSTMATCH module=hstp_trans_main.prx start=0x00225178 end=0x002251c8 symbol=FUN_00225178 lang=c99 */
/* Clone of src/eboot/FUN_00216174.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003f3488;
extern void FUN_0022520c();

undefined4 * FUN_00225178(undefined4 *param_1)
{
  DAT_003f3488 = (unsigned int)(param_1);
  FUN_0022520c();
  *param_1 = 0x41c00000;
  param_1[1] = 0x3eb851ec;
  param_1[2] = 0x3d23d70a;
  return param_1;
}
