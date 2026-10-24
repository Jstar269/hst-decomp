/* HSTMATCH module=EBOOT.BIN start=0x0021a370 end=0x0021a6bc symbol=FUN_0021a370 lang=c99 rodata=0x002efb40 */
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned char undefined1;
typedef unsigned long long ulonglong;
typedef int code();

extern undefined4 DAT_002efdb4;
extern undefined4 DAT_002efb40[];
extern undefined4 DAT_003415a8;
extern undefined4 DAT_002efdc0;
extern undefined4 DAT_002efdcc;
extern undefined4 DAT_002efdd8;
extern undefined4 DAT_002efde4;
extern undefined4 DAT_002efdf0;
extern undefined4 DAT_002efdfc;
extern undefined4 DAT_002efe08;
extern undefined4 DAT_002efe14;
extern undefined4 DAT_002efe20;
extern undefined4 DAT_002efe2c;
extern undefined4 DAT_002efe38;
extern undefined4 DAT_002efe44;
extern undefined4 DAT_002efe50;
extern void FUN_0010b8cc();
extern undefined4 FUN_001fea10();
extern void FUN_00110a78();
extern void FUN_00103540();
extern void FUN_000ffb3c();
extern undefined8 FUN_00022178();
extern undefined8 FUN_0000c07c();
extern undefined8 FUN_00021ac0();
extern int FUN_00022254();

void FUN_0021a370(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;

  (**(code **)(**(int **)(param_1 + 0xe4) + 0x30))();
  FUN_0010b8cc(*(undefined4 *)(param_1 + 0xe4), *(undefined4 *)(param_1 + 0xe8), 2);
  iVar2 = *(int *)(param_1 + 0x64);
  iVar3 = *(int *)(param_1 + 0xec) + DAT_002efdb4;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x68);
  iVar3 = *(int *)(param_1 + 0xf0) + DAT_002efdc0;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x6c);
  iVar3 = *(int *)(param_1 + 0xf4) + DAT_002efdcc;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x70);
  iVar3 = *(int *)(param_1 + 0xf8) + DAT_002efdd8;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x74);
  iVar3 = *(int *)(param_1 + 0xfc) + DAT_002efde4;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x78);
  iVar3 = *(int *)(param_1 + 0x100) + DAT_002efdf0;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x7c);
  iVar3 = *(int *)(param_1 + 0x104) + DAT_002efdfc;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x80);
  iVar3 = *(int *)(param_1 + 0xec) + DAT_002efe08;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x84);
  iVar3 = *(int *)(param_1 + 0xf0) + DAT_002efe14;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x88);
  iVar3 = *(int *)(param_1 + 0xf4) + DAT_002efe20;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x8c);
  iVar3 = *(int *)(param_1 + 0xf8) + DAT_002efe2c;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x90);
  iVar3 = *(int *)(param_1 + 0xfc) + DAT_002efe38;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x94);
  iVar3 = *(int *)(param_1 + 0x100) + DAT_002efe44;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  iVar2 = *(int *)(param_1 + 0x98);
  iVar3 = *(int *)(param_1 + 0x104) + DAT_002efe50;
  *(int *)(iVar2 + 0x24) = iVar3;
  *(int *)(iVar2 + 0x28) = iVar3;
  if (*(int *)(param_1 + 0xe0) == 0) {
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  else {
    uVar5 = FUN_001fea10(0x12, 0x21,
                         *(undefined4 *)(&DAT_002efb40[*(int *)(*(int *)(param_1 + 0xe8) * 4 + param_1 + 0xec) * 4]));
    FUN_00110a78(*(undefined4 *)(param_1 + 0xe0), uVar5, 1);
    FUN_00103540(0x47c35000, *(undefined4 *)(param_1 + 0xe0));
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined1 *)(param_1 + 0x54) = 0;
  iVar2 = 0;
  uVar5 = *(undefined4 *)(DAT_003415a8 + 0x80);
  do {
    uVar6 = FUN_00022178(iVar2);
    uVar6 = FUN_0000c07c(0, 0x40240000, (int)uVar6, (int)((ulonglong)uVar6 >> 0x20));
    uVar7 = FUN_00022178(uVar5);
    uVar6 = FUN_00021ac0((int)uVar7, (int)((ulonglong)uVar7 >> 0x20), (int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20));
    iVar3 = FUN_00022254((int)uVar6, (int)((ulonglong)uVar6 >> 0x20));
    iVar4 = 0x1d - iVar2;
    if ((iVar2 == 0) || (0 < iVar3)) {
      iVar1 = param_1 + iVar4 * 4;
      FUN_000ffb3c(*(undefined4 *)(iVar1 + 100), 0);
      iVar1 = *(int *)(iVar1 + 100);
      iVar3 = iVar3 % 10 + (&DAT_002efdb4)[iVar4 * 3];
      *(int *)(iVar1 + 0x24) = iVar3;
      *(int *)(iVar1 + 0x28) = iVar3;
    }
    else {
      FUN_000ffb3c(*(undefined4 *)(param_1 + iVar4 * 4 + 100), 1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}
// near miss from lane fm10 (unreviewed)
