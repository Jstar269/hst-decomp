/* HSTMATCH module=EBOOT.BIN start=0x00232660 end=0x00232b24 symbol=FUN_00232660 lang=c99 */
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

extern undefined4 DAT_002f3a04;
extern undefined4 DAT_002f3ab8;
extern undefined4 DAT_002f3ac4;
extern undefined DAT_002f3d08;
extern undefined4 DAT_002f3e50;
extern undefined4 DAT_002f3e54;
extern undefined4 DAT_002f3e58;
extern float DAT_002f3e5c;
extern undefined4 DAT_002f3e60;
extern float DAT_002f3e64;
extern int DAT_002f3e68;
extern undefined4 DAT_002f3e6c;
extern int DAT_002f3e70;
extern undefined4 DAT_002f3e74;
extern ulonglong FUN_0000b16c();
extern float FUN_0000bd2c(float param_1);
extern float FUN_0000bf34(float param_1);
extern int FUN_00020f5c();
extern int FUN_0002166c();
extern int FUN_00021748();
extern int FUN_000223a0();
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_000ffb3c();
extern void FUN_00103128();
extern code * FUN_0022cd60();
extern void FUN_00231ba0();
extern void FUN_00232084();
extern void FUN_0027fc70();

void FUN_00232660(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  FUN_00231ba0();
  FUN_00232084(param_1,0);
  if (*(char *)(param_1 + 0x1e8) == '\0') {
    uVar6 = FUN_000ede98(*(undefined4 *)(param_1 + 0x1ec),
                         *(undefined4 *)(*(int *)(param_1 + 0x1e0) * 4 + param_1 + 0x2a0),
                         DAT_002f3e50,DAT_002f3e54);
    *(undefined4 *)(param_1 + 0x1ec) = uVar6;
    uVar6 = FUN_000ede98(*(undefined4 *)(param_1 + 0x1f0),
                         *(undefined4 *)(*(int *)(param_1 + 0x1e0) * 4 + param_1 + 0x2c8),
                         DAT_002f3e50,DAT_002f3e54);
    *(undefined4 *)(param_1 + 0x1f0) = uVar6;
  }
  cVar1 = *(char *)(param_1 + 0x1e8);
  iVar4 = *(int *)(param_1 + 0xc4);
  if (cVar1 == '\0') {
    *(float *)(param_1 + 500) = *(float *)(param_1 + 500) + 1.0f;
    *(float *)(param_1 + 0x1f8) = *(float *)(param_1 + 0x1f8) + 1.0f;
  }
  else {
    *(undefined4 *)(param_1 + 500) = 0;
    *(undefined4 *)(param_1 + 0x1f8) = 0;
  }
  uVar6 = FUN_0000bf34(*(float *)(param_1 + 500) * DAT_002f3e5c * 0.017453292f);
  uVar10 = FUN_00020f5c(uVar6);
  uVar10 = FUN_0000b16c((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  uVar11 = FUN_00020f5c(DAT_002f3e58);
  uVar10 = FUN_00021748((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                        (int)((ulonglong)uVar10 >> 0x20));
  uVar10 = FUN_0002166c(0,0x3ff00000,(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  fVar7 = (float)FUN_000223a0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
  fVar7 = (float)FUN_0000bd2c(fVar7 * 32.0f);
  fVar9 = fVar7 / 2.0f;
  fVar8 = (float)FUN_0000bd2c((*(float *)(param_1 + 0x1ec) + 13.0f) - fVar9);
  *(short *)(iVar4 + 4) = (short)(int)fVar8;
  fVar8 = (float)FUN_0000bd2c((*(float *)(param_1 + 0x1f0) + 13.0f) - fVar9);
  iVar3 = 0;
  *(short *)(iVar4 + 6) = (short)(int)fVar8;
  *(short *)(iVar4 + 8) = *(short *)(iVar4 + 4) + (short)(int)fVar7;
  *(short *)(iVar4 + 10) = *(short *)(iVar4 + 6) + (short)(int)fVar7;
  iVar4 = param_1;
  do {
    puVar5 = *(uint **)(iVar4 + 0xf0);
    if ((iVar3 == *(int *)(param_1 + 0x1e0)) && (*(char *)(param_1 + 0x1e8) == '\0')) {
      uVar6 = FUN_0000bf34(*(float *)(param_1 + 0x1f8) * DAT_002f3e64 * 0.017453292f);
      uVar10 = FUN_00020f5c(uVar6);
      uVar10 = FUN_0000b16c((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
      uVar11 = FUN_00020f5c(DAT_002f3e60);
      uVar10 = FUN_00021748((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar10,
                            (int)((ulonglong)uVar10 >> 0x20));
      fVar7 = (float)FUN_000223a0((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    }
    else {
      fVar7 = 0.0f;
    }
    *puVar5 = (int)(fVar7 * 128.0f) << 0x18 | 0x808080;
    uVar6 = *(undefined4 *)(iVar4 + 200);
    if ((*(int *)(param_1 + 0x1dc) == 0) && (*(int *)(iVar4 + 0x200) == 4)) {
      FUN_000ffb3c(uVar6,0);
      FUN_0027fc70(param_1 + 0x1d4,uVar6,1);
    }
    else {
      FUN_000ffb3c(uVar6,1);
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 10);
  iVar4 = *(int *)(param_1 + 0x68);
  iVar3 = DAT_002f3a04 + *(int *)(param_1 + 0x1e0);
  *(int *)(iVar4 + 0x24) = iVar3;
  *(int *)(iVar4 + 0x28) = iVar3;
  iVar4 = (int)(FUN_0022cd60());
  iVar4 = *(int *)(iVar4 + 0x138);
  FUN_000ffb3c(*(undefined4 *)(param_1 + 0x9c),1);
  FUN_000ffb3c(*(undefined4 *)(param_1 + 0xa0),1);
  iVar3 = (int)(FUN_0022cd60());
  if (*(int *)(iVar3 + 0x138) == 0) {
    iVar3 = -3;
  }
  else {
    iVar3 = 0;
  }
  iVar2 = (uint)(iVar4 == 2) * 0x50;
  iVar3 = *(int *)(*(int *)(&DAT_002f3d08 + *(int *)(param_1 + 0x1e0) * 4) * 8 + iVar2 + 0x2f3d20) +
          iVar3;
  iVar4 = DAT_002f3e68;
  if ((DAT_002f3e68 <= iVar3) && (iVar4 = DAT_002f3e6c, iVar3 <= DAT_002f3e6c)) {
    iVar4 = iVar3;
  }
  iVar3 = *(int *)(param_1 + 0xa4);
  iVar4 = DAT_002f3ab8 + iVar4;
  *(int *)(iVar3 + 0x24) = iVar4;
  *(int *)(iVar3 + 0x28) = iVar4;
  iVar4 = (int)(FUN_0022cd60());
  if (*(int *)(iVar4 + 0x138) == 0) {
    iVar4 = -3;
  }
  else {
    iVar4 = 0;
  }
  iVar4 = *(int *)(*(int *)(&DAT_002f3d08 + *(int *)(param_1 + 0x1e0) * 4) * 8 + iVar2 + 0x2f3d24) +
          iVar4;
  iVar3 = DAT_002f3e70;
  if ((DAT_002f3e70 <= iVar4) && (iVar3 = DAT_002f3e74, iVar4 <= DAT_002f3e74)) {
    iVar3 = iVar4;
  }
  iVar4 = *(int *)(param_1 + 0xa8);
  iVar3 = DAT_002f3ac4 + iVar3;
  *(int *)(iVar4 + 0x24) = iVar3;
  *(int *)(iVar4 + 0x28) = iVar3;
  FUN_00103128(param_1);
  return;
}
// near miss from lane fm11 (unreviewed)
