/* HSTMATCH module=hstp_trans_main.prx start=0x001f52f8 end=0x001f5300 symbol=FUN_001f52f8 lang=c99 */
/* Clone of src/eboot/FUN_001e70e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0022d170();

void FUN_001f52f8(int param_1)
{
  FUN_0022d170(*(undefined4 *)(param_1 + 0x1d64));
  return;
}
