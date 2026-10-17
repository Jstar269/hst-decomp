/* HSTMATCH module=hstp_trans_main.prx start=0x001c0f48 end=0x001c0fa8 symbol=FUN_001c0f48 lang=c99 */
/* Clone of src/eboot/FUN_001b2e18.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00063304();

void FUN_001c0f48(int *param_1)
{
  int iVar2;
  int iVar1;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x2b4);
  }
  else {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(undefined4 *)(iVar2 + 0x2b0) = 0;
    }
  }
  if (((*(int *)(iVar2 + 0x2b4)) != 0) && ((*(int *)(iVar2 + 0x2b4)) != 0)) {
    FUN_00063304((*(int *)(iVar2 + 0x2b4)),1);
    *(undefined4 *)(iVar2 + 0x2b4) = 0;
  }
  return;
}
