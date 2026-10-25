/* HSTMATCH module=EBOOT.BIN start=0x0027e7d0 end=0x0027ed88 symbol=FUN_0027e7d0 lang=c99 */
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

extern undefined DAT_002fe798;
extern undefined DAT_002fe7c0;
extern undefined DAT_002fe7cc;
extern undefined DAT_002fe7d8;
extern undefined DAT_002fe7dc;
extern undefined DAT_002fe7e8;
extern undefined DAT_002fe7f8;
extern undefined DAT_002fe7fc;
extern undefined DAT_003070bc;
extern undefined DAT_00309c88;
extern char DAT_002fe79c[];
extern char DAT_002fe7c4[];
extern char DAT_002fe7d0[];
extern char DAT_002fe7e0[];
extern char DAT_002fe7f0[];
extern char DAT_002fe804[];
extern char DAT_002fe80c[];
extern char DAT_002fe824[];
extern char DAT_002fe83c[];
extern int FUN_0000d62c();
extern uint * FUN_000114c0();
extern int FUN_00014a40();
extern void FUN_0001cfa4();
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern undefined4 FUN_000650e0();
extern int FUN_00065104();
extern undefined4 FUN_000651b8();
extern undefined4 FUN_00065364();
extern undefined4 FUN_0006569c();
extern int FUN_00066338();
extern undefined4 * FUN_0008c230();
extern void FUN_001a5bcc();
extern void FUN_0027ed88();
extern void FUN_0027ee6c();
extern void FUN_0027eedc();
extern void FUN_0027f04c();

void FUN_0027e7d0(int param_1)
{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_10 [16];
  undefined1 auStack_20 [16];
  undefined *local_30 [4];
  undefined2 local_32;
  undefined2 local_54;
  undefined *local_58;
  int local_2058 [2048];
  
  FUN_000649c0(local_30);
  local_30[0] = &DAT_003070bc;
  FUN_0008c230(auStack_20);
  FUN_0008c230(auStack_10);
  iVar3 = FUN_000651b8(local_30,DAT_002fe79c,0,1,&DAT_002fe7c0);
  if (iVar3 != 0) {
    iVar11 = 1;
    iVar4 = FUN_000650e0(local_30);
    local_58 = &DAT_00309c88;
    iVar3 = 0;
    FUN_000114c0(&local_58,0,0x28);
    local_54 = 0xffff;
    local_32 = 0xffff;
    FUN_0027f04c(param_1 + 4,0x15,&local_58,0);
    iVar13 = 0;
    if (0 < iVar4 + -1) {
      do {
        iVar5 = FUN_0006569c(local_30,iVar11,DAT_002fe7c4);
        iVar6 = FUN_00014a40(iVar5);
        iVar5 = FUN_0000d62c(iVar5 + iVar6 + -3);
        iVar12 = *(int *)(param_1 + 4) + iVar5 * 0x28;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,&DAT_002fe7cc);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 4) = uVar2;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,DAT_002fe7d0);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 6) = uVar2;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,&DAT_002fe7d8);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 8) = uVar2;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,&DAT_002fe7dc);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 10) = uVar2;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,DAT_002fe7e0);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 0xc) = uVar2;
        uVar2 = 0;
        iVar6 = FUN_00065364(local_30,&DAT_002fe7e8);
        if (-1 < iVar6) {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
        }
        *(undefined2 *)(iVar12 + 0xe) = uVar2;
        iVar6 = FUN_00065364(local_30,DAT_002fe7f0);
        if (iVar6 < 0) {
          *(undefined2 *)(iVar12 + 0x10) = 0;
        }
        else {
          uVar2 = FUN_00065104(local_30,iVar11,iVar6);
          *(undefined2 *)(iVar12 + 0x10) = uVar2;
        }
        iVar6 = 0;
        do {
          uVar1 = 0;
          iVar7 = FUN_00065364(local_30,&DAT_002fe7f8);
          if (-1 < iVar7) {
            uVar1 = FUN_00065104(local_30,iVar11,iVar7 + iVar6);
          }
          *(undefined1 *)(iVar12 + iVar6 + 0x12) = uVar1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 10);
        iVar6 = 0;
        do {
          uVar1 = 0;
          iVar7 = FUN_00065364(local_30,&DAT_002fe7fc);
          if (-1 < iVar7) {
            uVar1 = FUN_00065104(local_30,iVar11,iVar7 + iVar6);
          }
          *(undefined1 *)(iVar12 + iVar6 + 0x1c) = uVar1;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 9);
        iVar6 = FUN_00065364(local_30,DAT_002fe804);
        if (iVar6 < 0) {
          *(undefined1 *)(iVar12 + 0x25) = 0;
        }
        else {
          uVar1 = FUN_00065104(local_30,iVar11,iVar6);
          *(undefined1 *)(iVar12 + 0x25) = uVar1;
        }
        *(short *)(iVar12 + 0x26) = (short)iVar5;
        if (iVar3 < iVar5) {
          iVar3 = iVar5;
        }
        iVar13 = iVar13 + 1;
        iVar11 = iVar11 + 1;
      } while (iVar13 < iVar4 + -1);
    }
    uVar9 = *(uint *)(param_1 + 8);
    uVar8 = iVar3 + 1;
    if (uVar9 < uVar8) {
      FUN_0027eedc(param_1 + 4,uVar8 - uVar9,&local_58,0);
    }
    else if (uVar8 < uVar9) {
      FUN_0027ee6c(param_1 + 4,uVar9 - uVar8,0);
    }
    local_2058[0] = 0;
    local_2058[1] = 0;
    piVar10 = local_2058;
    iVar3 = 0;
    uVar8 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar4 = *(int *)(param_1 + 4) + uVar8 * 0x28;
        if (*(short *)(iVar4 + 4) < 0) {
          *piVar10 = 0x7fff;
          piVar10[1] = uVar8;
        }
        else {
          iVar3 = iVar3 + 1;
          *piVar10 = (int)*(short *)(iVar4 + 8);
          piVar10[1] = uVar8;
        }
        uVar8 = uVar8 + 1;
        piVar10 = piVar10 + 2;
      } while (uVar8 < *(uint *)(param_1 + 8));
    }
    FUN_0001cfa4(local_2058,0,*(int *)(param_1 + 8) + -1);
    FUN_001a5bcc(param_1 + 0x10,iVar3,&DAT_002fe798,0);
    uVar8 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      piVar10 = local_2058;
      do {
        iVar3 = uVar8 * 4;
        uVar8 = uVar8 + 1;
        *(int *)(*(int *)(param_1 + 0x10) + iVar3) =
             (int)*(short *)(*(int *)(param_1 + 4) + piVar10[1] * 0x28 + 0x26);
        piVar10 = piVar10 + 2;
      } while (uVar8 < *(uint *)(param_1 + 0x14));
    }
    FUN_0027ed88(DAT_002fe80c);
    uVar8 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      iVar3 = 0;
      while( true ) {
        iVar3 = *(int *)(param_1 + 4) + (iVar3 + uVar8) * 8;
        FUN_0027ed88(DAT_002fe824,uVar8,(int)*(short *)(iVar3 + 4),
                     (int)*(short *)(iVar3 + 8));
        uVar8 = uVar8 + 1;
        if (*(uint *)(param_1 + 8) <= uVar8) break;
        iVar3 = uVar8 * 4;
      }
    }
    uVar8 = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      iVar3 = *(int *)(param_1 + 0x10);
      while( true ) {
        FUN_0027ed88(DAT_002fe83c,uVar8,*(undefined4 *)(iVar3 + uVar8 * 4));
        uVar8 = uVar8 + 1;
        if (*(uint *)(param_1 + 0x14) <= uVar8) break;
        iVar3 = *(int *)(param_1 + 0x10);
      }
    }
    local_58 = &DAT_00309c88;
  }
  local_30[0] = &DAT_003070bc;
  FUN_00066338(auStack_10,0);
  FUN_00066338(auStack_20,0);
  FUN_00064a08(local_30,0);
  return;
}
// near miss from lane fm11 (unreviewed)
