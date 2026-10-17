/* HSTMATCH module=hstp_trans_main.prx start=0x00138914 end=0x00138954 symbol=FUN_00138914 lang=c99 */
/* Clone of src/eboot/FUN_0012d414.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00055be8();

void FUN_00138914(int param_1,undefined4 param_2)
{
  FUN_00055be8(*(undefined4 *)(param_1 + 4));
  FUN_00055be8(*(undefined4 *)(param_1 + 0xc),param_2);
  return;
}
