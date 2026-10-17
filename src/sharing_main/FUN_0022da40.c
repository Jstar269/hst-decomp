/* HSTMATCH module=hstp_trans_main.prx start=0x0022da40 end=0x0022da94 symbol=FUN_0022da40 lang=c99 */
/* Clone of src/eboot/FUN_0021e4cc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_002bf370();

void FUN_0022da40(int param_1,undefined1 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x1e4) = param_2;
  *(undefined1 *)(param_1 + 0x208) = 1;
  if ((param_3 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x200), iVar1 = FUN_002bf370(*(int *)(param_1 + 0x170)),
     iVar2 >= iVar1)) {
    *(undefined1 *)(param_1 + 0x208) = 0;
  }
  return;
}
