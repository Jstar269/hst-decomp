/* HSTMATCH module=hstp_trans_main.prx start=0x0012f40c end=0x0012f43c symbol=FUN_0012f40c lang=c99 */
/* Clone of src/eboot/FUN_00124238.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0012f2d0();

void FUN_0012f40c(int param_1)
{
  FUN_0012f2d0(param_1,1,0);
  *(undefined4 *)(param_1 + 0x68) = 0;
  return;
}
