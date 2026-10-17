/* HSTMATCH module=hstp_trans_main.prx start=0x001c744c end=0x001c7490 symbol=FUN_001c744c lang=c99 */
/* Clone of src/eboot/FUN_001b9760.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003b25c4;
extern undefined4 * FUN_0001ec44();

undefined4 * FUN_001c744c(undefined4 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b25c4);
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  param_1[0x11] = 0;
  return param_1;
}
