/* HSTMATCH module=hstp_trans_main.prx start=0x00095578 end=0x000955fc symbol=FUN_00095578 lang=c99 */
/* Clone of src/eboot/FUN_00093654.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00059d68();

void FUN_00095578(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 != 0) {
    FUN_00059d68(iVar1,0xffffffff);
    *(undefined4 *)(0xd0 + iVar1) = *(undefined4 *)(iVar1 + 0xc4);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 0) {
    FUN_00059d68(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(iVar1 + 0xc4);
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    FUN_00059d68(iVar1,0xffffffff);
    *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(iVar1 + 0xc4);
  }
  return;
}
