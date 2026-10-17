/* HSTMATCH module=hstp_trans_main.prx start=0x0028de10 end=0x0028de54 symbol=FUN_0028de10 lang=c99 */
/* Clone of src/eboot/FUN_0027caa0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2f1c;
extern undefined4 * FUN_00061cb0();

undefined4 * FUN_0028de10(undefined4 *param_1)
{
  FUN_00061cb0();
  *param_1 = (unsigned int)(&DAT_003b2f1c);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x21] = 0x40000000;
  return param_1;
}
