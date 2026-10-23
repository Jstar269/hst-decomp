/* HSTMATCH module=EBOOT.BIN start=0x001eb960 end=0x001ebc5c symbol=FUN_001eb960 lang=c99 */
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

extern undefined * DAT_00338b44;
extern void FUN_000de100();
extern undefined4 FUN_000de2c8();
extern undefined4 FUN_000de3f0();
extern bool FUN_000de51c();
extern bool FUN_000dea20();
extern undefined4 FUN_000def0c();
extern bool FUN_000def58();
extern void FUN_000ffb3c();

void FUN_001eb960(int param_1)
{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar14;
  int iVar13;
  int iVar12;
  int iVar11;
  int iVar10;
  char local_1;
  int local_8;
  int local_c;
  int local_10;
  
  cVar1 = FUN_000def58(DAT_00338b44);
  local_10 = *(int *)(DAT_00338b44 + 0xb4);
  local_c = *(int *)(DAT_00338b44 + 0xb8) + *(int *)(DAT_00338b44 + 0xbc) + 1;
  if (*(int *)(DAT_00338b44 + 0xb4) < local_c) {
    piVar3 = &local_10;
  }
  else {
    piVar3 = &local_c;
  }
  *(int *)(param_1 + 0xe0) = *piVar3;
  FUN_000de100(DAT_00338b44,param_1 + 0x11c,&local_1,&local_8);
  iVar14 = 0;
  iVar13 = 0;
  iVar11 = 0;
  iVar10 = param_1;
  iVar12 = param_1;
  do {
    *(undefined4 *)(iVar12 + 0xe4) = *(undefined4 *)(DAT_00338b44 + iVar13 + 0xb8);
    iVar9 = 0;
    if (0 < *(int *)(param_1 + 0xe0)) {
      iVar8 = 0;
      iVar5 = iVar10;
      do {
        iVar9 = iVar9 + 1;
        iVar4 = (int)(iVar11 + DAT_00338b44 + iVar8);
        iVar8 = iVar8 + 4;
        *(undefined4 *)(iVar5 + 0xec) = *(undefined4 *)(iVar4 + 0xd8);
        iVar5 = iVar5 + 4;
      } while (iVar9 < *(int *)(param_1 + 0xe0));
    }
    if (local_1 == '\0') {
      if (local_8 == 0) {
        *(undefined4 *)(param_1 + 0x11c) = 5;
        *(undefined4 *)(param_1 + 0x120) = 3;
      }
      else if (local_8 == 1) {
        *(undefined4 *)(param_1 + 0x11c) = 3;
        *(undefined4 *)(param_1 + 0x120) = 5;
      }
    }
    else {
      *(undefined4 *)(iVar12 + 0x11c) = 4;
    }
    iVar9 = FUN_000dea20(DAT_00338b44,iVar14);
    if (iVar9 == 0) {
      iVar9 = FUN_000dea20(DAT_00338b44,1 - iVar14);
      if (iVar9 == 0) {
        iVar9 = FUN_000de51c(DAT_00338b44,iVar14);
        if (iVar9 == 0) {
          iVar9 = FUN_000de2c8(DAT_00338b44,iVar14);
          if (iVar9 == 0) {
            iVar9 = FUN_000de3f0(DAT_00338b44,iVar14);
            if (iVar9 == 0) {
              *(undefined4 *)(iVar12 + 0x124) = 0xffffffff;
            }
            else {
              *(undefined4 *)(iVar12 + 0x124) = 1;
            }
          }
          else {
            *(undefined4 *)(iVar12 + 0x124) = 0;
          }
        }
        else {
          *(undefined4 *)(iVar12 + 0x124) = 2;
        }
      }
      else {
        *(undefined4 *)(iVar12 + 0x124) = 4;
      }
    }
    else {
      *(undefined4 *)(iVar12 + 0x124) = 3;
    }
    iVar14 = iVar14 + 1;
    iVar13 = iVar13 + 4;
    iVar12 = iVar12 + 4;
    iVar11 = iVar11 + 0x18;
    iVar10 = iVar10 + 0x18;
  } while (iVar14 < 2);
  uVar2 = FUN_000def0c(DAT_00338b44);
  *(undefined1 *)(param_1 + 300) = uVar2;
  iVar10 = FUN_000de2c8(DAT_00338b44,0xffffffff);
  if (iVar10 == 0) {
    iVar10 = FUN_000de3f0(DAT_00338b44,0xffffffff);
  }
  *(bool *)(param_1 + 0x12d) = iVar10 != 0;
  uVar2 = FUN_000de51c(DAT_00338b44,0xffffffff);
  *(undefined1 *)(param_1 + 0x12e) = uVar2;
  uVar2 = FUN_000dea20(DAT_00338b44,0xffffffff);
  *(undefined1 *)(param_1 + 0x12f) = uVar2;
  iVar12 = 0;
  iVar10 = param_1;
  do {
    bVar7 = cVar1 != '\0';
    if (!(bVar7)) {
      bVar7 = *(char *)(param_1 + 300) != '\0';
    }
    uVar6 = *(undefined4 *)(iVar10 + 0xa4);
    FUN_000ffb3c(uVar6,bVar7);
    bVar7 = cVar1 != '\0';
    if (!(bVar7)) {
      bVar7 = *(char *)(param_1 + 300) == '\0';
    }
    uVar6 = *(undefined4 *)(iVar10 + 0x9c);
    FUN_000ffb3c(uVar6,bVar7);
    iVar12 = iVar12 + 1;
    iVar10 = iVar10 + 4;
  } while (iVar12 < 2);
  return;
}
// Best near miss: 146 differing words remain after reordering the loop locals. The state and
// record-copy branches still differ substantially. Tried return-type, signed-byte, pointer-parameter,
// float-copy, register, and loop-form variants; the local declaration order gave the best result.
// near miss from lane km4 (unreviewed)
