/* HSTMATCH module=hstp_trans_main.prx start=0x0019f834 end=0x0019f8b8 symbol=FUN_0019f834 lang=c99 */
/* Clone of src/eboot/FUN_00193024.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
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

extern undefined * DAT_003eaa70;
extern undefined4 DAT_003eaa88;
extern void FUN_001a2d70();

int FUN_0019f834(undefined4 param_1)
{
  int iVar1;
  int local_4;
  undefined4 local_8;

  local_8 = param_1;
  if (DAT_003eaa70 == 0) {
    goto ret0;
  }
  FUN_001a2d70(&local_4,DAT_003eaa88 + 0x30,&local_8);
  if (local_4 == DAT_003eaa88 + 0x34) {
    goto ret0;
  }
  iVar1 = *(int *)(DAT_003eaa70 + 4) + *(int *)(local_4 + 0x10) * 0x9c;
  return iVar1;
ret0:
  return 0;
}
