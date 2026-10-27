/* HSTMATCH module=EBOOT.BIN start=0x000b1e34 end=0x000b2144 symbol=FUN_000b1e34 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined * DAT_003386b0;
extern undefined1 DAT_003386b8;
extern undefined * DAT_00338af0;
extern void * DAT_00338c20;
extern float DAT_003411fc;
extern undefined4 DAT_00341284;
extern undefined4 DAT_00341288;
extern undefined4 DAT_00341314;
extern int FUN_0008882c(int param_1);
extern undefined4 FUN_000b3490(int param_1);
extern int FUN_000b3c68(int param_1);
extern int FUN_000c4ba0(int param_1,int param_2);
extern void FUN_000fb0d4(void *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5, undefined4 param_6,undefined4 param_7,int param_8);

void FUN_000b1e34(char *param_1,int param_2,int param_3)
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  float fVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  switch (param_3) {
  case 0: {
    uVar3 = FUN_000b3490((int)param_1);
    iVar4 = *(int *)(param_1 + 0x484);
    iVar6 = iVar4;
    if (iVar4 < 0) {
      iVar6 = -iVar4;
    }
    if (param_2 == 0) {
      if ((uVar3 & 0xff) == 0) {
        if (DAT_00341284 < iVar4) {
          iVar6 = 8;
        }
        else if (iVar4 < DAT_00341288) {
          iVar6 = 8;
        }
        else if (0 < iVar6) {
          if (iVar4 < 8) {
            if (iVar4 < -7) {
              iVar6 = 0xc;
            }
            else if (iVar4 < 1) {
              iVar6 = 2;
            }
            else {
              iVar6 = 1;
            }
          }
          else {
            iVar6 = 0xb;
          }
        }
        else {
          iVar6 = 0;
        }
      }
      else if (0 < iVar6) {
        if (iVar4 < 1) {
          iVar6 = 10;
        }
        else {
          iVar6 = 9;
        }
      }
      else {
        iVar6 = 0xd;
      }
    }
    else {
      iVar6 = 3;
    }
    break;
  }
  default:
    iVar6 = 0x11;
    break;
  }
  *(undefined1 *)(param_1 + 0x480) = 1;
  *(char *)(param_1 + 0x4ce) = (char)param_2;
  if (*(int *)(param_1 + 0x3c) == 7) {
    iVar4 = *(int *)(param_1 + 0x5bc);
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0x484);
    bVar1 = false;
    if (DAT_003386b8 != '\0') {
      bVar1 = *(char *)(param_1 + 0x1b4) == '\0';
    }
    if ((bVar1) && (DAT_00338af0 != 0)) {
      iVar4 = FUN_000c4ba0((int)(DAT_00338af0),(int)(*(int *)(param_1 + 0x148)));
      *(undefined4 *)(iVar4 + 0x134) = *(undefined4 *)(DAT_00338af0 + 0x780);
      *(char *)(iVar4 + 0x130) = (char)uVar5;
      *(char *)(iVar4 + 0x131) = (char)param_2;
    }
    iVar4 = *(int *)(param_1 + 0x5bc);
  }
  if ((*(int *)(iVar4 + 0x58) != 0) && (*(int *)(*(int *)(iVar4 + 0x58) + 0x8c) != 0)) {
    if (*(int *)(DAT_003386b0 + 0x3c) == 7) {
      iVar4 = *(int *)(param_1 + 0x41c);
    }
    else {
      iVar4 = FUN_0008882c((int)(DAT_003386b0));
      if ((*(int *)(param_1 + 0x144) != *(int *)(iVar4 + 0x144)) && (param_3 == 0)) {
        return;
      }
      iVar4 = *(int *)(param_1 + 0x41c);
    }
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x5bc) + 4);
    if ((float)iVar4 / DAT_00341314 < 1.0f) {
      uVar3 = 0;
    }
    else {
      fVar7 = *(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x14);
      iVar4 = FUN_000b3c68((int)param_1);
      if (DAT_003411fc * 0.01f * -(*(float *)(iVar4 + 0x24) * 0.01f) < fVar7) {
        if (fVar7 < 0.0f) {
          bVar2 = 1;
        }
        else {
          bVar2 = 0;
        }
      }
      else {
        bVar2 = 0;
      }
      uVar3 = bVar2 ^ 1;
    }
    if (uVar3 == 0) {
      local_10 = 0;
    }
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_000fb0d4(DAT_00338c20,(int)(iVar6),(int)(*(int *)(*(int *)(param_1 + 0x5bc) + 0x58)),(undefined4)(uVar5),(undefined4)((uint)*(byte *)(param_1 + 0x4cf)),(undefined4)(&local_10),(undefined4)(*(undefined4 *)(param_1 + 0x484)),(int)(uVar3));
    if ((*(int *)(param_1 + 0x4e8) != 1) && (param_3 == 0)) {
      *(float *)(param_1 + 0x48c) = (float)*(int *)(param_1 + 0x484);
      *(undefined4 *)(param_1 + 0x490) = 0xffffffd3;
    }
  }
  return;
}
// Near miss: 154 of 196 words differ; the initial state-code branch and later parameter/register scheduling still diverge.
// Ruled out outer-if versus switch forms, int/byte return forms for the mode helper, pointer-typed global/helper forms, and scalar versus array output buffers.
// near miss from lane km5 (unreviewed)

}  /* extern "C" */
// improved by lane dsm1 (unreviewed): no comparable result -> 154 differing words
