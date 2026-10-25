/* HSTMATCH module=EBOOT.BIN start=0x0024ad34 end=0x0024b258 symbol=FUN_0024ad34 lang=c99 */
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
extern undefined * DAT_003386b0;
extern undefined * DAT_00340284;
extern undefined4 DAT_0034a748;
extern undefined4 * FUN_00022434();
extern undefined4 FUN_000224d8();
extern void FUN_00055724();
extern float FUN_00055768();
extern void FUN_0005f1e8();
extern undefined1 FUN_00131cf8();

void FUN_0024ad34(int param_1)
{
  char cVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined1 auStack_10 [16];
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  
  if ((*(int *)(DAT_00340284 + 0x8c) == 0) || (iVar2 = FUN_00131cf8(), iVar2 != 0)) {
    if (*(float *)(param_1 + 0x4c4) < *(float *)(DAT_003313c4 + 0x1d8)) {
      if (*(float *)(param_1 + 0x4c4) < *(float *)(param_1 + 0x148)) {
        cVar1 = *(char *)(param_1 + 0x4b0);
        goto LAB_0024b214;
      }
      if ((*(char *)(param_1 + 0x465) != '\0') && (*(char *)(param_1 + 0x466) != '\0')) {
        iVar2 = *(int *)(param_1 + 0x3c);
        if (iVar2 == 1) {
          if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x454) == 0x66)) {
            FUN_0005f1e8(param_1 + 0x290,0);
          }
          else {
            FUN_0005f1e8(param_1 + 0xe0,0);
          }
        }
        else if ((iVar2 == 2) || (iVar2 == 4)) {
          FUN_0005f1e8(param_1 + 0xe0,0);
        }
        else if ((iVar2 == 3) || (iVar2 == 5)) {
          FUN_0005f1e8(param_1 + 0x290,0);
        }
      }
    }
    else if (*(float *)(DAT_003313c4 + 0x1d8) < *(float *)(param_1 + 0x4c8)) {
      if (((*(float *)(param_1 + 0x4c8) <= *(float *)(param_1 + 0x148)) &&
          (*(char *)(param_1 + 0x465) != '\0')) && (*(char *)(param_1 + 0x466) != '\0')) {
        iVar2 = *(int *)(param_1 + 0x3c);
        if (iVar2 == 1) {
          if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x454) == 0x66)) {
            FUN_0005f1e8(param_1 + 0x290,0);
          }
          else {
            FUN_0005f1e8(param_1 + 0xe0,0);
          }
        }
        else if ((iVar2 == 2) || (iVar2 == 4)) {
          FUN_0005f1e8(param_1 + 0xe0,0);
        }
        else if ((iVar2 == 3) || (iVar2 == 5)) {
          FUN_0005f1e8(param_1 + 0x290,0);
        }
      }
    }
    else if ((*(char *)(param_1 + 0x465) != '\0') && (*(char *)(param_1 + 0x466) != '\0')) {
      iVar2 = *(int *)(param_1 + 0x3c);
      if (iVar2 == 1) {
        if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x454) == 0x66)) {
          FUN_0005f1e8(param_1 + 0x290,0);
        }
        else {
          FUN_0005f1e8(param_1 + 0xe0,0);
        }
      }
      else if ((iVar2 == 2) || (iVar2 == 4)) {
        FUN_0005f1e8(param_1 + 0xe0,0);
      }
      else if ((iVar2 == 3) || (iVar2 == 5)) {
        FUN_0005f1e8(param_1 + 0x290,0);
      }
    }
  }
  else if (*(int *)(DAT_00340284 + 0x8c) == 2) {
    FUN_00055724(auStack_10,param_1 + 0xe0);
    local_20 = *(undefined4 *)(DAT_003313c4 + 0x1d0);
    local_1c = *(undefined4 *)(DAT_003313c4 + 0x1d4);
    local_18 = *(undefined4 *)(DAT_003313c4 + 0x1d8);
    local_14 = *(undefined4 *)(DAT_003313c4 + 0x1dc);
    FUN_00022434(&local_40,&local_20,auStack_10);
    local_28 = local_38;
    local_30 = local_40;
    local_2c = local_3c;
    local_24 = local_34;
    fVar3 = (float)FUN_00055768(param_1 + 0xe0);
    fVar4 = (float)FUN_000224d8(&local_30,&local_30);
    if ((((fVar3 + 3.0f) * (fVar3 + 3.0f) < fVar4) && (*(char *)(param_1 + 0x465) != '\0')) &&
       (*(char *)(param_1 + 0x466) != '\0')) {
      iVar2 = *(int *)(param_1 + 0x3c);
      if (iVar2 == 1) {
        if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x454) == 0x66)) {
          FUN_0005f1e8(param_1 + 0x290,0);
        }
        else {
          FUN_0005f1e8(param_1 + 0xe0,0);
        }
      }
      else if ((iVar2 == 2) || (iVar2 == 4)) {
        FUN_0005f1e8(param_1 + 0xe0,0);
      }
      else if ((iVar2 == 3) || (iVar2 == 5)) {
        FUN_0005f1e8(param_1 + 0x290,0);
      }
    }
  }
  else if ((*(char *)(param_1 + 0x465) != '\0') && (*(char *)(param_1 + 0x466) != '\0')) {
    iVar2 = *(int *)(param_1 + 0x3c);
    if (iVar2 == 1) {
      if ((*(int *)(param_1 + 0x4e0) == 1) && (*(int *)(param_1 + 0x454) == 0x66)) {
        FUN_0005f1e8(param_1 + 0x290,0);
      }
      else {
        FUN_0005f1e8(param_1 + 0xe0,0);
      }
    }
    else if ((iVar2 == 2) || (iVar2 == 4)) {
      FUN_0005f1e8(param_1 + 0xe0,0);
    }
    else if ((iVar2 == 3) || (iVar2 == 5)) {
      FUN_0005f1e8(param_1 + 0x290,0);
    }
  }
  cVar1 = *(char *)(param_1 + 0x4b0);
LAB_0024b214:
  if ((cVar1 != '\0') && (*(int *)(DAT_003386b0 + 0x3c) != 9)) {
    FUN_0005f1e8(DAT_0034a748,0);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
