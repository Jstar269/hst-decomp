/* HSTMATCH module=hstp_trans_main.prx start=0x00120ce4 end=0x00120cf8 symbol=FUN_00120ce4 lang=c99 */
/* Clone of src/eboot/FUN_00115dc8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
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


void FUN_00120ce4(int param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4, undefined2 param_5,undefined2 param_6)
{
  *(undefined2 *)(param_1 + 0x130) = param_3;
  *(undefined2 *)(param_1 + 0x132) = param_4;
  *(undefined2 *)(param_1 + 0x134) = param_5;
  *(undefined2 *)(param_1 + 0x136) = param_6;
  return;
}
