/* HSTMATCH module=hstp_trans_main.prx start=0x001dbeec end=0x001dbf18 symbol=FUN_001dbeec lang=c99 */
/* Clone of src/eboot/FUN_001cd810.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b261c;

undefined4 * FUN_001dbeec(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b261c);
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}
