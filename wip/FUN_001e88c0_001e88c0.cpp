/* HSTMATCH module=EBOOT.BIN start=0x001e88c0 end=0x001e8bc4 symbol=FUN_001e88c0 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined * DAT_00338b44;
extern void FUN_000de100(void *, int, unsigned char *, int *);
extern undefined4 FUN_000de2c8(void *, int);
extern undefined4 FUN_000de3f0(void *, int);
extern int FUN_000de51c(void *, int);
extern int FUN_000dea20(void *, int);
extern bool FUN_000def0c(void *);
extern bool FUN_000def58(void *);
}

extern "C" void FUN_001e88c0(int param_1,int param_2)
{
  int initialState;
  int cVar1;
  int *piVar2;
  uint uVar3;
  int iVar12;
  int iVar11;
  int iVar10;
  int iVar9;
  int iVar8;
  int iVar7;
  int iVar6;
  int iVar5;
  int iVar4;
  unsigned char local_1;
  unsigned char invertedState;
  int local_8;
  int local_c;
  int local_10;
  
  initialState = FUN_000def58(DAT_00338b44);
  if (param_2 != 0) {
    local_10 = *(int *)(DAT_00338b44 + 0xb4);
    invertedState = (initialState != '\0') ^ 1;
    local_c = *(int *)(DAT_00338b44 + 0xbc) + *(int *)(DAT_00338b44 + 0xb8) + invertedState;
    piVar2 = local_10 < local_c ? &local_10 : &local_c;
    *(int *)(param_1 + 0x398) = *piVar2;
  }
  FUN_000de100(DAT_00338b44,param_1 + 0x3d4,&local_1,&local_8);
  iVar12 = 0;
  iVar11 = 0;
  iVar10 = param_1;
  iVar9 = 0;
  iVar8 = param_1;
  do {
    *(undefined4 *)(iVar10 + 0x39c) = *(undefined4 *)(DAT_00338b44 + iVar11 + 0xb8);
    iVar7 = 0;
    if (0 < *(int *)(param_1 + 0x398)) {
      iVar6 = 0;
      iVar5 = iVar8;
      do {
        iVar7 = iVar7 + 1;
        iVar4 = (int)(DAT_00338b44 + iVar9 + iVar6);
        iVar6 = iVar6 + 4;
        *(undefined4 *)(iVar5 + 0x3a4) = *(undefined4 *)(iVar4 + 0xd8);
        iVar5 = iVar5 + 4;
      } while (iVar7 < *(int *)(param_1 + 0x398));
    }
    if (local_1 != '\0') {
      *(undefined4 *)(iVar10 + 0x3d4) = 4;
    }
    else {
      int localResult = local_8;
      if (localResult != 0) {
        if (localResult == 1) {
          *(undefined4 *)(param_1 + 0x3d4) = 3;
          *(undefined4 *)(param_1 + 0x3d8) = 5;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x3d4) = 5;
        *(undefined4 *)(param_1 + 0x3d8) = 3;
      }
    }
    if (FUN_000dea20(DAT_00338b44,iVar12) != 0) {
      *(undefined4 *)(iVar10 + 0x3dc) = 3;
    }
    else if (FUN_000dea20(DAT_00338b44,1 - iVar12) != 0) {
      *(undefined4 *)(iVar10 + 0x3dc) = 4;
    }
    else if (FUN_000de51c(DAT_00338b44,iVar12) != 0) {
      *(undefined4 *)(iVar10 + 0x3dc) = 2;
    }
    else if (FUN_000de2c8(DAT_00338b44,iVar12) != 0) {
      *(undefined4 *)(iVar10 + 0x3dc) = 0;
    }
    else if (FUN_000de3f0(DAT_00338b44,iVar12) != 0) {
      *(undefined4 *)(iVar10 + 0x3dc) = 1;
    }
    else {
      *(undefined4 *)(iVar10 + 0x3dc) = 0xffffffff;
    }
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 4;
    iVar10 = iVar10 + 4;
    iVar9 = iVar9 + 0x18;
    iVar8 = iVar8 + 0x18;
  } while (iVar12 < 2);
  cVar1 = FUN_000def0c(DAT_00338b44);
  if (param_2 != 0) {
    uVar3 = FUN_000def0c(DAT_00338b44);
    *(uint *)(param_1 + 0x3e4) = uVar3 & 0xff;
  }
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x3e4) != 0) {
      iVar10 = 0;
      iVar8 = param_1;
      do {
        if (*(int *)(DAT_00338b44 + 0xa4) == iVar10) {
          iVar9 = iVar8 + *(int *)(param_1 + 0x398) * 4;
          *(int *)(iVar9 + 0x3e4) = *(int *)(iVar9 + 0x3e4) + 1;
        }
        iVar10 = iVar10 + 1;
        iVar8 = iVar8 + 0x18;
      } while (iVar10 < 2);
      return;
    }
    iVar8 = *(int *)(param_1 + 0x3e4);
  }
  else {
    iVar8 = *(int *)(param_1 + 0x3e4);
  }
  if (iVar8 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x398) * 4 + param_1 + 0x3e4) =
         *(undefined4 *)(param_1 + 0x3d4);
    *(undefined4 *)(*(int *)(param_1 + 0x398) * 4 + param_1 + 0x3fc) =
         *(undefined4 *)(param_1 + 0x3d8);
  }
  return;
}
// Near miss: 126 differing words remain; entry, typed flag inversion, pointer selection, and main copy loop are close to retail.
// Remaining differences include local-state branch layout, helper-call status selection, saved-loop timing, and final counter paths.
// Tried return-width changes, local register order, flattened helper decisions, switch dispatch, pointer selection, and address-expression order.
// near miss from lane km5 (unreviewed)
