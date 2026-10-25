/* HSTMATCH module=EBOOT.BIN start=0x001ef424 end=0x001ef824 symbol=FUN_001ef424 lang=c99 */
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

extern undefined4 DAT_002ee808;
extern undefined4 DAT_003313c4;
extern undefined4 DAT_00331b84;
extern undefined * DAT_003386b0;
extern undefined DAT_0034179c;
extern undefined4 DAT_003417b8;
extern char DAT_002ee80c[];
extern void FUN_0005bbd4();
extern void FUN_0005c7a4(int param_1,int param_2,float *param_3);
extern void FUN_00063b20();
extern undefined4 FUN_00065740();
extern int FUN_001b1c44();
extern void FUN_001b7298();
extern void FUN_001e075c();
extern void FUN_001e09dc();
extern void FUN_001f3a30();
extern void FUN_001f483c();
extern void FUN_001f4bbc();
extern void FUN_001f4bfc();
extern void FUN_001f4c54();
extern void FUN_001f4d44();
extern void FUN_001fb928();
extern void FUN_001ff668();
extern void FUN_00216d60();
extern void FUN_00216de0();

void FUN_001ef424(int param_1,char *param_2,float *param_3,int *param_4,uint param_5, undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x584) + 0x98) = 0;
    iVar3 = *(int *)(param_1 + 0x584);
    FUN_0005bbd4(0,0,0x43f00000,0x43880000,0x43700000,0x43080000,DAT_003313c4);
    param_3 = (float *)(iVar3 + 0xf0);
    param_2 = (char *)0x0;
    FUN_0005c7a4(DAT_003313c4,0,param_3);
    FUN_001f3a30(param_1,param_2,param_3,(int)param_4,param_5,param_6,param_7,param_8);
    if (*(int *)(param_1 + 0x510) == 0) {
      *(undefined4 *)(param_1 + 0x558) = 0;
    }
    else {
      param_2 = (char *)0x0;
      FUN_001e09dc(*(int *)(param_1 + 0x510),0);
      *(undefined4 *)(param_1 + 0x558) = 0;
    }
    FUN_00216de0(*(undefined1 **)(param_1 + 0x560));
    if (*(int *)(param_1 + 0x524) == 5) {
      param_2 = (char *)0x1;
      FUN_00216d60(*(undefined1 **)(param_1 + 0x560),1);
    }
    else if (*(char *)(param_1 + 0x521) == '\0') {
      param_2 = (char *)0x0;
      FUN_00216d60(*(undefined1 **)(param_1 + 0x560),0);
    }
    if (DAT_003417b8 != '\x01') {
      iVar3 = *(int *)(param_1 + 0x44);
      goto LAB_001ef544;
    }
    if ((*(char *)(param_1 + 0x521) != '\0') && (*(int *)(param_1 + 0x5b4) == -1)) {
      param_2 = (char *)0x47;
      iVar3 = FUN_001b1c44((int *)&DAT_0034179c,0x47);
      *(int *)(param_1 + 0x5b4) = iVar3;
    }
  }
  iVar3 = *(int *)(param_1 + 0x44);
LAB_001ef544:
  if (iVar3 == 1) {
    if (((DAT_003417b8 != '\x01') || (*(char *)(param_1 + 0x521) == '\0')) &&
       (*(int *)(DAT_003386b0 + 0xa8) != 0)) {
      param_2 = *(char **)(param_1 + 0x524);
      FUN_001b7298(*(int *)(DAT_003386b0 + 0xa8),(int)param_2);
    }
    FUN_001f4c54(param_1);
  }
  if (DAT_002ee808 == *(int *)(param_1 + 0x44)) {
    FUN_001f4d44(param_1);
    iVar3 = *(int *)(param_1 + 0x3c4);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x3c4);
  }
  if (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 0x58);
    if (iVar3 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = *(uint *)(iVar3 + 0xf0);
    }
    if (uVar2 < 2) {
      if (iVar3 == 0) {
        fVar6 = 0.0f;
      }
      else {
        fVar6 = *(float *)(iVar3 + 0x104);
      }
      param_2 = DAT_002ee80c;
      param_3 = (float *)0x1;
      iVar3 = FUN_00065740(*(int *)(*(int *)(param_1 + 0x584) + 0x90),DAT_002ee80c,1);
      if ((int)fVar6 == iVar3) {
        FUN_001f4bbc(param_1);
        param_2 = (char *)0x46;
        FUN_001b1c44((int *)&DAT_0034179c,0x46);
        if (*(int *)(DAT_003386b0 + 0xa8) != 0) {
          param_2 = *(char **)(param_1 + 0x524);
          FUN_001b7298(*(int *)(DAT_003386b0 + 0xa8),(int)param_2);
        }
      }
    }
  }
  FUN_001f4bfc();
  FUN_001f483c(param_1);
  if (*(int *)(param_1 + 0x558) == 0) {
    if (*(int **)(param_1 + 0x3c0) != (int *)0x0) {
      iVar3 = **(int **)(param_1 + 0x3c0);
      param_3 = *(float **)(iVar3 + 0x158);
      if (*(int *)(iVar3 + 0x15c) < (int)param_3) {
        bVar1 = true;
      }
      else {
        param_2 = (char *)(iVar3 + (int)param_3 * 0x34);
        do {
          if (*(int **)(param_2 + 0xf4) == (int *)0x0) {
            fVar6 = 0.0f;
          }
          else {
            fVar6 = *(float *)(**(int **)(param_2 + 0xf4) + 8);
          }
          if (*(float *)(param_2 + 0x104) < fVar6) {
            bVar1 = false;
            goto LAB_001ef6e4;
          }
          param_3 = (float *)((int)param_3 + 1);
          param_2 = param_2 + 0x34;
        } while ((int)param_3 <= *(int *)(iVar3 + 0x15c));
        bVar1 = true;
      }
LAB_001ef6e4:
      if (bVar1) {
        *(undefined4 *)(param_1 + 0x558) = *(undefined4 *)(param_1 + 0x44);
      }
    }
    iVar3 = *(int *)(param_1 + 0x558);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x558);
  }
  iVar5 = iVar3 + 0x25;
  if (0 < iVar3) {
    if (*(char *)(param_1 + 0x5a3) == '\0') {
      if (*(char *)(param_1 + 0x596) == '\0') {
        if (*(char *)(param_1 + 0x5a4) == '\0') {
          iVar4 = *(int *)(param_1 + 0x44);
          if (iVar4 == iVar3 + 0x1e) {
            param_2 = (char *)0x5;
            FUN_00063b20(0x477fff00,DAT_00331b84,5);
          }
          if (iVar4 == iVar5) {
            FUN_001f4bbc(param_1);
            FUN_001e075c(*(int *)(param_1 + 0x510),param_2,param_3,param_4,param_5,param_6,param_7,
                         param_8);
            *(undefined1 *)(*(int *)(param_1 + 0x584) + 0x98) = 1;
            FUN_001fb928(param_1 + 0x3c,4,1);
            FUN_00216de0(*(undefined1 **)(param_1 + 0x560));
            FUN_001ff668();
          }
        }
        else if (iVar5 == *(int *)(param_1 + 0x44)) {
          FUN_001f4bbc(param_1);
          FUN_001fb928(param_1 + 0x3c,0xf,1);
        }
      }
      else if (iVar5 == *(int *)(param_1 + 0x44)) {
        FUN_001f4bbc(param_1);
        FUN_001fb928(param_1 + 0x3c,0x10,1);
      }
    }
    else if (iVar5 == *(int *)(param_1 + 0x44)) {
      FUN_001f4bbc(param_1);
      FUN_001fb928(param_1 + 0x3c,0xe,1);
    }
  }
  return;
}
// near miss from lane fm11 (unreviewed)
