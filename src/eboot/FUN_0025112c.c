/* HSTMATCH module=EBOOT.BIN start=0x0025112c end=0x00251414 symbol=FUN_0025112c lang=c99 rodata=0x002ca654 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: `flag = !(cVar1 != 0)` for the sltu+xori+andi byte test, and the if/else arm order in the 2-or-3 state picks. */
typedef unsigned int undefined4;
typedef unsigned char undefined1;

extern int DAT_002fbef4;
extern undefined1 DAT_0034179c;
extern unsigned char DAT_002fbef9;
extern int DAT_002fc560;
extern undefined4 *DAT_003415a8;
extern void FUN_0010b980();
extern void FUN_00110a78();
extern void FUN_001b1c44(undefined1 *, int);
extern undefined4 FUN_001fea10();
extern void FUN_00250f68();
extern void FUN_00251414();
extern void FUN_0025141c();

struct Player {
  char pad0[0xc4];
  int *f0c4;
  char pad1[0x1d4 - 0xc8];
  int f1d4;
  int f1d8;
  char pad2[0x2f8 - 0x1dc];
  int f2f8;
  char pad3[0x304 - 0x2fc];
  int f304;
  char pad4[0x30c - 0x308];
  int f30c;
  unsigned char f310;
  char pad5[0x314 - 0x311];
  int f314;
  unsigned char f318;
  char pad6[0x34c - 0x319];
  int f34c;
  char pad7[0x35c - 0x350];
  int f35c;
};

void FUN_0025112c(struct Player *param_1, int param_2, int param_3, int param_4)
{
  unsigned char cVar1;
  unsigned char flag;
  int iVar2;
  int *iVar4;
  undefined4 uVar3;

  param_1->f2f8 = param_2;
  switch (param_2) {
  case 0:
  case 5:
  case 6:
    break;
  case 1:
    if (param_1->f1d8 != 0) {
      uVar3 = FUN_001fea10(0x12, 5, 1);
      FUN_00110a78(param_1->f1d8, uVar3, 0);
    }
    if (param_3 == 0) {
      if (DAT_002fbef9 != 0) {
        FUN_00251414(param_1, 0);
      }
    }
    cVar1 = param_1->f318;
    flag = !(cVar1 != 0);
    FUN_0010b980(param_1->f1d4, flag, 0);
    iVar4 = param_1->f0c4;
    iVar2 = DAT_002fc560 + 1;
    iVar4[9] = iVar2;
    iVar4[10] = iVar2;
    break;
  case 2:
    if (param_1->f1d8 != 0) {
      uVar3 = FUN_001fea10(0x12, 5, 2);
      FUN_00110a78(param_1->f1d8, uVar3, 0);
    }
    FUN_0025141c(param_1);
    FUN_00250f68(param_1, 0xffffffff, 0);
    if (param_1->f30c != 0 && DAT_003415a8[0x21b35] == 0) {
      param_1->f310 = 1;
      param_1->f314 = 0;
      iVar2 = 3;
      param_1->f304 = 3;
      DAT_002fbef4 = 3;
      if (param_1->f30c != 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 2;
      }
      FUN_0010b980(param_1->f1d4, (iVar2 + 2) - param_1->f304, 0);
      DAT_003415a8[0x21b35] = 1;
    }
    if (DAT_002fbef9 != 0) {
      FUN_00251414(param_1, param_1->f304 == 3);
    }
    iVar2 = param_1->f30c;
    if (iVar2 != 0) {
      iVar2 = 3;
    }
    else {
      iVar2 = 2;
    }
    FUN_0010b980(param_1->f1d4, (iVar2 + 2) - param_1->f304, 0);
    iVar4 = param_1->f0c4;
    iVar2 = DAT_002fc560 + 2;
    iVar4[9] = iVar2;
    iVar4[10] = iVar2;
    break;
  case 3:
    if (param_1->f1d8 != 0) {
      uVar3 = FUN_001fea10(0x12, 5, 0);
      FUN_00110a78(param_1->f1d8, uVar3, 0);
    }
    iVar2 = param_1->f35c;
    FUN_0010b980(param_1->f1d4, iVar2 + 6, 0);
    if (param_3 != 0) {
      param_1->f34c = 0x42ca0000;
    }
    if (param_1->f304 == 3) {
      FUN_0025141c(param_1);
    }
    break;
  case 4:
    if (param_1->f1d8 != 0) {
      uVar3 = FUN_001fea10(0x12, 5, 0);
      FUN_00110a78(param_1->f1d8, uVar3, 0);
    }
    break;
  }
  if (param_4 == 0) {
    if (param_3 != 0) {
      FUN_001b1c44(&DAT_0034179c, 3);
    }
    else {
      FUN_001b1c44(&DAT_0034179c, 4);
    }
  }
  return;
}
