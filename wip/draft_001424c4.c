/* HSTMATCH module=EBOOT.BIN start=0x001424c4 end=0x001428d4 symbol=FUN_001424c4 lang=c99 */
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

extern undefined DAT_002dbb34;
extern void FUN_00003268();
extern int FUN_00004138();
extern undefined4 FUN_000041ec();
extern void FUN_000104e0();
extern uint FUN_0004cad0();
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern undefined4 FUN_00064bf4();
extern undefined4 FUN_000650e0();
extern int FUN_00065104();
extern int FUN_00065140();
extern int FUN_0006517c();
extern void FUN_00146dd8();
extern void FUN_00146ee0();
extern uint FUN_00146f64();
extern void FUN_00147274();
extern void FUN_001472b8();

void FUN_001424c4(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined1 auStack_10 [16];
  undefined4 local_14;
  undefined4 local_18;
  int local_1c;
  undefined1 local_20;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  int local_40;
  undefined4 local_44;
  int local_48;
  int local_4c;
  int local_78;
  undefined1 local_7c;
  undefined4 local_80;
  int local_84;
  undefined4 local_88;
  int local_8c;
  int local_90;
  undefined4 local_94;
  int local_98;
  int local_9c;
  int local_a0;
  
  FUN_00146ee0(param_1 + 0x8c8,*(undefined4 *)(param_1 + 0x8cc),0);
  FUN_001472b8(param_1 + 0x8d4,*(undefined4 *)(param_1 + 0x8d8),0);
  FUN_000649c0(auStack_10);
  cVar2 = FUN_00064bf4(auStack_10,param_2,1,&DAT_002dbb34);
  if (cVar2 == '\0') {
    FUN_00064a08(auStack_10,0xffffffff);
  }
  else {
    iVar9 = 0;
    iVar3 = FUN_000650e0(auStack_10);
    if (0 < iVar3) {
      do {
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        uVar4 = FUN_0006517c(auStack_10,iVar9,0);
        FUN_00003268(&local_38,uVar4);
        local_2c = FUN_00065104(auStack_10,iVar9,1);
        local_28 = FUN_00065104(auStack_10,iVar9,2);
        local_24 = FUN_00065104(auStack_10,iVar9,3);
        iVar3 = FUN_00065104(auStack_10,iVar9,4);
        local_20 = iVar3 != 0;
        local_18 = FUN_00065140(auStack_10,iVar9,5);
        local_14 = FUN_00065140(auStack_10,iVar9,6);
        local_1c = FUN_00065104(auStack_10,iVar9,7);
        if (*(int *)(param_1 + 0x8cc) == 0) {
          if (*(uint *)(param_1 + 0x8cc) < *(uint *)(param_1 + 0x8d0)) {
            iVar3 = *(int *)(param_1 + 0x8c8) + *(uint *)(param_1 + 0x8cc) * 0x28;
            if (iVar3 == 0) {
              iVar3 = *(int *)(param_1 + 0x8cc);
            }
            else {
              FUN_000041ec(iVar3,&local_38);
              *(undefined4 *)(iVar3 + 0xc) = local_2c;
              *(undefined4 *)(iVar3 + 0x10) = local_28;
              *(undefined4 *)(iVar3 + 0x14) = local_24;
              *(undefined1 *)(iVar3 + 0x18) = local_20;
              *(int *)(iVar3 + 0x1c) = local_1c;
              *(undefined4 *)(iVar3 + 0x20) = local_18;
              *(undefined4 *)(iVar3 + 0x24) = local_14;
              iVar3 = *(int *)(param_1 + 0x8cc);
            }
            *(int *)(param_1 + 0x8cc) = iVar3 + 1;
          }
          else {
            FUN_00146dd8(param_1 + 0x8c8,&local_38,0);
          }
        }
        else {
          iVar3 = *(int *)(param_1 + 0x8c8);
          iVar6 = iVar3 + *(int *)(param_1 + 0x8cc) * 0x28;
          if (iVar3 != iVar6) {
            iVar7 = *(int *)(iVar3 + 0x1c);
            while( true ) {
              iVar1 = iVar3;
              if (local_1c <= iVar7) {
                iVar1 = local_40;
              }
              local_40 = iVar1;
              if (iVar3 + 0x28 == iVar6) break;
              iVar7 = *(int *)(iVar3 + 0x44);
              iVar3 = iVar3 + 0x28;
            }
          }
          local_4c = local_40 + 0x28;
          local_48 = local_4c;
          FUN_00146f64(param_1 + 0x8c8,local_4c,&local_38,0);
        }
        FUN_00004138(&local_38,0xffffffff);
        iVar9 = iVar9 + 1;
        iVar3 = FUN_000650e0(auStack_10);
      } while (iVar9 < iVar3);
    }
    local_44 = 0;
    piVar5 = (int *)FUN_0004cad0(param_3,&local_44,0x10,1);
    if (piVar5 != (int *)0x0) {
      iVar3 = *piVar5;
      piVar10 = piVar5 + 1;
      iVar9 = 0;
      if (0 < iVar3) {
        local_8c = *piVar10;
        while( true ) {
          local_a0 = piVar10[1];
          local_9c = piVar10[2];
          local_98 = piVar10[3];
          local_94 = 0x3f800000;
          local_90 = piVar10[4];
          local_7c = 1;
          local_88 = 0;
          local_80 = 0;
          piVar10 = piVar10 + 5;
          if (*(uint *)(param_1 + 0x8d8) < *(uint *)(param_1 + 0x8dc)) {
            piVar8 = (int *)(*(int *)(param_1 + 0x8d4) + *(uint *)(param_1 + 0x8d8) * 0x30);
            if (piVar8 == (int *)0x0) {
              iVar6 = *(int *)(param_1 + 0x8d8);
            }
            else {
              *piVar8 = local_a0;
              piVar8[1] = local_9c;
              piVar8[2] = local_98;
              piVar8[3] = 0x3f800000;
              piVar8[4] = local_90;
              piVar8[5] = local_8c;
              piVar8[6] = 0;
              piVar8[7] = local_84;
              piVar8[8] = 0;
              *(undefined1 *)(piVar8 + 9) = 1;
              piVar8[10] = local_78;
              iVar6 = *(int *)(param_1 + 0x8d8);
            }
            *(int *)(param_1 + 0x8d8) = iVar6 + 1;
          }
          else {
            FUN_00147274(param_1 + 0x8d4,&local_a0,0);
          }
          iVar9 = iVar9 + 1;
          if (iVar3 <= iVar9) break;
          local_8c = *piVar10;
        }
      }
      FUN_000104e0(piVar5);
    }
    FUN_00064a08(auStack_10,0xffffffff);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
