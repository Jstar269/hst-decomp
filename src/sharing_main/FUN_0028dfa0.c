/* HSTMATCH module=hstp_trans_main.prx start=0x0028dfa0 end=0x0028dfe4 symbol=FUN_0028dfa0 lang=c99 */
/* Clone of src/eboot/FUN_0027cc30.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2f00;
extern undefined4 * FUN_0001ec44();

undefined4 * FUN_0028dfa0(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2f00);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  return param_1;
}
