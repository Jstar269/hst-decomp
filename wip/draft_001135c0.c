/* HSTMATCH module=EBOOT.BIN start=0x001135c0 end=0x00113a70 symbol=FUN_001135c0 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern float DAT_002d9368;
extern float DAT_002d936c;
extern void FUN_000ffb3c();
extern void FUN_00112ed8(float param_1,int *param_2,int param_3);

void FUN_001135c0(undefined4 *param_1)
{
  short sVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  
  iVar10 = param_1[3];
  if ((*(ushort *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar10 * 4) + 0xe) & 3) == 0) {
    param_1[5] = (float)param_1[5] + ((float)param_1[6] - (float)param_1[5]) * 0.16f;
    fVar12 = 0.0f;
    if (((0.0f < (float)param_1[8] - (float)param_1[7]) &&
        (fVar11 = (float)param_1[5] / ((float)param_1[8] - (float)param_1[7]) + 0.0005f,
        fVar12 = DAT_002d9368, DAT_002d9368 <= fVar11)) &&
       (fVar12 = DAT_002d936c, fVar11 <= DAT_002d936c)) {
      fVar12 = fVar11;
    }
    iVar9 = (iVar10 + 5) * 4;
    iVar8 = (iVar10 + 3) * 4;
    iVar4 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9);
    iVar5 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar8);
    iVar2 = (int)((float)(int)param_1[4] * fVar12) + -0x10;
    iVar4 = (int)(short)(*(short *)(iVar5 + 8) - *(short *)(iVar5 + 4)) +
            (int)(short)(*(short *)(iVar4 + 8) - *(short *)(iVar4 + 4));
    if (iVar4 <= iVar2) {
      iVar4 = iVar2;
    }
    if (fVar12 < 0.001f) {
      FUN_000ffb3c(iVar5,1);
      FUN_000ffb3c(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + (iVar10 + 4) * 4),1);
      FUN_000ffb3c(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9),1);
    }
    else {
      FUN_000ffb3c(iVar5,0);
      iVar7 = (iVar10 + 4) * 4;
      FUN_000ffb3c(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar7),0);
      FUN_000ffb3c(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9),0);
      iVar2 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar10 * 4);
      iVar5 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar8);
      sVar6 = *(short *)(iVar2 + 6) + 8;
      sVar1 = *(short *)(iVar5 + 4);
      sVar3 = *(short *)(iVar2 + 4) + 8;
      *(short *)(iVar5 + 4) = sVar3;
      *(short *)(iVar5 + 8) = *(short *)(iVar5 + 8) + (sVar3 - sVar1);
      sVar1 = *(short *)(iVar5 + 6);
      *(short *)(iVar5 + 6) = sVar6;
      *(short *)(iVar5 + 10) = *(short *)(iVar5 + 10) + (sVar6 - sVar1);
      iVar5 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar8);
      iVar2 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9);
      sVar1 = *(short *)(iVar5 + 6);
      sVar3 = *(short *)(iVar2 + 4);
      sVar6 = ((short)iVar4 + *(short *)(iVar5 + 4)) -
              (*(short *)(iVar2 + 8) - *(short *)(iVar2 + 4));
      *(short *)(iVar2 + 4) = sVar6;
      *(short *)(iVar2 + 8) = *(short *)(iVar2 + 8) + (sVar6 - sVar3);
      sVar3 = *(short *)(iVar2 + 6);
      *(short *)(iVar2 + 6) = sVar1;
      *(short *)(iVar2 + 10) = *(short *)(iVar2 + 10) + (sVar1 - sVar3);
      *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar7) + 4) =
           *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar8) + 8);
      *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar7) + 6) =
           *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar8) + 6);
      *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar7) + 8) =
           *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9) + 4);
      *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar7) + 10) =
           *(undefined2 *)(*(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar9) + 10);
    }
    FUN_00112ed8(fVar12 * 100.0f,(int *)param_1[1],0);
    iVar4 = (iVar10 + 9) * 4;
    iVar5 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + (iVar10 + 8) * 4);
    iVar10 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar4);
    iVar2 = (int)(short)(*(short *)(iVar5 + 10) - *(short *)(iVar5 + 6)) -
            (int)(short)(*(short *)(iVar10 + 10) - *(short *)(iVar10 + 6));
    sVar1 = *(short *)(iVar5 + 8);
    sVar3 = *(short *)(iVar10 + 4);
    sVar6 = *(short *)(iVar5 + 6) + (short)(iVar2 / 2);
    *(short *)(iVar10 + 4) = sVar1;
    *(short *)(iVar10 + 8) = *(short *)(iVar10 + 8) + (sVar1 - sVar3);
    sVar1 = *(short *)(iVar10 + 6);
    *(short *)(iVar10 + 6) = sVar6;
    *(short *)(iVar10 + 10) = *(short *)(iVar10 + 10) + (sVar6 - sVar1);
    iVar10 = *(int *)(*(int *)(*(int *)*param_1 + 0x10) + iVar4);
    *(short *)(iVar10 + 4) = *(short *)(iVar10 + 4) + 4;
    *(short *)(iVar10 + 8) = *(short *)(iVar10 + 8) + 4;
  }
  return;
}
// near miss from lane fm11 (unreviewed)
