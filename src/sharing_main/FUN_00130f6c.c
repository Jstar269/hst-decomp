/* HSTMATCH module=hstp_trans_main.prx start=0x00130f6c end=0x00130fa8 symbol=FUN_00130f6c lang=c99 */
/* Clone of src/eboot/FUN_00125d38.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b12e4;
extern undefined4 * FUN_00061cb0();

undefined4 * FUN_00130f6c(undefined4 *param_1)
{
  FUN_00061cb0();
  *param_1 = (unsigned int)(&DAT_003b12e4);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  return param_1;
}
