/* HSTMATCH module=EBOOT.BIN start=0x001c772c end=0x001c7cb4 symbol=FUN_001c772c lang=c99 */
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

extern undefined * DAT_0033b574;
extern undefined * DAT_0034a118;
extern undefined4 DAT_0034a2e0;
extern char DAT_002ea38c[];
extern char DAT_002ea3b8[];
extern char DAT_002ea3e8[];
extern char DAT_002ea74c[];
extern char DAT_002ea8bc[];
extern char DAT_002ea8e0[];
extern char DAT_002ea904[];
extern char DAT_002ea928[];
extern char DAT_002ea938[];
extern char DAT_002ea960[];
extern char DAT_002ea988[];
extern char DAT_002ea9b4[];
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern int FUN_00010184();
extern void FUN_000104e0();
extern void FUN_000143b0();
extern void FUN_0001bfb4();
extern void FUN_0001ca58();
extern void FUN_0001cad0();
extern void FUN_0001cb88();
extern int FUN_0001cbfc();
extern undefined4 FUN_0001cc54();
extern int FUN_0006517c();
extern undefined4 FUN_0010ae20();
extern undefined4 * FUN_001268d8();
extern void FUN_001277e8();
extern void FUN_0012a254();
extern undefined4 * FUN_0012cc4c();
extern void FUN_0012d464();
extern void FUN_001b8f40();
extern void FUN_001b8f94();
extern void FUN_001c67e8();
extern int FUN_001c7cb4();
extern void FUN_001c7e8c();
extern void FUN_00225990();
extern undefined4 FUN_002292a8();
extern void FUN_002293d4();
extern undefined4 FUN_002296a0();
extern void FUN_00229774();
extern bool FUN_0022c988();
extern undefined4 FUN_0027d34c();
extern void FUN_00286938();
extern void FUN_00286f00();
extern void FUN_00289110();
extern void FUN_00289d60();
extern void FUN_0028b93c();

void FUN_001c772c(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  char local_80 [128];
  undefined1 auStack_100 [128];
  undefined1 auStack_200 [256];
  undefined1 auStack_300 [256];
  
  if (DAT_0033b574 != 0) {
    FUN_00289110(DAT_0033b574 + 0x1320);
  }
  FUN_001c7e8c(param_1,param_5);
  iVar11 = param_2 + 1;
  iVar10 = param_3 + 1;
  iVar2 = FUN_00000bcc(0x420);
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = (int)(FUN_001268d8(iVar2));
  }
  DAT_0034a118 = (unsigned char *)(iVar3);
  if (param_5 != 0) {
    FUN_0001cad0(0x30ebf4,1,DAT_002ea8bc,iVar11);
    iVar3 = *(int *)(param_1 + 0x15c);
    FUN_00229774(iVar3 + 0x34);
    FUN_002293d4(iVar3 + 0x34);
    pcVar9 = *(char **)(iVar3 + 0x24);
    if (pcVar9 != (char *)0x0) {
      if (pcVar9 == (char *)0x0) {
        *(undefined4 *)(iVar3 + 0x24) = 0;
      }
      else {
        if ((*pcVar9 != '\0') && (*(int *)(pcVar9 + 4) != 0)) {
          FUN_000104e0();
        }
        FUN_00000a00(pcVar9);
        *(undefined4 *)(iVar3 + 0x24) = 0;
      }
    }
    FUN_000143b0(auStack_300,DAT_002ea38c,iVar11);
    puVar4 = (undefined1 *)FUN_00000bcc(0x10);
    if (puVar4 == (undefined1 *)0x0) {
      *(undefined4 *)(iVar3 + 0x24) = 0;
    }
    else {
      *puVar4 = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      *(undefined1 **)(iVar3 + 0x24) = puVar4;
    }
    FUN_0010ae20(puVar4,auStack_300);
    FUN_000143b0(auStack_300,DAT_002ea3b8,iVar11);
    FUN_002292a8(iVar3 + 0x34,auStack_300);
    FUN_000143b0(auStack_300,DAT_002ea3e8,iVar11);
    FUN_002296a0(iVar3 + 0x34,auStack_300);
    FUN_0027d34c(*(undefined4 *)(param_1 + 0x170),iVar11);
    FUN_0001cb88(0x30ebf4);
    uVar5 = FUN_00010184(0x40,0x1ccccc);
    FUN_0001bfb4(0x30ab9c,uVar5,0x1ccccc);
    FUN_0001ca58(0x30ebf4,DAT_002ea8e0,iVar11);
    FUN_001b8f40(*(undefined4 *)(param_1 + 0x160),param_2,0);
    FUN_0001cb88(0x30ebf4);
    uVar6 = FUN_0001cbfc();
    uVar7 = FUN_0001cc54();
    FUN_0001bfb4(0x30ab9c,uVar6,uVar7);
    FUN_000104e0(uVar5);
    FUN_0001ca58(0x30ebf4,DAT_002ea904,iVar11);
    pcVar8 = DAT_002ea74c;
    pcVar9 = local_80;
    iVar3 = 0x40;
    do {
      cVar1 = pcVar8[1];
      iVar3 = iVar3 + -1;
      *pcVar9 = *pcVar8;
      pcVar9[1] = cVar1;
      pcVar8 = pcVar8 + 2;
      pcVar9 = pcVar9 + 2;
    } while (0 < iVar3);
    uVar5 = FUN_0006517c(*(undefined4 *)(param_1 + 0x178),param_2,0);
    FUN_000143b0(auStack_100,DAT_002ea928,uVar5);
    FUN_00289d60(param_1 + 0x180,local_80,auStack_100,iVar11);
    FUN_0001cb88(0x30ebf4);
  }
  uVar5 = FUN_00010184(0x40,0x100000);
  FUN_0001bfb4(0x30ab9c,uVar5,0x100000);
  FUN_0001ca58(0x30ebf4,DAT_002ea938,iVar11,iVar10);
  FUN_001c7cb4(param_1,iVar11,iVar10,1);
  FUN_0001cb88(0x30ebf4);
  uVar6 = FUN_0001cbfc();
  uVar7 = FUN_0001cc54();
  FUN_0001bfb4(0x30ab9c,uVar6,uVar7);
  FUN_000104e0(uVar5);
  uVar5 = FUN_00010184(0x40,0x100000);
  FUN_0001bfb4(0x30ab9c,uVar5,0x100000);
  FUN_0001ca58(0x30ebf4,DAT_002ea960,iVar11,iVar10);
  iVar3 = FUN_00000bcc(0x13d0);
  if (iVar3 != 0) {
    FUN_0012cc4c(iVar3);
  }
  if (DAT_0033b574 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)(DAT_0033b574 + 0x1320);
  }
  FUN_001c67e8(param_1,iVar3);
  FUN_00286f00(DAT_0033b574 + 0x1320,0,0,0,iVar11,iVar10,0,0);
  FUN_0001cb88(0x30ebf4);
  uVar6 = FUN_0001cbfc();
  uVar7 = FUN_0001cc54();
  FUN_0001bfb4(0x30ab9c,uVar6,uVar7);
  FUN_000104e0(uVar5);
  FUN_0001ca58(0x30ebf4,DAT_002ea988,iVar11,iVar10);
  FUN_0012d464(DAT_0033b574,param_2,param_3);
  FUN_000143b0(auStack_200,DAT_002ea9b4,iVar11,iVar10);
  FUN_00286938(DAT_0033b574 + 0x1320,auStack_200);
  FUN_0001cb88(0x30ebf4);
  FUN_00286f00(DAT_0034a118 + 0xe0,0,0,0,0,0,0,0);
  FUN_001277e8(DAT_0034a118);
  FUN_0012a254(DAT_0034a118,0,0xffffffff,1);
  if (DAT_0034a118 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)(DAT_0034a118 + 0xe0);
  }
  FUN_001c67e8(param_1,iVar3);
  FUN_0028b93c(*(undefined4 *)(param_1 + 0x17c),iVar11,iVar10);
  FUN_00225990(DAT_0034a2e0,iVar11,iVar10,0);
  uVar5 = *(undefined4 *)(param_3 * 4 + param_2 * 0x18 + 0x2ea7cc);
  if (param_2 == 7) {
    if (param_3 != 3) {
      uVar6 = *(undefined4 *)(param_1 + 0x160);
      goto LAB_001c7c84;
    }
    iVar3 = FUN_0022c988();
    if (iVar3 != 0) {
      uVar5 = 0xffffffff;
    }
  }
  uVar6 = *(undefined4 *)(param_1 + 0x160);
LAB_001c7c84:
  FUN_001b8f94(uVar6,uVar5);
  return;
}
// near miss from lane fm11 (unreviewed)
