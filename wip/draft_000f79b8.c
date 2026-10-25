/* HSTMATCH module=EBOOT.BIN start=0x000f79b8 end=0x000f7e30 symbol=FUN_000f79b8 lang=c99 */
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

extern undefined DAT_002c0c74;
extern undefined4 DAT_002d6c9c;
extern char DAT_002d79e0[];
extern char DAT_002d7a13[];
extern char DAT_002d8234[];
extern void FUN_00000020();
extern void FUN_00000028();
extern int FUN_00000bcc();
extern undefined4 * FUN_00050fc0();
extern void FUN_000511c4();
extern void FUN_00051398();
extern undefined4 * FUN_000ee6d4();
extern undefined4 * FUN_000eea78();
extern undefined4 * FUN_000eed74();
extern undefined4 * FUN_000eef78();
extern undefined4 * FUN_000efe28();
extern undefined4 * FUN_000f0b64();
extern undefined4 * FUN_000f13e8();
extern undefined4 * FUN_000f1828();
extern int * FUN_000f2024();
extern undefined4 * FUN_000f2410();
extern undefined4 * FUN_000f31e0();
extern undefined4 * FUN_000f5ba8();
extern undefined4 * FUN_000f7558();
extern int FUN_000f7680();
extern void FUN_00103628();
extern undefined4 * FUN_001ea814();
extern undefined4 * FUN_001ec2f8();
extern void FUN_001ecbbc();

void FUN_000f79b8(int param_1)
{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00000020(DAT_002d8234);
  if (*(int *)(param_1 + 0x98) == 0) {
    iVar1 = FUN_00000bcc(4);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    else {
      uVar6 = (unsigned int)(FUN_001ea814(iVar1));
      *(undefined4 *)(param_1 + 0x98) = uVar6;
    }
    iVar1 = *(int *)(param_1 + 0x90);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x90);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_00000bcc(0x880);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x90) = 0;
    }
    else {
      uVar6 = FUN_000f7680(iVar1);
      *(undefined4 *)(param_1 + 0x90) = uVar6;
    }
  }
  iVar1 = FUN_00000bcc(0x220);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x54) = 0;
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_000f31e0(iVar1,0);
    *(int **)(param_1 + 0x54) = piVar2;
  }
  (**(code **)(*piVar2 + 0xc))(piVar2);
  iVar1 = FUN_00000bcc(0xa4);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(FUN_000ee6d4(iVar1));
  }
  *(int *)(param_1 + 0x58) = iVar1;
  FUN_00103628(iVar1,1);
  *(undefined1 *)(iVar1 + 0x54) = 1;
  if (*(char *)(param_1 + 0x156) == '\0') {
    iVar1 = FUN_00000bcc(0x94);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)(FUN_000eea78(iVar1));
    }
    *(int *)(param_1 + 0x5c) = iVar1;
    FUN_00103628(iVar1,1);
    *(undefined1 *)(iVar1 + 0x54) = 1;
  }
  else {
    iVar1 = FUN_00000bcc(0x74);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (int)(FUN_000eed74(iVar1));
    }
    *(int *)(param_1 + 0x60) = iVar1;
    FUN_00103628(iVar1,1);
    *(undefined1 *)(iVar1 + 0x54) = 1;
  }
  iVar1 = FUN_00000bcc(200);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(FUN_000eef78(iVar1));
  }
  *(int *)(param_1 + 100) = iVar1;
  FUN_00103628(iVar1,1);
  *(undefined1 *)(iVar1 + 0x54) = 1;
  iVar1 = FUN_00000bcc(0x98);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)(FUN_000efe28(iVar1));
  }
  *(int *)(param_1 + 0x68) = iVar1;
  FUN_00103628(iVar1,1);
  *(undefined1 *)(iVar1 + 0x54) = 1;
  *(undefined4 *)(iVar1 + 0x94) = 0;
  iVar1 = FUN_00000bcc(0xb8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f13e8(iVar1));
    *(undefined4 *)(param_1 + 0x6c) = uVar6;
  }
  iVar1 = FUN_00000bcc(0x98);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f1828(iVar1));
    *(undefined4 *)(param_1 + 0x70) = uVar6;
  }
  iVar1 = FUN_00000bcc(0x88);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f2024(iVar1));
    *(undefined4 *)(param_1 + 0x74) = uVar6;
  }
  iVar1 = FUN_00000bcc(0xa8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x78) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f2410(iVar1));
    *(undefined4 *)(param_1 + 0x78) = uVar6;
  }
  puVar3 = (undefined1 *)FUN_00000bcc(0xc);
  if (puVar3 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar3 + 8) = 0;
    iVar1 = FUN_00000bcc(0x48);
    uVar6 = 0;
    if (iVar1 != 0) {
      uVar6 = (unsigned int)(FUN_00050fc0(iVar1));
    }
    *(undefined4 *)(puVar3 + 8) = uVar6;
    FUN_000511c4(uVar6,DAT_002d79e0,0);
    FUN_00051398(DAT_002d6c9c,*(undefined4 *)(puVar3 + 8));
    *(undefined4 *)(puVar3 + 4) = 0;
    puVar3[1] = 0;
    *puVar3 = 1;
  }
  *(undefined1 **)(param_1 + 0x7c) = puVar3;
  puVar3 = (undefined1 *)FUN_00000bcc(0xc);
  if (puVar3 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar3 + 4) = 0;
    iVar1 = FUN_00000bcc(0x48);
    uVar6 = 0;
    if (iVar1 != 0) {
      uVar6 = (unsigned int)(FUN_00050fc0(iVar1));
    }
    *(undefined4 *)(puVar3 + 4) = uVar6;
    FUN_000511c4(uVar6,DAT_002d7a13 + 1,0);
    FUN_00051398(DAT_002d6c9c,*(undefined4 *)(puVar3 + 4));
    *(undefined4 *)(puVar3 + 8) = 0xbf800000;
    puVar3[1] = 1;
    *puVar3 = 1;
    *(undefined4 *)(puVar3 + 8) = 0xbf800000;
  }
  *(undefined1 **)(param_1 + 0x80) = puVar3;
  iVar1 = FUN_00000bcc(0xa4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f0b64(iVar1));
    *(undefined4 *)(param_1 + 0x84) = uVar6;
  }
  iVar1 = FUN_00000bcc(0x4a0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f5ba8(iVar1));
    *(undefined4 *)(param_1 + 0x88) = uVar6;
  }
  iVar1 = FUN_00000bcc(0x880);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_000f7558(iVar1));
    *(undefined4 *)(param_1 + 0x8c) = uVar6;
  }
  iVar1 = FUN_00000bcc(0x20);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x94) = 0;
    uVar6 = 0;
  }
  else {
    uVar6 = (unsigned int)(FUN_001ec2f8(iVar1));
    *(undefined4 *)(param_1 + 0x94) = uVar6;
  }
  FUN_001ecbbc(uVar6,*(undefined4 *)(param_1 + 0x98));
  uVar4 = 0;
  iVar1 = param_1;
  do {
    uVar4 = uVar4 + 1;
    *(undefined4 *)(iVar1 + 0x9c) = 0;
    iVar1 = iVar1 + 4;
  } while (uVar4 < 0xb);
  uVar4 = 0;
  puVar5 = (unsigned int *)(&DAT_002c0c74);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x58);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x5c);
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x60);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(*(int *)(param_1 + 0x54) + 100);
  *(undefined4 *)(param_1 + 0xbc) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x1b8) + 0x58);
  *(undefined4 *)(param_1 + 0xc0) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x1b8) + 0x5c);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(*(int *)(param_1 + 0x74) + 0x54);
  iVar1 = param_1;
  do {
    uVar6 = puVar5[1];
    uVar7 = puVar5[2];
    *(undefined4 *)(iVar1 + 200) = *puVar5;
    *(undefined4 *)(iVar1 + 0xcc) = uVar6;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(iVar1 + 0xd0) = uVar7;
    puVar5 = puVar5 + 3;
    iVar1 = iVar1 + 0xc;
  } while (uVar4 < 0xb);
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined1 *)(param_1 + 0x154) = 1;
  *(undefined1 *)(param_1 + 0x155) = 0;
  FUN_00000028();
  return;
}
// near miss from lane fm11 (unreviewed)
