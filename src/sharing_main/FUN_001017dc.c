/* HSTMATCH module=hstp_trans_main.prx start=0x001017dc end=0x0010181c symbol=FUN_001017dc lang=c99 */
/* Clone of src/eboot/FUN_000fc0a0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_003b0e38;

undefined4 * FUN_001017dc(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b0e38);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[8] = 0x47c35000;
  *(undefined1 *)(param_1 + 9) = 0;
  return param_1;
}
