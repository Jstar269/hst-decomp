/* HSTMATCH module=EBOOT.BIN start=0x00245c70 end=0x0024627c symbol=FUN_00245c70 lang=c99 */
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

extern undefined4 DAT_002f862c;
extern undefined * DAT_003386b0;
extern undefined * DAT_003402a0;
extern undefined4 * FUN_00022434();
extern undefined4 FUN_000224d8();
extern float FUN_00022e44(float param_1);
extern int FUN_001b1f7c();
extern undefined4 FUN_001b1f84();
extern void FUN_00245b04();

undefined4 FUN_00245c70(int param_1,int param_2)
{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  uint local_4;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  undefined4 local_44;
  undefined4 local_48;
  undefined4 local_4c;
  undefined4 local_50;
  undefined4 local_54;
  undefined4 local_58;
  undefined4 local_5c;
  undefined4 local_60;
  undefined4 local_64;
  undefined4 local_68;
  undefined4 local_6c;
  undefined4 local_70;
  
  if (param_2 == 0x11) {
    *(undefined1 *)(param_1 + 0x328) = 0;
  }
  else if (param_2 == 0x18) {
    FUN_00245b04();
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  else {
    if (param_2 == 0x12) {
      uVar5 = *(undefined4 *)(param_1 + 0x2d8);
    }
    else {
      if (param_2 != 0x10) {
        if (param_2 == 0xd) {
          return 0;
        }
        if (param_2 == 0xe) {
          uVar5 = *(undefined4 *)(param_1 + 0x2d8);
        }
        else {
          if (param_2 != 0x16) {
            if (param_2 == 0xc) {
              return 0;
            }
            if (param_2 == 0xb) {
              return 0;
            }
            if (param_2 == 10) {
              return 0;
            }
            if (param_2 == 9) {
              return 0;
            }
            if (param_2 != 8) {
              if (param_2 != 4) {
                return 0;
              }
              *(undefined1 *)(param_1 + 0x300) = 1;
              return 0;
            }
            *(undefined1 *)(param_1 + 0x32a) = 0;
            iVar3 = FUN_001b1f7c(0x34179c,*(undefined4 *)(param_1 + 0x2d8));
            if (iVar3 != 0) {
              FUN_001b1f84(0x34179c,param_1 + 0x2d8);
            }
            uVar5 = *(undefined4 *)(param_1 + 0x2dc);
            iVar3 = FUN_001b1f7c(0x34179c,uVar5);
            if (iVar3 != 0) {
              FUN_001b1f84(0x34179c,param_1 + 0x2dc);
            }
            cVar1 = *(char *)(param_1 + 0x268);
            if (cVar1 == '\0') {
              iVar3 = *(int *)(param_1 + 0x50);
            }
            else {
              *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
              uVar6 = *(int *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
              *(uint *)(DAT_003402a0 + 0x1360) = uVar6;
              *(byte *)(param_1 + 0x3c) =
                   *(byte *)(param_1 + 0x3c) |
                   (int)(((uVar6 >> 0x10) & 0x7fff) % 100) < *(int *)(param_1 + 0x44) * 0x14;
              *(undefined1 *)(param_1 + 0x268) = 0;
              if (*(char *)(param_1 + 0x3c) != '\0') {
                *(undefined4 *)(param_1 + 0x44) = 0;
                FUN_00245b04(param_1);
              }
              iVar3 = *(int *)(param_1 + 0x50);
            }
            if (iVar3 < 1) {
              uVar4 = *(undefined1 *)(param_1 + 0x3c);
            }
            else {
              if (*(int *)(param_1 + 0x260) == 0x2b) {
                *(undefined4 *)(param_1 + 0x50) = 0;
                *(undefined1 *)(param_1 + 0x3c) = 1;
                *(undefined4 *)(param_1 + 0x2cc) = 1;
                *(undefined4 *)(param_1 + 0x2d0) = 0;
              }
              else {
                *(undefined1 *)(param_1 + 0x3c) = 0;
              }
              uVar4 = *(undefined1 *)(param_1 + 0x3c);
            }
            *(undefined1 *)(param_1 + 0x3d) = uVar4;
            *(int *)(param_1 + 0x2e0) = *(int *)(param_1 + 0x2e0) + *(int *)(param_1 + 0x2e4);
            iVar3 = *(int *)(param_1 + 0x2ac);
            if (((iVar3 == 4) || (iVar3 == 5)) || (iVar3 == 7)) {
              *(undefined4 *)(param_1 + 0x4c) = 0xffffffff;
              if (*(int *)(param_1 + 0x40) == 1) {
                *(undefined4 *)(param_1 + 0x50) = 0;
              }
              else if (*(int *)(param_1 + 0x260) != 0xd) {
                *(undefined4 *)(param_1 + 0x50) = 0;
              }
              *(undefined1 *)(param_1 + 0x3c) = 1;
              if (*(int *)(param_1 + 0x2ac) == 7) {
                FUN_00245b04(param_1);
              }
              iVar3 = *(int *)(param_1 + 0x324);
            }
            else {
              iVar3 = *(int *)(param_1 + 0x324);
            }
            if (iVar3 != 1) {
              return 0;
            }
            *(undefined4 *)(param_1 + 0x324) = 2;
            return 0;
          }
          uVar5 = *(undefined4 *)(param_1 + 0x2d8);
        }
        iVar3 = FUN_001b1f7c(0x34179c,uVar5);
        if (iVar3 != 0) {
          FUN_001b1f84(0x34179c,param_1 + 0x2d8);
        }
        uVar5 = *(undefined4 *)(param_1 + 0x2dc);
        iVar3 = FUN_001b1f7c(0x34179c,uVar5);
        if (iVar3 != 0) {
          FUN_001b1f84(0x34179c,param_1 + 0x2dc);
        }
        if (*(int *)(*(int *)(DAT_003386b0 + 0x9c) + 0x58) < *(int *)(param_1 + 0x4c)) {
          if (*(char *)(param_1 + 0x3d) != '\0') {
            FUN_00245b04(param_1);
            *(undefined1 *)(param_1 + 0x3c) = 1;
            *(undefined1 *)(param_1 + 0x3d) = *(undefined1 *)(param_1 + 0x3c);
          }
          iVar3 = *(int *)(param_1 + 0x2ac);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x2ac);
        }
        if (iVar3 == 6) {
          fVar9 = 0.0f;
          iVar3 = 0;
          uVar6 = 1;
          if (1 < *(int *)(param_1 + 0x2a4) - 1U) {
            do {
              FUN_00022434(&local_50,*(undefined4 *)(*(int *)(param_1 + 0x2a0) + (uVar6 + 1) * 4),
                           *(undefined4 *)(*(int *)(param_1 + 0x2a0) + uVar6 * 4));
              local_18 = local_48;
              local_20 = local_50;
              local_1c = local_4c;
              local_14 = local_44;
              uVar5 = FUN_000224d8(&local_20,&local_20);
              fVar8 = (float)FUN_00022e44(uVar5);
              fVar9 = fVar9 + fVar8;
              uVar6 = uVar6 + 1;
              iVar3 = iVar3 + 1;
            } while (uVar6 < *(int *)(param_1 + 0x2a4) - 1U);
          }
          iVar7 = *(int *)(param_1 + 0x2d0) + *(int *)(*(int *)(DAT_003386b0 + 0x9c) + 0x58);
          local_4 = *(int *)(param_1 + 0x2d4) +
                    iVar7 / ((int)((fVar9 / (float)iVar3) / *(float *)(param_1 + 0x2b8)) << 1);
          if ((int)local_4 < DAT_002f862c) {
            puVar2 = (uint *)&DAT_002f862c;
          }
          else {
            puVar2 = &local_4;
          }
          uVar6 = *puVar2;
          *(uint *)(param_1 + 0x2cc) = uVar6;
          uVar6 = uVar6 % *(uint *)(param_1 + 0x2a4);
          if (uVar6 == 0) {
            uVar6 = 1;
          }
          if (uVar6 == *(uint *)(param_1 + 0x2a4) - 1) {
            FUN_00022434(&local_70,*(undefined4 *)(*(int *)(param_1 + 0x2a0) + 4),
                         *(undefined4 *)(*(int *)(param_1 + 0x2a0) + uVar6 * 4));
            local_38 = local_68;
            local_40 = local_70;
            local_3c = local_6c;
            local_34 = local_64;
            uVar5 = FUN_000224d8(&local_40,&local_40);
            fVar8 = (float)FUN_00022e44(uVar5);
            fVar9 = *(float *)(param_1 + 0x2b8);
          }
          else {
            FUN_00022434(&local_60,*(undefined4 *)(*(int *)(param_1 + 0x2a0) + (uVar6 + 1) * 4),
                         *(undefined4 *)(*(int *)(param_1 + 0x2a0) + uVar6 * 4));
            local_28 = local_58;
            local_30 = local_60;
            local_2c = local_5c;
            local_24 = local_54;
            uVar5 = FUN_000224d8(&local_30,&local_30);
            fVar8 = (float)FUN_00022e44(uVar5);
            fVar9 = *(float *)(param_1 + 0x2b8);
          }
          *(int *)(param_1 + 0x2c8) = iVar7 % ((int)(fVar8 / fVar9) << 1);
        }
        if (param_2 != 0xe) {
          return 0;
        }
        if (*(int *)(param_1 + 0x260) != 0x24) {
          return 0;
        }
        if (*(int *)(param_1 + 0x324) != 1) {
          return 0;
        }
        FUN_00245b04(param_1);
        *(undefined4 *)(param_1 + 0x324) = 0;
        return 0;
      }
      *(undefined1 *)(param_1 + 0x328) = 1;
      uVar5 = *(undefined4 *)(param_1 + 0x2d8);
    }
    iVar3 = FUN_001b1f7c(0x34179c,uVar5);
    if (iVar3 != 0) {
      FUN_001b1f84(0x34179c,param_1 + 0x2d8);
    }
    uVar5 = *(undefined4 *)(param_1 + 0x2dc);
    iVar3 = FUN_001b1f7c(0x34179c,uVar5);
    if (iVar3 != 0) {
      FUN_001b1f84(0x34179c,param_1 + 0x2dc);
    }
    *(undefined1 *)(param_1 + 0x300) = 0;
  }
  return 0;
}
// near miss from lane fm11 (unreviewed)
