/* HSTMATCH module=EBOOT.BIN start=0x00267bd8 end=0x00267f24 symbol=FUN_00267bd8 lang=c99 */
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
extern undefined4 DAT_002bc440;
extern undefined4 DAT_002bc444;
extern undefined4 DAT_002bc448;
extern undefined4 DAT_002bc44c;
extern undefined * DAT_003313c4;
extern undefined4 DAT_00338714;
extern undefined * DAT_00340284;
extern undefined4 * FUN_000224f8();
extern undefined4 * FUN_00022518();
extern void FUN_00055044();
extern void FUN_0005f1e8();
extern undefined1 FUN_00131cf8();

extern unsigned int DAT_002bc410;
void FUN_00267bd8(int param_1)
{
  float b48[16], b80[8], b96[4];
  char *base;
  b48[0] = *(float *)((char *)&DAT_002bc410 + 0);
  b48[1] = *(float *)((char *)&DAT_002bc410 + 4);
  b48[2] = *(float *)((char *)&DAT_002bc410 + 8);
  b48[3] = *(float *)((char *)&DAT_002bc410 + 12);
  b48[4] = *(float *)((char *)&DAT_002bc410 + 16);
  b48[5] = *(float *)((char *)&DAT_002bc410 + 20);
  b48[6] = *(float *)((char *)&DAT_002bc410 + 24);
  b48[7] = *(float *)((char *)&DAT_002bc410 + 28);
  b48[8] = *(float *)((char *)&DAT_002bc410 + 32);
  b48[9] = *(float *)((char *)&DAT_002bc410 + 36);
  b48[10] = *(float *)((char *)&DAT_002bc410 + 40);
  b48[11] = *(float *)((char *)&DAT_002bc410 + 44);
  b48[12] = *(float *)((char *)&DAT_002bc410 + 48);
  b48[13] = *(float *)((char *)&DAT_002bc410 + 52);
  b48[14] = *(float *)((char *)&DAT_002bc410 + 56);
  b48[15] = *(float *)((char *)&DAT_002bc410 + 60);
  base = (char *)*(unsigned int *)&DAT_003313c4;
  b80[0] = *(float *)(base + 496);
  b80[1] = *(float *)(base + 500);
  b80[2] = *(float *)(base + 504);
  b80[3] = *(float *)(base + 508);
  b80[4] = *(float *)(base + 480);
  b80[5] = *(float *)(base + 484);
  b80[6] = *(float *)(base + 488);
  b80[7] = *(float *)(base + 492);
  FUN_000224f8(b48, b80, b96);
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
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
  undefined4 local_44;
  undefined4 local_48;
  undefined4 local_50 [2];
  undefined4 local_54;
  undefined4 local_58;
  undefined4 local_5c;
  undefined4 local_60;
  undefined4 local_64;
  undefined4 local_68;
  undefined4 local_6c;
  undefined4 local_70;
  
  local_40 = DAT_002bc410;
  local_3c = DAT_002bc414;
  local_38 = DAT_002bc418;
  local_34 = DAT_002bc41c;
  local_10 = DAT_002bc440;
  local_c = DAT_002bc444;
  local_8 = DAT_002bc448;
  local_4 = DAT_002bc44c;
  local_30 = *(undefined4 *)(DAT_003313c4 + 0x1f0);
  local_2c = *(undefined4 *)(DAT_003313c4 + 500);
  local_28 = *(undefined4 *)(DAT_003313c4 + 0x1f8);
  local_24 = *(undefined4 *)(DAT_003313c4 + 0x1fc);
  local_20 = *(undefined4 *)(DAT_003313c4 + 0x1e0);
  local_1c = *(undefined4 *)(DAT_003313c4 + 0x1e4);
  local_18 = *(undefined4 *)(DAT_003313c4 + 0x1e8);
  local_14 = *(undefined4 *)(DAT_003313c4 + 0x1ec);
  FUN_000224f8(local_50,&local_30,&local_20);
  local_40 = local_50[0];
  local_38 = local_48;
  local_34 = local_44;
  local_2c = 0x3f800000;
  local_24 = 0x3f800000;
  local_30 = 0;
  local_28 = 0;
  local_3c = 0;
  local_1c = 0;
  FUN_00022518(&local_60,&local_40);
  local_40 = local_60;
  local_3c = local_5c;
  local_38 = local_58;
  local_54 = 0;
  local_34 = 0;
  FUN_00022518(&local_70,&local_20);
  local_64 = 0;
  local_14 = 0;
  local_20 = local_70;
  local_1c = local_6c;
  local_18 = local_68;
  if ((*(char *)(param_1 + 0x4c) != '\0') && (uVar3 = 0, *(int *)(param_1 + 0x54) != 0)) {
    iVar1 = *(int *)(param_1 + 0x50);
    while( true ) {
      iVar2 = uVar3 * 4;
      iVar1 = *(int *)(iVar1 + iVar2);
      local_10 = *(undefined4 *)(iVar1 + 0x10);
      local_c = *(undefined4 *)(iVar1 + 0x14);
      local_8 = *(undefined4 *)(iVar1 + 0x18);
      local_4 = *(undefined4 *)(iVar1 + 0x1c);
      FUN_00055044(*(undefined4 *)(iVar1 + 0x24),&local_40);
      if ((*(int *)(DAT_00340284 + 0x8c) == 0) || (iVar1 = FUN_00131cf8(), iVar1 != 0)) {
        if (*(float *)(param_1 + 0x5c) < *(float *)(DAT_003313c4 + 0x1d8)) {
          iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar2);
          if (*(float *)(param_1 + 0x5c) < *(float *)(iVar1 + 0x18)) {
            *(undefined1 *)(param_1 + 100) = 1;
          }
          else {
            FUN_0005f1e8(*(undefined4 *)(iVar1 + 0x24),DAT_00338714);
            *(undefined1 *)(param_1 + 100) = 0;
          }
        }
        else if (*(float *)(DAT_003313c4 + 0x1d8) < *(float *)(param_1 + 0x60)) {
          iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar2);
          if (*(float *)(iVar1 + 0x18) < *(float *)(param_1 + 0x60)) {
            *(undefined1 *)(param_1 + 100) = 1;
          }
          else {
            FUN_0005f1e8(*(undefined4 *)(iVar1 + 0x24),DAT_00338714);
            *(undefined1 *)(param_1 + 100) = 0;
          }
        }
        else {
          FUN_0005f1e8(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + iVar2) + 0x24),
                       DAT_00338714);
          *(undefined1 *)(param_1 + 100) = 0;
        }
      }
      else {
        FUN_0005f1e8(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x50) + iVar2) + 0x24),
                     DAT_00338714);
        *(undefined1 *)(param_1 + 100) = 0;
      }
      uVar3 = uVar3 + 1;
      if (*(uint *)(param_1 + 0x54) <= uVar3) break;
      iVar1 = *(int *)(param_1 + 0x50);
    }
  }
  return;
}

// NEAR MISS 0x00267bd8: draft 127/211 words. The missing body is a long chain of
// Vec4/Mat4 copies the draft dropped, so this needs a typed rewrite, not a
// respelling:
//   * retail's frame is 128 bytes; sp+0x40..0x4c, 0x50, 0x54, 0x58, 0x5c and
//     sp+0x20..0x2c, 0x10..0x1c hold Vec4 locals. The first two are filled by
//     lwc1/swc1 pairs from DAT_002bc410.. with a FRESH lui per field - the
//     digest's "memberwise copy from an extern const global" shape, so the
//     source is `Vec4 a = DAT_002bc410;` (a Vec4-typed extern const) etc.
//   * then FUN_000224f8(&tmp, &v1, &v2), FUN_00022518(&tmp, &v) pairs, and the
//     loop over param_1->[0x50] with 0x54 count passes &local_40 to
//     FUN_00055044 and calls FUN_0005f1e8(.., _DAT_00338714) with a float
//     compare cascade on +0x5c/+0x60 against _DAT_003313c4+0x1d8.
// Everything after the copies (the loop) is already close to the draft; the
// copies alone are ~80 instructions.
// near miss from lane fm10 (unreviewed)
