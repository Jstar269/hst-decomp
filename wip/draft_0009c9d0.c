/* HSTMATCH module=EBOOT.BIN start=0x0009c9d0 end=0x0009cdf0 symbol=FUN_0009c9d0 lang=c99 */
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

extern undefined4 DAT_002bc410;
extern undefined4 DAT_002bc414;
extern undefined4 DAT_002bc418;
extern undefined4 DAT_002bc41c;
extern undefined4 DAT_002bc420;
extern undefined4 DAT_002bc424;
extern undefined4 DAT_002bc428;
extern undefined4 DAT_002bc42c;
extern undefined4 DAT_002bc430;
extern undefined4 DAT_002bc434;
extern undefined4 DAT_002bc438;
extern undefined4 DAT_002bc43c;
extern undefined4 DAT_002bc440;
extern undefined4 DAT_002bc444;
extern undefined4 DAT_002bc448;
extern undefined4 DAT_002bc44c;
extern undefined4 DAT_003386b0;
extern undefined4 DAT_00338750;
extern undefined * DAT_00338b44;
extern void FUN_00093c30();
extern void FUN_00093c7c();

void FUN_0009c9d0(char *param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *iVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  
  DAT_00338750 = DAT_00338750 & 0xf9 | 6;
  uVar5 = *(uint *)(DAT_00338b44 + 0x50);
  fVar9 = (float)*(int *)(DAT_00338b44 + 0x58);
  iVar4 = *(int *)(*(int *)(uVar5 * 4 + DAT_003386b0 + 0x70) + 0x144);
  fVar8 = (float)*(int *)(DAT_00338b44 + 0x48);
  *(bool *)(param_1 + 0x400) = uVar5 == *(uint *)(param_1 + 0x148) && param_2 == 0;
  *(undefined1 *)(param_1 + 0x408) = 0;
  *(undefined1 *)(param_1 + 0x418) = 0;
  *(undefined1 *)(param_1 + 0x419) = 0;
  *(undefined4 *)(param_1 + 0x41c) = 0;
  *(undefined4 *)(param_1 + 0x420) = 0;
  *(undefined4 *)(param_1 + 0x424) = 0;
  *(undefined1 *)(param_1 + 0x4d8) = 0;
  *(undefined1 *)(param_1 + 0x4d9) = 0;
  *(undefined1 *)(param_1 + 0x4e0) = 0;
  *(undefined4 *)(param_1 + 0x45c) = 0;
  *(undefined1 *)(param_1 + 0x4cf) = 0;
  *(undefined1 *)(param_1 + 0x4d0) = 0;
  *(undefined1 *)(param_1 + 0x4d1) = 0;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  *(undefined4 *)(param_1 + 0x4ec) = 0x3c;
  uVar7 = 0;
  iVar6 = param_1;
  while( true ) {
    *(undefined1 *)(iVar6 + 0x5b0) = 0;
    uVar7 = uVar7 + 1;
    if (1 < uVar7) break;
    iVar6 = param_1 + uVar7;
  }
  *(undefined4 *)(param_1 + 0x5b4) = 0xd0;
  *(undefined1 *)(param_1 + 0x5b9) = 0xff;
  *(undefined1 *)(param_1 + 0x4da) = 0;
  *(undefined4 *)(param_1 + 0x4dc) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x480) = 0;
  *(undefined1 *)(param_1 + 0x4cc) = 0;
  *(undefined1 *)(param_1 + 0x4cd) = 0;
  uVar7 = *(int *)(param_1 + 0x168) * 0x343fd + 0x269ec3;
  *(uint *)(param_1 + 0x168) = uVar7;
  *(int *)(param_1 + 0x4f0) = (int)((float)((uVar7 >> 0x10) & 0x7fff) * 3.0517578e-05f * 30.0f);
  if (*(int *)(param_1 + 0x144) == 0) {
    *(float *)(param_1 + 0x5a0) = fVar8;
    *(undefined4 *)(param_1 + 0x5a4) = 0x3f800000;
    *(float *)(param_1 + 0x5a8) = fVar8;
    *(undefined4 *)(param_1 + 0x5ac) = 0x3f800000;
  }
  else {
    *(float *)(param_1 + 0x5a0) = -fVar8;
    *(undefined4 *)(param_1 + 0x5a4) = 0x3f800000;
    *(float *)(param_1 + 0x5a8) = -fVar8;
    *(undefined4 *)(param_1 + 0x5ac) = 0x3f800000;
  }
  uVar3 = DAT_002bc41c;
  uVar2 = DAT_002bc418;
  uVar1 = DAT_002bc414;
  fVar8 = 1.0f;
  *(undefined4 *)(param_1 + 0x550) = DAT_002bc410;
  *(undefined4 *)(param_1 + 0x554) = uVar1;
  *(undefined4 *)(param_1 + 0x558) = uVar2;
  *(undefined4 *)(param_1 + 0x55c) = uVar3;
  uVar3 = DAT_002bc42c;
  uVar2 = DAT_002bc428;
  uVar1 = DAT_002bc424;
  *(undefined4 *)(param_1 + 0x560) = DAT_002bc420;
  *(undefined4 *)(param_1 + 0x564) = uVar1;
  *(undefined4 *)(param_1 + 0x568) = uVar2;
  *(undefined4 *)(param_1 + 0x56c) = uVar3;
  uVar3 = DAT_002bc43c;
  uVar2 = DAT_002bc438;
  uVar1 = DAT_002bc434;
  *(undefined4 *)(param_1 + 0x570) = DAT_002bc430;
  *(undefined4 *)(param_1 + 0x574) = uVar1;
  *(undefined4 *)(param_1 + 0x578) = uVar2;
  *(undefined4 *)(param_1 + 0x57c) = uVar3;
  uVar3 = DAT_002bc44c;
  uVar2 = DAT_002bc448;
  uVar1 = DAT_002bc444;
  *(undefined4 *)(param_1 + 0x580) = DAT_002bc440;
  *(undefined4 *)(param_1 + 0x584) = uVar1;
  *(undefined4 *)(param_1 + 0x588) = uVar2;
  *(undefined4 *)(param_1 + 0x58c) = uVar3;
  if (iVar4 == *(int *)(param_1 + 0x144)) {
    uVar7 = *(uint *)(param_1 + 0x148);
  }
  else {
    if (param_2 == 0) {
      if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
        if ((*(uint *)(param_1 + 0x148) & 2) == 0) {
          fVar9 = fVar9 * 1.0f;
        }
        else {
          fVar8 = -1.0f;
          fVar9 = fVar9 * -1.0f;
        }
        if (0.0f < fVar9) {
          *(float *)(param_1 + 0x580) = fVar8 * 3.7033198f;
          *(undefined4 *)(param_1 + 0x588) = 0xc144985e;
        }
        else {
          *(float *)(param_1 + 0x580) = fVar8 * 1.4f;
          *(undefined4 *)(param_1 + 0x588) = 0xc099999a;
        }
        *(bool *)(param_1 + 0x408) = 0.0f < fVar9;
      }
      else {
        *(float *)(param_1 + 0x580) = fVar9 * 3.7033198f;
        *(undefined4 *)(param_1 + 0x588) = 0xc144985e;
        *(undefined1 *)(param_1 + 0x408) = 1;
      }
      goto LAB_0009cd88;
    }
    uVar7 = *(uint *)(param_1 + 0x148);
  }
  if (uVar5 == uVar7) {
    fVar8 = *(float *)(param_1 + 0x404);
  }
  else {
    if ((param_2 == 0) || ((uVar7 & 2) != (uVar5 & 2))) {
      *(float *)(param_1 + 0x580) = -fVar9 * 2.88036f;
      *(undefined4 *)(param_1 + 0x588) = 0xc03e31f8;
      goto LAB_0009cd88;
    }
    fVar8 = *(float *)(param_1 + 0x404);
  }
  *(float *)(param_1 + 0x580) = fVar9 * fVar8;
  *(undefined4 *)(param_1 + 0x588) = 0xc144985e;
LAB_0009cd88:
  *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_1 + 0x580);
  *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(param_1 + 0x584);
  *(undefined4 *)(param_1 + 0x598) = *(undefined4 *)(param_1 + 0x588);
  *(undefined4 *)(param_1 + 0x59c) = *(undefined4 *)(param_1 + 0x58c);
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_00093c30(*(int *)(param_1 + 0x5bc),&local_10);
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_00093c7c(*(int *)(param_1 + 0x5bc),&local_20);
  return;
}
// near miss from lane fm11 (unreviewed)
