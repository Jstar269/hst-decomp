/* HSTMATCH module=hstp_trans_main.prx start=0x001b7798 end=0x001b77d4 symbol=FUN_001b7798 lang=c99 */
/* Clone of src/eboot/FUN_001aa1cc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_00177234();
extern undefined4 FUN_001aa91c();

void FUN_001b7798(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001aa91c();
  iVar1 = FUN_00177234(*(undefined4 *)(iVar1 + 0x2e4));
  *(int *)(*(int *)(param_1 + 0x98) + 0x24) = *(int *)(*(int *)(param_1 + 0x98) + 0x28) + iVar1;
  return;
}
