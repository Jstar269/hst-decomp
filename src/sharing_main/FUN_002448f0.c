/* HSTMATCH module=hstp_trans_main.prx start=0x002448f0 end=0x0024492c symbol=FUN_002448f0 lang=c99 */
/* Clone of src/eboot/FUN_002347c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2b64;
extern undefined DAT_003b2b70;

undefined4 * FUN_002448f0(undefined4 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003b2b70);
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  *param_1 = (unsigned int)(&DAT_003b2b64);
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return param_1;
}
