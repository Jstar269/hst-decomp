/* HSTMATCH module=EBOOT.BIN start=0x00283874 end=0x00283c14 symbol=FUN_00283874 lang=c99 */
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

extern undefined * DAT_00338ac4;
extern undefined1 DAT_003417c8;
extern void FUN_000bb190();
extern int FUN_000bbba4();
extern undefined4 FUN_000bd568();
extern undefined4 FUN_000bd6a4();
extern void FUN_00282664();
extern int FUN_002831c0();
extern void FUN_00283358();

void FUN_00283874(int param_1)
{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar10;
  int iVar9;
  int iVar8;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = param_1;
  do {
    if (((*(unsigned char *)(DAT_00338ac4 + iVar9 + 0x5e) != 0) && (*(unsigned char *)(iVar8 + 0xa6d) != 0)) &&
       (iVar10 == *(int *)(DAT_00338ac4 + 0x198))) {
      FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e);
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 7;
    iVar8 = iVar8 + 0x458;
  } while (iVar10 < 4);
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = param_1;
  do {
    if ((*(unsigned char *)(DAT_00338ac4 + iVar9 + 0x5e) != 0) && (*(unsigned char *)(iVar8 + 0xa6d) != 0)) {
      if (iVar10 == *(int *)(DAT_00338ac4 + 0x198)) {
        iVar3 = FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e);
        if (iVar10 == iVar3) {
          float copy0 = *(float *)(param_1 + 100);
          float copy1 = *(float *)(param_1 + 0x58);
          float copy2 = *(float *)(param_1 + 0x5c);
          float copy3 = *(float *)(param_1 + 0x60);
          *(float *)(param_1 + 0x500) = copy1;
          *(float *)(param_1 + 0x504) = copy2;
          *(float *)(param_1 + 0x508) = copy3;
          *(float *)(param_1 + 0x50c) = copy0;
          float copy4 = *(float *)(param_1 + 0x68);
          float copy5 = *(float *)(param_1 + 0x70);
          float copy6 = *(float *)(param_1 + 0x6c);
          *(float *)(param_1 + 0x510) = copy4;
          *(float *)(param_1 + 0x514) = copy6;
          *(float *)(param_1 + 0x518) = copy5;
          float copy7 = *(float *)(param_1 + 0x74);
          float copy8 = *(float *)(param_1 + 0x78);
          *(float *)(param_1 + 0x51c) = copy7;
          *(float *)(param_1 + 0x520) = copy8;
          *(undefined1 *)(param_1 + 0x524) = *(undefined1 *)(param_1 + 0x7c);
          *(undefined1 *)(param_1 + 0x525) = *(undefined1 *)(param_1 + 0x7d);
        }
        else {
          iVar3 = FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e);
          iVar3 = param_1 + iVar3 * 0x458;
          uVar13 = *(undefined4 *)(iVar3 + 0x95c);
          uVar11 = *(undefined4 *)(iVar3 + 0x960);
          uVar12 = *(undefined4 *)(iVar3 + 0x964);
          *(undefined4 *)(param_1 + 0x500) = *(undefined4 *)(iVar3 + 0x958);
          *(undefined4 *)(param_1 + 0x504) = uVar13;
          *(undefined4 *)(param_1 + 0x508) = uVar11;
          *(undefined4 *)(param_1 + 0x50c) = uVar12;
          uVar11 = *(undefined4 *)(iVar3 + 0x96c);
          uVar12 = *(undefined4 *)(iVar3 + 0x970);
          *(undefined4 *)(param_1 + 0x510) = *(undefined4 *)(iVar3 + 0x968);
          *(undefined4 *)(param_1 + 0x514) = uVar11;
          *(undefined4 *)(param_1 + 0x518) = uVar12;
          uVar11 = *(undefined4 *)(iVar3 + 0x978);
          *(undefined4 *)(param_1 + 0x51c) = *(undefined4 *)(iVar3 + 0x974);
          *(undefined4 *)(param_1 + 0x520) = uVar11;
          uVar1 = *(undefined1 *)(iVar3 + 0x97d);
          *(undefined1 *)(param_1 + 0x524) = *(undefined1 *)(iVar3 + 0x97c);
          *(undefined1 *)(param_1 + 0x525) = uVar1;
        }
        uVar13 = *(undefined4 *)(param_1 + 0x4ec);
        uVar11 = *(undefined4 *)(param_1 + 0x4f0);
        uVar12 = *(undefined4 *)(param_1 + 0x4f4);
        *(undefined4 *)(iVar8 + 0x940) = *(undefined4 *)(param_1 + 0x4e8);
        *(undefined4 *)(iVar8 + 0x944) = uVar13;
        *(undefined4 *)(iVar8 + 0x948) = uVar11;
        *(undefined4 *)(iVar8 + 0x94c) = uVar12;
        *(undefined4 *)(iVar8 + 0x950) = *(undefined4 *)(param_1 + 0x4f8);
        *(undefined1 *)(iVar8 + 0x954) = *(undefined1 *)(param_1 + 0x4fc);
        uVar13 = *(undefined4 *)(param_1 + 0x504);
        uVar11 = *(undefined4 *)(param_1 + 0x508);
        uVar12 = *(undefined4 *)(param_1 + 0x50c);
        *(undefined4 *)(iVar8 + 0x958) = *(undefined4 *)(param_1 + 0x500);
        *(undefined4 *)(iVar8 + 0x95c) = uVar13;
        *(undefined4 *)(iVar8 + 0x960) = uVar11;
        *(undefined4 *)(iVar8 + 0x964) = uVar12;
        uVar13 = *(undefined4 *)(param_1 + 0x514);
        uVar11 = *(undefined4 *)(param_1 + 0x518);
        uVar12 = *(undefined4 *)(param_1 + 0x51c);
        *(undefined4 *)(iVar8 + 0x968) = *(undefined4 *)(param_1 + 0x510);
        *(undefined4 *)(iVar8 + 0x96c) = uVar13;
        *(undefined4 *)(iVar8 + 0x970) = uVar11;
        *(undefined4 *)(iVar8 + 0x974) = uVar12;
        uVar11 = *(undefined4 *)(param_1 + 0x524);
        *(undefined4 *)(iVar8 + 0x978) = *(undefined4 *)(param_1 + 0x520);
        *(undefined4 *)(iVar8 + 0x97c) = uVar11;
        FUN_002831c0(iVar8 + 0x980,param_1 + 0x528);
        FUN_002831c0(iVar8 + 0xaa0,param_1 + 0x648);
        FUN_002831c0(iVar8 + 0xbc0,param_1 + 0x768);
        puVar7 = (undefined1 *)(param_1 + 0x888);
        puVar5 = (undefined1 *)(iVar8 + 0xce0);
        iVar3 = 3;
        do {
          uVar1 = puVar7[1];
          iVar3 = iVar3 + -1;
          *puVar5 = *puVar7;
          puVar5[1] = uVar1;
          puVar7 = puVar7 + 2;
          puVar5 = puVar5 + 2;
        } while (0 < iVar3);
        puVar6 = (undefined4 *)(param_1 + 0x890);
        puVar4 = (undefined4 *)(iVar8 + 0xce8);
        iVar3 = 0x2b;
        do {
          iVar3 = iVar3 + -1;
          *puVar4 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar4 = puVar4 + 1;
        } while (0 < iVar3);
        *(int *)(iVar8 + 0xa78) = iVar10;
        uVar2 = *(uint *)(param_1 + 0x2c14) & 3;
        if (((int)*(uint *)(param_1 + 0x2c14) < 0) && (uVar2 != 0)) {
          uVar2 = uVar2 - 4;
        }
        if (uVar2 == 0) {
          FUN_000bd568(DAT_00338ac4);
        }
      }
      else {
        FUN_000bd6a4(DAT_00338ac4,iVar10);
        iVar3 = FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e);
        if (iVar10 == iVar3) {
          uVar13 = *(undefined4 *)(iVar8 + 0x95c);
          uVar11 = *(undefined4 *)(iVar8 + 0x960);
          uVar12 = *(undefined4 *)(iVar8 + 0x964);
          *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar8 + 0x958);
          *(undefined4 *)(param_1 + 0x5c) = uVar13;
          *(undefined4 *)(param_1 + 0x60) = uVar11;
          *(undefined4 *)(param_1 + 100) = uVar12;
          uVar11 = *(undefined4 *)(iVar8 + 0x96c);
          uVar12 = *(undefined4 *)(iVar8 + 0x970);
          *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar8 + 0x968);
          *(undefined4 *)(param_1 + 0x6c) = uVar11;
          *(undefined4 *)(param_1 + 0x70) = uVar12;
          uVar11 = *(undefined4 *)(iVar8 + 0x978);
          *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar8 + 0x974);
          *(undefined4 *)(param_1 + 0x78) = uVar11;
          uVar1 = *(undefined1 *)(iVar8 + 0x97d);
          *(undefined1 *)(param_1 + 0x7c) = *(undefined1 *)(iVar8 + 0x97c);
          *(undefined1 *)(param_1 + 0x7d) = uVar1;
        }
      }
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 7;
    iVar8 = iVar8 + 0x458;
  } while (iVar10 < 4);
  if (*(unsigned char *)(param_1 + 1) == 0) {
    FUN_00283358(param_1);
  }
  else {
    DAT_003417c8 = *(undefined1 *)(param_1 + 0x4dc);
  }
  FUN_00282664(param_1);
  FUN_000bb190(DAT_00338ac4);
  return;
}

// Best result: 108 differing words out of 232; first mismatch at +0xc0.
// Remaining differences are float register ordering in the large state copies and fields copied with integer instructions.
// Ruled out broad float typing, pointer-view changes, loop-variable type changes, C/C++ modes, and strength-reduction toggles; grouped self-copy floats and loop register ordering are best so far.
// near miss from lane km4 (unreviewed)
