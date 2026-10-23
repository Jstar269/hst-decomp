/* HSTMATCH module=EBOOT.BIN start=0x0017523c end=0x00175464 symbol=FUN_0017523c lang=c99 */
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


void FUN_0017523c(char *param_1,ushort *param_2)
{
  char *iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = 0;
  for (iVar2 = 0, iVar1 = param_1; iVar2 < 5; iVar2 = iVar2 + 1, iVar1 = iVar1 + 0x14) {
    uVar3 = uVar5;
    switch (iVar2) {
      case 0:
        if (*(uint *)(iVar1 + 0x5dc) != 0) {
          iVar4 = 0;
          uVar3 = 0;
          while (((uint)*param_2 != **(uint **)(*(int *)(param_1 + 0x1e4) + iVar4) &&
                 (uVar6 = uVar3 + 1, uVar3 = uVar5, uVar6 < *(uint *)(iVar1 + 0x5dc)))) {
            iVar4 = uVar6 * 4;
            uVar3 = uVar6;
          }
        }
        break;
      case 1:
        uVar6 = 0;
        if (*(uint *)(iVar1 + 0x5dc) != 0) {
          iVar4 = 0;
          while ((uVar3 = uVar6, (uint)param_2[1] != **(uint **)(*(int *)(param_1 + 0x1fc) + iVar4)
                 && (uVar6 = uVar6 + 1, uVar3 = uVar5, uVar6 < *(uint *)(iVar1 + 0x5dc)))) {
            iVar4 = uVar6 * 4;
          }
        }
        break;
      case 2:
        uVar7 = *(uint *)(param_1 + 0x20c);
        *(uint *)(iVar1 + 0x5dc) = uVar7;
        uVar6 = 0;
        if (uVar7 != 0) {
          iVar4 = 0;
          while ((uVar3 = uVar6, (uint)param_2[2] != **(uint **)(*(int *)(param_1 + 0x208) + iVar4)
                 && (uVar6 = uVar6 + 1, uVar3 = uVar5, uVar6 < uVar7))) {
            iVar4 = uVar6 * 4;
          }
        }
        break;
      case 3:
        uVar6 = *(uint *)(param_1 + 0x20c);
        *(uint *)(iVar1 + 0x5dc) = uVar6;
        uVar7 = 0;
        if (uVar6 != 0) {
          iVar4 = 0;
          while ((uVar3 = uVar7, (uint)param_2[3] != **(uint **)(*(int *)(param_1 + 0x208) + iVar4)
                 && (uVar7 = uVar7 + 1, uVar3 = uVar5, uVar7 < uVar6))) {
            iVar4 = uVar7 * 4;
          }
        }
        break;
      case 4:
        *(undefined4 *)(iVar1 + 0x5dc) = 0;
        uVar3 = 0;
        break;
    }
    uVar5 = uVar3 & 3;
    if ((int)uVar3 < 0) {
      if (uVar5 != 0) {
        uVar5 = uVar5 - 4;
      }
      *(uint *)(iVar1 + 0x5cc) = uVar5;
    }
    else {
      *(uint *)(iVar1 + 0x5cc) = uVar5;
    }
    uVar5 = uVar3;
    if ((int)uVar3 < 0) {
      uVar5 = uVar3 + 3;
    }
    *(int *)(iVar1 + 0x5d0) = (int)uVar5 >> 2;
    uVar5 = *(uint *)(iVar1 + 0x5dc) >> 2;
    if ((*(uint *)(iVar1 + 0x5dc) & 3) != 0) {
      uVar5 = uVar5 + 1;
    }
    *(uint *)(iVar1 + 0x5d4) = uVar5;
    if (uVar5 < 4) {
      *(undefined4 *)(iVar1 + 0x5d8) = 0;
    }
    else if (*(int *)(iVar1 + 0x5d0) + 2 < (int)uVar5) {
      iVar4 = *(int *)(iVar1 + 0x5d0) + -1;
      *(int *)(iVar1 + 0x5d8) = iVar4;
      if (iVar4 < 0) {
        *(undefined4 *)(iVar1 + 0x5d8) = 0;
      }
    }
    else {
      *(uint *)(iVar1 + 0x5d8) = uVar5 - 3;
    }
    uVar5 = uVar3;
  }
  return;
}

// NEAR: 159/138 words, 155 differ. The ordered switch produces the retail
// reverse compare chain, but local register colors remain different: retail
// uses t4/t5/t6 for base/counter/result while this source uses t4/t3/t1. Tried
// the generated if chain, switch, for and do loops, char and int base pointers,
// declaration/init order changes, and temporary base/output pointers.
// near miss from lane km4 (unreviewed)
