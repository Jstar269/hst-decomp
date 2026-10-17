/* HSTMATCH module=hstp_trans_main.prx start=0x000e1d9c end=0x000e1e58 symbol=FUN_000e1d9c lang=c99 */
/* Clone of src/eboot/FUN_000ddbb0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e19f0;
extern int FUN_00089f84();

void FUN_000e1d9c(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = FUN_00089f84(DAT_003e19f0);
  if (param_3 == *(int *)(iVar1 + 0x144)) {
    *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 500) =
         *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 500) + 1;
    iVar1 = FUN_00089f84(DAT_003e19f0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f0) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f0) + 1;
    }
  }
  else {
    iVar1 = FUN_00089f84(DAT_003e19f0);
    if (param_2 == *(int *)(iVar1 + 0x144)) {
      *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f8) =
           *(int *)(*(int *)(DAT_003e19f0 + 0xa0) + 0x1f8) + 1;
    }
  }
  return;
}
