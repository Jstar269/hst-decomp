/* HSTMATCH module=hstp_trans_main.prx start=0x001e49b8 end=0x001e49e0 symbol=FUN_001e49b8 lang=c99 */
/* Clone of src/eboot/FUN_001d6bc8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2f7c;
extern undefined DAT_003b2f88;

undefined4 * FUN_001e49b8(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2f88);
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = (unsigned int)(&DAT_003b2f7c);
  return param_1;
}
