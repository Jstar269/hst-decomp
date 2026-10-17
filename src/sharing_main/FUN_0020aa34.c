/* HSTMATCH module=hstp_trans_main.prx start=0x0020aa34 end=0x0020aa8c symbol=FUN_0020aa34 lang=c99 */
/* Clone of src/eboot/FUN_001fc31c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b2800;
extern undefined4 * FUN_0001ec44();
extern void FUN_0020ae30();

undefined4 * FUN_0020aa34(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2800);
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_0020ae30(param_1,5);
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  return param_1;
}
