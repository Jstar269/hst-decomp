/* HSTMATCH module=EBOOT.BIN start=0x001420a4 end=0x001424c4 symbol=FUN_001420a4 lang=c99 */
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
extern char DAT_002dbb3c[];
extern char DAT_002dbb58[];
extern void FUN_00003268();
extern int FUN_00004138();
extern undefined4 FUN_000041ec();
extern void FUN_000104e0();
extern void FUN_000143b0();
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

void FUN_001420a4(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined1 auStack_100 [256];
  undefined1 auStack_110 [16];
  undefined4 local_114;
  undefined4 local_118;
  int local_11c;
  undefined1 local_120;
  undefined4 local_124;
  undefined4 local_128;
  undefined4 local_12c;
  undefined4 local_130;
  undefined4 local_134;
  undefined4 local_138;
  int local_140;
  undefined4 local_144;
  int local_148;
  int local_14c;
  int local_178;
  undefined1 local_17c;
  undefined4 local_180;
  int local_184;
  undefined4 local_188;
  int local_18c;
  int local_190;
  undefined4 local_194;
  int local_198;
  int local_19c;
  int local_1a0;
  
  FUN_00146ee0(param_1 + 0x8c8,*(undefined4 *)(param_1 + 0x8cc),0);
  FUN_001472b8(param_1 + 0x8d4,*(undefined4 *)(param_1 + 0x8d8),0);
  FUN_000143b0(auStack_100,DAT_002dbb3c,param_1 + 0xd68,param_1 + 0xd28,
               *(undefined4 *)(param_1 + 0xd24));
  FUN_000649c0(auStack_110);
  FUN_00064bf4(auStack_110,auStack_100,1,&DAT_002dbb34);
  iVar8 = 0;
  iVar2 = FUN_000650e0(auStack_110);
  if (0 < iVar2) {
    do {
      local_138 = 0;
      local_134 = 0;
      local_130 = 0;
      uVar3 = FUN_0006517c(auStack_110,iVar8,0);
      FUN_00003268(&local_138,uVar3);
      local_12c = FUN_00065104(auStack_110,iVar8,1);
      local_128 = FUN_00065104(auStack_110,iVar8,2);
      local_124 = FUN_00065104(auStack_110,iVar8,3);
      iVar2 = FUN_00065104(auStack_110,iVar8,4);
      local_120 = iVar2 != 0;
      local_118 = FUN_00065140(auStack_110,iVar8,5);
      local_114 = FUN_00065140(auStack_110,iVar8,6);
      local_11c = FUN_00065104(auStack_110,iVar8,7);
      if (*(int *)(param_1 + 0x8cc) == 0) {
        if (*(uint *)(param_1 + 0x8cc) < *(uint *)(param_1 + 0x8d0)) {
          iVar2 = *(int *)(param_1 + 0x8c8) + *(uint *)(param_1 + 0x8cc) * 0x28;
          if (iVar2 == 0) {
            iVar2 = *(int *)(param_1 + 0x8cc);
          }
          else {
            FUN_000041ec(iVar2,&local_138);
            *(undefined4 *)(iVar2 + 0xc) = local_12c;
            *(undefined4 *)(iVar2 + 0x10) = local_128;
            *(undefined4 *)(iVar2 + 0x14) = local_124;
            *(undefined1 *)(iVar2 + 0x18) = local_120;
            *(int *)(iVar2 + 0x1c) = local_11c;
            *(undefined4 *)(iVar2 + 0x20) = local_118;
            *(undefined4 *)(iVar2 + 0x24) = local_114;
            iVar2 = *(int *)(param_1 + 0x8cc);
          }
          *(int *)(param_1 + 0x8cc) = iVar2 + 1;
        }
        else {
          FUN_00146dd8(param_1 + 0x8c8,&local_138,0);
        }
      }
      else {
        iVar2 = *(int *)(param_1 + 0x8c8);
        iVar7 = iVar2 + *(int *)(param_1 + 0x8cc) * 0x28;
        if (iVar2 != iVar7) {
          iVar5 = *(int *)(iVar2 + 0x1c);
          while( true ) {
            iVar1 = iVar2;
            if (local_11c <= iVar5) {
              iVar1 = local_140;
            }
            local_140 = iVar1;
            if (iVar2 + 0x28 == iVar7) break;
            iVar5 = *(int *)(iVar2 + 0x44);
            iVar2 = iVar2 + 0x28;
          }
        }
        local_14c = local_140 + 0x28;
        local_148 = local_14c;
        FUN_00146f64(param_1 + 0x8c8,local_14c,&local_138,0);
      }
      FUN_00004138(&local_138,0xffffffff);
      iVar8 = iVar8 + 1;
      iVar2 = FUN_000650e0(auStack_110);
    } while (iVar8 < iVar2);
  }
  FUN_000143b0(auStack_100,DAT_002dbb58,param_1 + 0xd68,param_1 + 0xd28);
  local_144 = 0;
  piVar4 = (int *)FUN_0004cad0(auStack_100,&local_144,0x10,1);
  if (piVar4 != (int *)0x0) {
    iVar2 = *piVar4;
    piVar9 = piVar4 + 1;
    iVar8 = 0;
    if (0 < iVar2) {
      local_18c = *piVar9;
      while( true ) {
        local_1a0 = piVar9[1];
        local_19c = piVar9[2];
        local_198 = piVar9[3];
        local_194 = 0x3f800000;
        local_190 = piVar9[4];
        local_17c = 1;
        local_188 = 0;
        local_180 = 0;
        piVar9 = piVar9 + 5;
        if (*(uint *)(param_1 + 0x8d8) < *(uint *)(param_1 + 0x8dc)) {
          piVar6 = (int *)(*(int *)(param_1 + 0x8d4) + *(uint *)(param_1 + 0x8d8) * 0x30);
          if (piVar6 == (int *)0x0) {
            iVar7 = *(int *)(param_1 + 0x8d8);
          }
          else {
            *piVar6 = local_1a0;
            piVar6[1] = local_19c;
            piVar6[2] = local_198;
            piVar6[3] = 0x3f800000;
            piVar6[4] = local_190;
            piVar6[5] = local_18c;
            piVar6[6] = 0;
            piVar6[7] = local_184;
            piVar6[8] = 0;
            *(undefined1 *)(piVar6 + 9) = 1;
            piVar6[10] = local_178;
            iVar7 = *(int *)(param_1 + 0x8d8);
          }
          *(int *)(param_1 + 0x8d8) = iVar7 + 1;
        }
        else {
          FUN_00147274(param_1 + 0x8d4,&local_1a0,0);
        }
        iVar8 = iVar8 + 1;
        if (iVar2 <= iVar8) break;
        local_18c = *piVar9;
      }
    }
    FUN_000104e0(piVar4);
  }
  FUN_00064a08(auStack_110,0xffffffff);
  return;
}
// near miss from lane fm11 (unreviewed)
