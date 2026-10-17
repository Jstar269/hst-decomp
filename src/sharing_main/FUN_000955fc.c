/* HSTMATCH module=hstp_trans_main.prx start=0x000955fc end=0x00095674 symbol=FUN_000955fc lang=c99 */
/* Clone of src/eboot/FUN_000936d8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00059de4();

void FUN_000955fc(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059de4(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = 0;
  }
  return;
}
