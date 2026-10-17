/* HSTMATCH module=hstp_trans_main.prx start=0x0011fe84 end=0x0011fec8 symbol=FUN_0011fe84 lang=c99 */
/* Clone of src/eboot/FUN_00115094.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0011eab8();

void FUN_0011fe84(int param_1,undefined4 param_2)
{
  *(undefined1 *)(*(int *)(param_1 + 0x54) + 0x90a) = 0;
  *(undefined4 *)(param_1 + 0x80) = param_2;
  FUN_0011eab8(param_1,5);
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}
