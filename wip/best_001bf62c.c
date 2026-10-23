/* HSTMATCH module=EBOOT.BIN start=0x001bf62c end=0x001bf884 symbol=FUN_001bf62c lang=c99 */
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

extern int FUN_001bb8b8();
extern void FUN_001bbab8();
extern void FUN_001bf948();
extern void FUN_001bf980();
extern void FUN_001bf9b8();

void FUN_001bf62c(int param_1,int param_2,byte param_3)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar8;
  byte *pbVar6;
  byte *pbVar7;
  
  if ((param_2 >= 0) && (param_2 < 0xf)) {
    pbVar7 = (byte *)(param_1 + param_2 * 0x38 + 4);
  }
  else {
    pbVar7 = (byte *)0x0;
  }
  if (pbVar7 != (byte *)0x0) {
    *pbVar7 = param_3;
    uVar8 = (uint)*pbVar7 - 4u;
    if (uVar8 < 2u) {
      iVar2 = FUN_001bb8b8(1,param_2);
      iVar3 = FUN_001bb8b8(1,param_2);
      iVar4 = FUN_001bb8b8(3,param_2);
      iVar5 = FUN_001bb8b8(4,param_2);
      if ((iVar2 >= 0) && (iVar2 < 0x280)) {
        pbVar6 = (byte *)(param_1 + iVar2 + 0x84c);
      }
      else {
        pbVar6 = (byte *)0x0;
      }
      uVar8 = (uint)(*pbVar6 - 4);
      if (uVar8 > 1u) {
        FUN_001bf948(param_1,iVar2,4);
      }
      if ((iVar3 >= 0) && (iVar3 < 0x280)) {
        pbVar6 = (byte *)(param_1 + iVar3 + 0xacc);
      }
      else {
        pbVar6 = (byte *)0x0;
      }
      uVar8 = (uint)(*pbVar6 - 4);
      if (uVar8 > 1u) {
        FUN_001bf980(param_1,iVar3,4);
      }
      if (iVar4 != 0) {
        if ((iVar4 >= 0) && (iVar4 < 0x280)) {
          pbVar6 = (byte *)(param_1 + iVar4 + 0xd4c);
        }
        else {
          pbVar6 = (byte *)0x0;
        }
        uVar8 = (uint)(*pbVar6 - 4);
      if (uVar8 > 1u) {
          FUN_001bf9b8(param_1,iVar4,4);
        }
      }
      if (iVar5 != 0) {
        if ((iVar5 >= 0) && (iVar5 < 0x280)) {
          pbVar6 = (byte *)(param_1 + iVar5 + 0xd4c);
        }
        else {
          pbVar6 = (byte *)0x0;
        }
        uVar8 = (uint)(*pbVar6 - 4);
      if (uVar8 > 1u) {
          FUN_001bf9b8(param_1,iVar5,4);
        }
      }
      if (param_2 == 0xb) {
        uVar8 = (uint)*(byte *)(param_1 + 0xacf) - 4u;
        if (uVar8 >= 2u) {
          FUN_001bf980(param_1,3,4);
        }
      }
    }
    uVar8 = (uint)*pbVar7 - 4u;
    if (uVar8 < 2u) {
      FUN_001bbab8(pbVar7);
    }
  }
  return;
}
// near miss from lane km4 (unreviewed)
