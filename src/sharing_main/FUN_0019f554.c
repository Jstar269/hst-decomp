/* HSTMATCH module=hstp_trans_main.prx start=0x0019f554 end=0x0019f59c symbol=FUN_0019f554 lang=c99 */
/* Clone of src/eboot/FUN_00192d44.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_0019f38c();
extern undefined4 * FUN_0019f7c8();

undefined4 * FUN_0019f554(undefined4 *param_1)
{
  FUN_0019f7c8(param_1 + 1);
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_0019f38c(param_1 + 8);
  FUN_0019f38c(param_1 + 0x2c);
  *param_1 = 0;
  return param_1;
}
