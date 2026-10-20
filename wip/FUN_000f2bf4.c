/* HSTMATCH module=EBOOT.BIN start=0x000f2bf4 end=0x000f31e0 symbol=FUN_000f2bf4 lang=c99 */
/*
 * WIP Status: 567/379 words.
 *
 * Architecture & Discoveries:
 * - Function is the 2D screen indicator / off-screen target HUD marker update for a player/ball:
 *   1) Retrieves 3D entity position from model hierarchy (FUN_000938b8).
 *   2) Applies Camera View-Projection transform (FUN_00050824, FUN_00022548).
 *   3) Perspective division by W: `FUN_00022498(1.0f / w, &screen_pos, &screen_pos)`.
 *   4) Screen coordinate mapping & offset against 480x272 PSP screen boundaries:
 *      Uses 480.0f screen width boundary and DAT_002d7a74 margin.
 *   5) Off-screen arrow clamping logic: clamps indicator position to the perimeter
 *      of the screen when the target is out of the camera frustum.
 *   6) Renders indicator using FUN_000ee088 (billboard / 2D HUD quad draw with 8 float
 *      coordinates and UV parameters).
 * - Code expansion cause:
 *   Ghidra expanded vector/scalar boundary clamp macros into deep nested `if/else`
 *   ladders, blowing up code size to 567 words vs 379 retail words.
 */

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

extern undefined4 DAT_002d7a40;
extern undefined4 DAT_002d7a44;
extern undefined4 DAT_002d7a48;
extern undefined4 DAT_002d7a4c;
extern undefined4 DAT_002d7a50;
extern undefined4 DAT_002d7a54;
extern undefined4 DAT_002d7a58;
extern undefined4 DAT_002d7a5c;
extern undefined4 DAT_002d7a60;
extern undefined4 DAT_002d7a64;
extern undefined4 DAT_002d7a68;
extern undefined4 DAT_002d7a6c;
extern undefined4 DAT_002d7a70;
extern float DAT_002d7a74;
extern float DAT_002d7a78;
extern undefined4 DAT_002d7a7c;
extern undefined DAT_0032b1d0;
extern undefined4 DAT_003313c4;
extern undefined4 DAT_003386b0;
extern undefined DAT_003386b8;
extern undefined * DAT_00338ac4;
extern undefined DAT_00338c00;
extern float DAT_00338c10;
extern float DAT_00338c14;
extern undefined4 DAT_00338c18;
extern undefined4 DAT_00338c1c;
extern undefined * DAT_00340284;
extern undefined4 * FUN_00022498(float, int, int);
extern undefined4 * FUN_00022548();
extern void FUN_00050824();
extern void FUN_000938b8();
extern void FUN_000ee088(float param_1,float param_2,float param_3,float param_4,float param_5, float param_6,float param_7,float param_8,int param_9,int param_10);

void FUN_000f2bf4(char *param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_10 [4];
  float local_14;
  undefined4 local_18;
  float local_1c;
  float local_20;
  undefined4 local_28;
  float local_2c;
  float local_30;
  undefined4 auStack_60 [12];

  if ((*(char *)(*(int *)(DAT_00340284 + 0x80) + 0x78) == '\0') && (*param_1 == '\0')) {
    if (DAT_003386b8 == '\0') {
      iVar1 = 0;
    }
    else if (DAT_00338ac4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(DAT_00338ac4 + 0x198);
    }
    local_10[0] = DAT_002d7a40;
    local_10[1] = (float)DAT_002d7a44;
    local_10[2] = (float)DAT_002d7a48;
    local_10[3] = (float)DAT_002d7a4c;
    fVar3 = local_10[iVar1];
    iVar1 = *(int *)(*(int *)((int)fVar3 * 4 + DAT_003386b0 + 0x70) + 0x5bc);
    FUN_000938b8(auStack_60,iVar1,*(int *)(iVar1 + 4));
    local_14 = 1.0f;
    local_20 = local_30;
    local_1c = local_2c;
    local_18 = local_28;
    FUN_00050824(0x311170,DAT_003313c4);
    FUN_00022548(&local_20,(undefined1 (*) [64])&DAT_0032b1d0,(undefined1 (*) [16])&local_20);
    if (0.0f < local_14) {
      FUN_00022498((float)(1.0f / local_14),(int)(&local_20),(int)((undefined1 (*) [16])&local_20));
      if (DAT_00338c00 == '\0') {
        DAT_00338c18 = 0;
        DAT_00338c10 = -22.0f;
        DAT_00338c1c = 0;
        DAT_00338c14 = -110.0f;
        DAT_00338c00 = '\x01';
      }
      fVar4 = (local_20 - 1808.0f) + DAT_00338c10 * DAT_002d7a50;
      fVar2 = (local_1c - 1912.0f) + DAT_00338c14 * DAT_002d7a50;
      if (param_1[1] == '\0') {
        if (((DAT_002d7a64 <= fVar4) && (fVar4 <= DAT_002d7a68)) &&
           ((DAT_002d7a6c <= fVar2 && (fVar2 <= DAT_002d7a70)))) {
          param_1[1] = '\x01';
        }
      }
      else if (DAT_002d7a54 <= fVar4) {
        if (((DAT_002d7a58 < fVar4) || (fVar2 < DAT_002d7a5c)) || (DAT_002d7a60 < fVar2)) {
          param_1[1] = '\0';
        }
      }
      else {
        param_1[1] = '\0';
      }
      if (param_1[1] == '\0') {
        local_20 = fVar4;
        if (fVar2 < DAT_002d7a5c) {
          if ((fVar4 < DAT_002d7a74) || (480.0f - DAT_002d7a74 < fVar4)) {
            if (fVar4 < DAT_002d7a74) {
              local_20 = DAT_002d7a74;
            }
            else {
              local_20 = 480.0f - DAT_002d7a74;
              if (fVar4 <= 480.0f - DAT_002d7a74) {
                local_20 = fVar4;
              }
            }
            local_1c = DAT_002d7a74;
          }
          else {
            local_1c = DAT_002d7a74;
          }
        }
        else if (DAT_002d7a60 < fVar2) {
          if ((fVar4 < DAT_002d7a74) || (480.0f - DAT_002d7a74 < fVar4)) {
            if (fVar4 < DAT_002d7a74) {
              local_20 = DAT_002d7a74;
            }
            else {
              local_20 = 480.0f - DAT_002d7a74;
              if (fVar4 <= 480.0f - DAT_002d7a74) {
                local_20 = fVar4;
              }
            }
            local_1c = DAT_002d7a78;
          }
          else {
            local_1c = DAT_002d7a78;
          }
        }
        else if (fVar4 < DAT_002d7a54) {
          local_20 = DAT_002d7a74;
          local_1c = fVar2;
        }
        else {
          local_20 = 480.0f - DAT_002d7a74;
          local_1c = fVar2;
        }
        FUN_000ee088(local_20 - 16.0f,local_1c - 16.0f,local_20 + 16.0f,local_1c + 16.0f,0.0f,0.0f,1.0f,1.0f,*(int *)(param_1 + 4),0);
      }
    }
  }
  return;
}
// near miss from lane s10171846g1r1-0 (unreviewed)
