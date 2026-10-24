/* HSTMATCH module=EBOOT.BIN start=0x0015a844 end=0x0015aa1c symbol=FUN_0015a844 lang=c99 */
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

extern undefined * DAT_00340400;
extern undefined4 DAT_00340408;
extern void FUN_0015b6a4();
extern bool FUN_0015d16c();

undefined4 FUN_0015a844(int param_1)
{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 8) = 0x5a;
  bVar1 = *(byte *)(DAT_00340400 + 0xf0);
  if (DAT_00340408 == '\0') {
    if (((bVar1 & 1) == 0) || (iVar3 = FUN_0015d16c(param_1,0xd0), iVar3 != 0)) {
      if (((bVar1 & 2) == 0) || (iVar3 = FUN_0015d16c(param_1,0xd1), iVar3 != 0)) {
        if (((bVar1 & 4) == 0) || (iVar3 = FUN_0015d16c(param_1,0xd2), iVar3 != 0)) {
          if (((bVar1 & 8) == 0) || (iVar3 = FUN_0015d16c(param_1,0xd3), iVar3 != 0)) {
            if (((bVar1 & 0x10) == 0) || (iVar3 = FUN_0015d16c(param_1,0xd4), iVar3 != 0)) {
              *(undefined4 *)(param_1 + 4) = 0xffffffff;
              *(undefined4 *)(param_1 + 0x18) = 1;
            }
            else {
              *(undefined4 *)(param_1 + 4) = 0xd4;
              FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
            }
          }
          else {
            *(undefined4 *)(param_1 + 4) = 0xd3;
            FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
          }
        }
        else {
          *(undefined4 *)(param_1 + 4) = 0xd2;
          FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
        }
      }
      else {
        *(undefined4 *)(param_1 + 4) = 0xd1;
        FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
      }
      uVar2 = *(undefined4 *)(param_1 + 4);
    }
    else {
      *(undefined4 *)(param_1 + 4) = 0xd0;
      FUN_0015b6a4(param_1,*(undefined4 *)(param_1 + 4),0,1);
      uVar2 = *(undefined4 *)(param_1 + 4);
    }
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    FUN_0015b6a4(param_1,1,1,1);
    uVar2 = 0xd0;
  }
  return uVar2;
}
// near miss from lane fm9 (unreviewed)
