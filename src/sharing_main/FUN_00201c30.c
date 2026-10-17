/* HSTMATCH module=hstp_trans_main.prx start=0x00201c30 end=0x00201ca4 symbol=FUN_00201c30 lang=c99 */
/* Clone of src/eboot/FUN_001f3770.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001f08bc();
extern undefined4 FUN_002015d8();
extern void FUN_00207b70();
extern void FUN_0020a040();

void FUN_00201c30(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_002015d8(param_1,*(undefined4 *)(param_1 + 0x40),0);
  if (iVar1 == 0x14) {
    FUN_00207b70(param_1);
  }
  else {
    if (iVar1 == 0xb) {
      FUN_001f08bc(*(undefined4 *)(param_1 + 0x510));
    }
    FUN_0020a040(param_1 + 0x3c,iVar1,1);
  }
  return;
}
