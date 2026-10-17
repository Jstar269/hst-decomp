/* HSTMATCH module=hstp_trans_main.prx start=0x00159ccc end=0x00159d14 symbol=FUN_00159ccc lang=c99 */
/* Clone of src/eboot/FUN_0014de24.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b15c0;
extern undefined DAT_003b16d8;
extern undefined2 FUN_0015b050();

undefined4 * FUN_00159ccc(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b15c0);
  FUN_0015b050(param_2);
  return param_1;
}
