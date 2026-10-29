/* HSTMATCH module=EBOOT.BIN start=0x001c9e1c end=0x001ca1bc symbol=FUN_001c9e1c lang=c99 */
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

extern undefined4 DAT_002bc430;
extern undefined4 DAT_002bc434;
extern undefined4 DAT_002bc438;
extern undefined4 DAT_002bc43c;
extern undefined4 DAT_002ea2cc;
extern undefined4 DAT_002ea2d0;
extern undefined * DAT_003415a8;
extern undefined4 DAT_00341d7d;
extern undefined4 DAT_00341d7e;
extern undefined4 * FUN_00093818();
extern int FUN_0022a930();
extern int FUN_00288dec();

void FUN_001c9e1c(int param_1)
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  
  piVar8 = *(int **)(param_1 + 0x40);
  uVar11 = 0;
  if (piVar8 != piVar8 + *(int *)(param_1 + 0x44)) {
    iVar9 = 0;
    do {
      piVar10 = (int *)*piVar8;
      iVar2 = FUN_0022a930();
      iVar2 = iVar9 + iVar2;
      iVar3 = (**(code **)(*piVar10 + 0x34))(piVar10);
      { int *pt = (int *)((char *)iVar2 + 0xa210); *pt = iVar3; }
      *(int *)(iVar2 + 0xa214) = piVar10[0xc];
      *(short *)(iVar2 + 0xa218) = (short)piVar10[0xd];
      *(short *)(iVar2 + 0xa21a) = (short)piVar10[0xe];
      iVar3 = FUN_00288dec((int)piVar10);
      *(short *)(iVar2 + 0xa21c) = (short)iVar3;
      *(undefined1 *)(iVar2 + 0xa21e) = *(undefined1 *)((int)piVar10 + 0x57);
      puVar4 = (undefined4 *)(**(code **)(*piVar10 + 0x20))(piVar10);
      *(undefined4 *)(iVar2 + 0xa220) = *puVar4;
      *(undefined4 *)(iVar2 + 0xa224) = puVar4[1];
      *(undefined4 *)(iVar2 + 0xa228) = puVar4[2];
      *(undefined4 *)(iVar2 + 0xa22c) = puVar4[3];
      *(undefined4 *)(iVar2 + 0xa230) = DAT_002bc430;
      *(undefined4 *)(iVar2 + 0xa234) = DAT_002bc434;
      *(undefined4 *)(iVar2 + 0xa238) = DAT_002bc438;
      *(undefined4 *)(iVar2 + 0xa23c) = DAT_002bc43c;
      piVar5 = (int *)0x0;
      if (*(int *)((char *)iVar2 + 0xa210) - 2U < 2) {
        if (piVar10 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = piVar10 + -0x38;
        }
      }
      if (piVar5 != (int *)0x0) {
        puVar4 = FUN_00093818((int)piVar5);
        *(undefined4 *)(iVar2 + 0xa230) = puVar4[8];
        *(undefined4 *)(iVar2 + 0xa234) = puVar4[9];
        *(undefined4 *)(iVar2 + 0xa238) = puVar4[10];
        *(undefined4 *)(iVar2 + 0xa23c) = puVar4[0xb];
      }
      uVar11 = uVar11 + 1;
      iVar9 = iVar9 + 0x30;
    } while ((uVar11 < 0x30) &&
            (piVar8 = piVar8 + 1,
            piVar8 != (int *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x44) * 4)));
  }
  iVar9 = FUN_0022a930();
  *(uint *)(iVar9 + 0xab28) = uVar11;
  iVar9 = FUN_0022a930();
  *(undefined4 *)(iVar9 + 0xab20) = *(undefined4 *)(param_1 + 0xcc);
  iVar9 = FUN_0022a930();
  *(undefined4 *)(iVar9 + 0xab24) = *(undefined4 *)(param_1 + 0xd0);
  if ((*(int *)(param_1 + 0x94) == 0) || (*(char *)(param_1 + 0xfa) != '\0')) {
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab2c) = 0xffffffff;
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab30) = 0xffffffff;
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab34) = 0xffffffff;
  }
  else {
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x94) + 0x30);
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab2c) = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x94) + 0x34);
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab30) = uVar7;
    uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x94) + 0x38);
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab34) = uVar7;
  }
  iVar9 = FUN_0022a930();
  *(undefined1 *)(iVar9 + 0xab4c) = 1;
  iVar9 = FUN_0022a930();
  *(undefined1 *)(iVar9 + 0xab4d) = 0;
  iVar9 = FUN_0022a930();
  *(undefined4 *)(iVar9 + 0xab44) = 0;
  iVar9 = FUN_0022a930();
  *(undefined4 *)(iVar9 + 0xab48) = 0;
  if (*(int *)(param_1 + 0x98) == 0) {
    iVar9 = FUN_0022a930();
    *(undefined4 *)(iVar9 + 0xab40) = 0xffffffff;
    DAT_00341d7d = 0xff;
    DAT_00341d7e = 0xff;
    *(undefined1 *)(param_1 + 0xfa) = 0;
  }
  else {
    uVar1 = *(ushort *)(DAT_003415a8 + 0x10b4);
    iVar9 = FUN_0022a930();
    *(uint *)(iVar9 + 0xab40) = (uint)uVar1;
    uVar11 = *(uint *)(param_1 + 0xc0);
    DAT_00341d7d = (undefined1)uVar11;
    DAT_00341d7e = DAT_00341d7d;
    if ((int)(uVar11 & 0xffff) < DAT_002ea2cc) {
      *(short *)(DAT_003415a8 + 0x10b4) = (short)DAT_002ea2cc;
    }
    else {
      uVar6 = (undefined2)DAT_002ea2d0;
      if ((int)(uVar11 & 0xffff) <= DAT_002ea2d0) {
        uVar6 = (undefined2)uVar11;
      }
      *(undefined2 *)(DAT_003415a8 + 0x10b4) = uVar6;
    }
    *(undefined1 *)(param_1 + 0xfa) = 0;
  }
  return;
}
// near miss from lane dsn3 (unreviewed)
