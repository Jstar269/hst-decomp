/* HSTMATCH module=hstp_trans_main.prx start=0x001d4720 end=0x001d474c symbol=FUN_001d4720 lang=c99 */
/* Clone of src/eboot/FUN_001c6328.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001668dc();

void FUN_001d4720(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x15c) + 0x58);
  if (iVar1 != 0) {
    FUN_001668dc(iVar1);
  }
  return;
}
