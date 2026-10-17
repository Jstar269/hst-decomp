/* HSTMATCH module=hstp_trans_main.prx start=0x0023576c end=0x00235790 symbol=FUN_0023576c lang=c99 */
/* Clone of src/eboot/FUN_002261f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_0023576c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4, undefined4 *param_5)
{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  param_1[2] = *param_4;
  param_1[3] = *param_5;
  return;
}
