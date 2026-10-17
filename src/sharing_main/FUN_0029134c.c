/* HSTMATCH module=hstp_trans_main.prx start=0x0029134c end=0x00291364 symbol=FUN_0029134c lang=c99 */
/* Clone of src/eboot/FUN_0027fed8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;


void FUN_0029134c(int *param_1,int param_2,undefined1 param_3)
{
  *param_1 = param_2;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)(param_1 + 3) = param_3;
  return;
}
