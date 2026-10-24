/* HSTMATCH module=EBOOT.BIN start=0x001b6f68 end=0x001b7100 symbol=FUN_001b6f68 lang=c99 */
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

extern undefined4 DAT_003386b0;
extern undefined4 DAT_00338b44;
extern void FUN_000623f0(undefined4 param_1);
extern undefined4 FUN_000def0c(int param_1);
extern bool FUN_000def58(int param_1);
extern undefined4 FUN_001b1f84(int *param_1,int *param_2);
extern undefined4 FUN_001b2040(undefined4 param_1,int *param_2,int *param_3);
extern undefined4 FUN_001b2bb8(int *param_1,int param_2);
extern int FUN_001b413c(float param_1,undefined4 param_2,int *param_3);
extern void FUN_001b41c8(int *param_1);
extern void FUN_001b4418(float param_1,undefined4 param_2,int *param_3);
extern undefined4 FUN_001b4458(int *param_1);
extern void FUN_001b871c(int param_1);
extern void FUN_001b94f8(undefined4 *param_1,int *param_2,int *param_3,undefined4 *param_4);

void FUN_001b6f68(int param_1)
{
  int iVar1;
  int local_c;
  undefined4 local_8;
  undefined1 auStack_4 [4];
  
  if ((*(char *)(DAT_00338b44 + 0xb0) != '\0') && (*(int *)(DAT_003386b0 + 0x40) != 7)) {
    if ((*(int *)(DAT_00338b44 + 0xa4) != 0) && (*(int *)(DAT_00338b44 + 0xa4) != 1)) {
      FUN_001b2bb8((int *)(0x34179c),(int)(0x99));
      if (-1 < *(int *)(param_1 + 0x54)) {
        FUN_001b1f84((int *)(0x34179c),(int *)(param_1 + 0x54));
        *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x80) = 3;
    }
    iVar1 = FUN_000def0c((int)(DAT_00338b44));
    if ((iVar1 != 0) && (FUN_001b413c((float)(0),(undefined4)(0x3cf5c28f),(int *)(0x34179c)), *(char *)(param_1 + 0x78) == '\0')) {
      FUN_001b4418((float)(0),(undefined4)(0x3cf5c28f),(int *)(0x34179c));
    }
  }
  iVar1 = FUN_001b4458((int *)(0x34179c));
  if ((iVar1 == 0x25) && (*(int *)(DAT_003386b0 + 0x40) != 7)) {
    FUN_001b41c8((int *)(0x34179c));
  }
  iVar1 = FUN_000def58((int)(DAT_00338b44));
  if (iVar1 != 0) {
    FUN_000623f0((undefined4)(3));
  }
  FUN_001b871c((int)(param_1));
  FUN_001b2040((undefined4)(0x3f000000),(int *)(0x34179c),(int *)(param_1 + 100));
  local_c = param_1 + 0x40;
  local_8 = *(undefined4 *)(param_1 + 0x44);
  FUN_001b94f8((undefined4 *)(auStack_4),(int *)(param_1 + 0x3c),(int *)(&local_8),(undefined4 *)(&local_c));
  return;
}
// near miss from lane fm9 (unreviewed)
