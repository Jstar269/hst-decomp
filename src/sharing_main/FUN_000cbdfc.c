/* HSTMATCH module=hstp_trans_main.prx start=0x000cbdfc end=0x000cbe68 symbol=FUN_000cbdfc lang=c99 */
/* Clone of src/eboot/FUN_000c825c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
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

extern int * FUN_000008d8();
extern int FUN_00000a90();
extern void FUN_000577ec();
extern void FUN_00057904();

void FUN_000cbdfc(int param_1)
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1d0) == 0) {
    uVar1 = FUN_00000a90(0x6d0);
    uVar1 = (unsigned int)(FUN_000008d8(uVar1,FUN_000577ec,FUN_00057904,0x1b0,4));
    *(undefined4 *)(param_1 + 0x1d0) = uVar1;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    uVar1 = FUN_00000a90(4);
    *(undefined4 *)(param_1 + 0x1d4) = uVar1;
  }
  return;
}
