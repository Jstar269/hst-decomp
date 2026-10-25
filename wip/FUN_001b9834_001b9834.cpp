/* HSTMATCH module=EBOOT.BIN start=0x001b9834 end=0x001b9b0c symbol=FUN_001b9834 lang=c99 */
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

extern undefined * DAT_003313c4;
extern undefined * DAT_00331b84;
extern undefined * DAT_00331b88;
extern undefined * DAT_003415ac;
extern float FUN_0000c000(float param_1);
extern void FUN_00049774(void *);
extern void FUN_00049970(float *, void *);
extern void FUN_00049d34(void *);
extern float FUN_00049da4();
extern float FUN_00049e68();
extern float FUN_00049ec4();
extern float FUN_00049fbc();
extern float FUN_0004a080();
extern void FUN_0005bc58();

void FUN_001b9834(char *param_1)
{
  float *output;
  int bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float auStack_40 [16];
  
  if (*(int **)(param_1 + 0x3c) == (int *)0x0) {
    return;
  }
  if ((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) != 0) {
    bVar1 = 0;
  } else {
    bVar1 = 1;
  }
  if (bVar1) {
    fVar8 = *(float *)(param_1 + 0x44);
  }
  else {
    iVar4 = **(int **)(param_1 + 0x3c);
    iVar6 = *(int *)(iVar4 + 0x158);
    if (iVar6 <= *(int *)(iVar4 + 0x15c)) {
      iVar5 = iVar4 + iVar6 * 0x34;
      iVar7 = iVar6;
      do {
        if (*(int **)(iVar5 + 0xf4) == (int *)0x0) {
          fVar8 = 0.0f;
        }
        else {
          fVar8 = *(float *)(**(int **)(iVar5 + 0xf4) + 8);
        }
        if (*(float *)(iVar5 + 0x104) < fVar8) {
          bVar2 = false;
          goto LAB_001b9900;
        }
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 0x34;
      } while (iVar7 <= *(int *)(iVar4 + 0x15c));
    }
    bVar2 = true;
LAB_001b9900:
    if (bVar2) {
LAB_001b996c:
      *(undefined1 *)(param_1 + 0x40) = 1;
      return;
    }
    if (*(int *)(iVar4 + 0x15c) < iVar6) {
      bVar2 = false;
    }
    else {
      iVar7 = iVar4 + iVar6 * 0x34;
      do {
        if (*(float *)(iVar7 + 0x10c) != 0.0f) {
          bVar2 = true;
          goto LAB_001b9960;
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x34;
      } while (iVar6 <= *(int *)(iVar4 + 0x15c));
      bVar2 = false;
    }
LAB_001b9960:
    if (!bVar2) goto LAB_001b996c;
    fVar8 = *(float *)(param_1 + 0x44);
  }
  *(float *)(param_1 + 0x44) = fVar8 + 1.0f;
  if (*(undefined1 *)(param_1 + 0x41) == 0 || *(float *)(param_1 + 0x44) < 60.0f) {
    FUN_00049774(*(int **)(param_1 + 0x3c));
  }
  FUN_00049970(auStack_40,*(int **)(param_1 + 0x3c));
  FUN_00049d34(*(undefined4 **)(param_1 + 0x3c));
  iVar4 = (int)DAT_003313c4;
  *(float *)(iVar4 + 0x1d0) = auStack_40[12];
  *(float *)(iVar4 + 0x1d4) = auStack_40[13];
  *(float *)(iVar4 + 0x1d8) = auStack_40[14];
  *(float *)(iVar4 + 0x1dc) = auStack_40[15];
  iVar4 = (int)DAT_003313c4;
  *(float *)(iVar4 + 0x1e0) = auStack_40[8];
  *(float *)(iVar4 + 0x1e4) = auStack_40[9];
  *(float *)(iVar4 + 0x1e8) = auStack_40[10];
  *(float *)(iVar4 + 0x1ec) = auStack_40[11];
  iVar4 = (int)DAT_003313c4;
  *(float *)(iVar4 + 0x1f0) = auStack_40[4];
  *(float *)(iVar4 + 0x1f4) = auStack_40[5];
  *(float *)(iVar4 + 0x1f8) = auStack_40[6];
  *(float *)(iVar4 + 0x1fc) = auStack_40[7];
  fVar8 = FUN_00049da4(*(undefined4 **)(param_1 + 0x3c));
  output = (float *)DAT_003313c4;
  output[128] = fVar8 * 57.29578f;
  fVar8 = FUN_0000c000(output[128] * 0.008726646f);
  output[133] = fVar8;
  fVar8 = FUN_00049e68(*(undefined4 **)(param_1 + 0x3c));
  *(float *)(DAT_003313c4 + 0x204) = fVar8;
  fVar8 = FUN_00049ec4(*(undefined4 **)(param_1 + 0x3c));
  *(float *)(DAT_003313c4 + 0x208) = fVar8;
  FUN_00049fbc(*(int **)(param_1 + 0x3c));
  FUN_0004a080(*(int **)(param_1 + 0x3c));
  FUN_0005bc58(DAT_003313c4);
  iVar4 = (int)(DAT_00331b84);
  if (bVar1) {
    *(undefined4 *)(DAT_00331b84 + 0xc) = 0;
    *(undefined1 *)(iVar4 + 0x52) = 0;
    iVar4 = (int)(DAT_00331b88);
    *(undefined4 *)(DAT_00331b88 + 0xc) = 0;
    *(undefined1 *)(iVar4 + 0x52) = 0;
  }
  return;
}
// Near miss: 97 of 182 words differ. The 16-float stack buffer and its copies match, but the loop and saved-register coloring still diverge.
// Ruled out bool/int flag forms, char/int parameter forms, float comparison orientations, pointer reuse and declaration order, and a C++ build.
// near miss from lane km5 (unreviewed)
