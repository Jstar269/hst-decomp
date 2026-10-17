/* HSTMATCH module=hstp_trans_main.prx start=0x002352c8 end=0x002352dc symbol=FUN_002352c8 lang=c99 */
/* Clone of src/eboot/FUN_00225d54.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0022fcdc();

void FUN_002352c8(int param_1,undefined4 param_2,undefined4 param_3)
{
  FUN_0022fcdc(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1c),param_2,1,param_3);
  return;
}
