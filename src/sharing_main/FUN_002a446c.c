/* HSTMATCH module=hstp_trans_main.prx start=0x002a446c end=0x002a44b8 symbol=FUN_002a446c lang=c99 */
/* Clone of src/eboot/FUN_00292e60.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b30b4;
extern undefined4 * FUN_002a308c();

undefined4 * FUN_002a446c(undefined4 *param_1)
{
  FUN_002a308c();
  *param_1 = (unsigned int)(&DAT_003b30b4);
  *(undefined1 *)(param_1 + 0x13) = 0;
  *(undefined1 *)((int)param_1 + 0x4d) = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x4e) = 1;
  return param_1;
}
