/* HSTMATCH module=hstp_trans_main.prx start=0x002b4168 end=0x002b41b0 symbol=FUN_002b4168 lang=c99 */
/* Clone of src/eboot/FUN_002a49d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b31ac;
extern undefined4 DAT_003f469c;
extern undefined4 * FUN_0001ec44();
extern void FUN_002b46a8();

undefined4 * FUN_002b4168(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b31ac);
  DAT_003f469c = (unsigned int)(param_1);
  FUN_002b46a8(param_1,0);
  return param_1;
}
