/* HSTMATCH module=hstp_trans_main.prx start=0x002b0188 end=0x002b0194 symbol=FUN_002b0188 lang=c99 */
/* Clone of src/eboot/FUN_002a0d7c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
typedef float undefined4;


void FUN_002b0188(undefined4 param_1,undefined4 param_2,int param_3)
{
  *(undefined4 *)(param_3 + 0x13c) = param_1;
  *(undefined4 *)(param_3 + 0x140) = param_2;
  return;
}
