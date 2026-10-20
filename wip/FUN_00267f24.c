/* HSTMATCH module=EBOOT.BIN start=0x00267f24 end=0x00268454 symbol=FUN_00267f24 lang=c99 */
/*
 * WIP Status: 315/332 words (94.9% length).
 *
 * Architecture & Discoveries:
 * - Function is an avoidance / reaction update loop over a collection of 3D entities:
 *     for (int i = 0; i < self->count; i++) {
 *         Entity *e = self->items[i];
 *         ...
 *     }
 * - Vector math calls:
 *   - FUN_00022434: Vec4 subtraction `Vec4::sub(&diff, &e->pos, &camera_pos)`.
 *   - FUN_000224d8: Vec4 squared magnitude `Vec4::length_sq(&diff)`.
 *   - Threshold 6.25f (2.5f^2): distance cull against camera.
 *   - Probes left/right offset positions (pos.x - 0.5f vs pos.x + 0.5f) to determine
 *     relative orientation/facing to camera.
 *   - Updates position by +/- 0.2f depending on counter % 7.
 *   - FUN_000fb4d0: 3D positional audio trigger `Sound::play(DAT_00338c20, 2, &sound_pos)`
 *     where sound_pos = (e->pos.x, e->pos.y - 1.2f, e->pos.z, e->pos.w).
 * - Stack frame:
 *   176-byte frame (0xb0) saving ra, s2, s1, s0, $f21, $f20, with temporary Vec4
 *   structures passed by address to Vec4::sub and Sound::play.
 */

typedef unsigned int uint;
typedef unsigned int undefined4;

extern undefined4 DAT_003386b0;
extern undefined4 DAT_00338c20;
extern void * FUN_00022434();
extern float FUN_000224d8();
extern void FUN_000fb4d0();

void FUN_00267f24(int param_1)
{
  int iVar1;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  float local_24;
  float local_28;
  float local_2c;
  float local_30;
  float local_34;
  float local_38;
  float local_3c;
  float local_40;
  undefined4 local_44;
  undefined4 local_48;
  float local_4c;
  undefined4 local_50;
  undefined4 local_54;
  undefined4 local_58;
  float local_5c;
  undefined4 local_60;
  undefined4 local_64;
  undefined4 local_68;
  undefined4 local_6c;
  undefined4 local_70;
  undefined4 local_74;
  undefined4 local_78;
  undefined4 local_7c;
  undefined4 local_80;
  undefined4 local_84;
  undefined4 local_88;
  undefined4 local_8c;
  undefined4 local_90;

  uVar5 = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    do {
      iVar4 = uVar5 * 4;
      iVar1 = *(int *)(DAT_003386b0 + 0x88);
      local_10 = *(undefined4 *)(iVar1 + 0x2f0);
      local_8 = *(undefined4 *)(iVar1 + 0x2f8);
      local_4 = *(undefined4 *)(iVar1 + 0x2fc);
      local_c = 0;
      FUN_00022434(&local_70,*(undefined4 *)(*(int *)(param_1 + 0x50) + iVar4),&local_10);
      local_18 = local_68;
      local_20 = local_70;
      local_1c = local_6c;
      local_14 = local_64;
      fVar6 = (float)FUN_000224d8(&local_20,&local_20);
      if (fVar6 < 6.25f) {
        pfVar3 = *(float **)(*(int *)(param_1 + 0x50) + iVar4);
        if ((int)pfVar3[8] < 7) {
          local_3c = pfVar3[1];
          local_30 = *pfVar3 - 0.5f;
          local_38 = pfVar3[2];
          local_40 = *pfVar3 + 0.5f;
          local_34 = pfVar3[3];
          local_2c = local_3c;
          local_28 = local_38;
          local_24 = local_34;
          FUN_00022434(&local_80,&local_30,&local_10);
          local_18 = local_78;
          local_20 = local_80;
          local_1c = local_7c;
          local_14 = local_74;
          fVar7 = (float)FUN_000224d8(&local_20,&local_20);
          FUN_00022434(&local_90,&local_40,&local_10);
          local_18 = local_88;
          local_20 = local_90;
          local_1c = local_8c;
          local_14 = local_84;
          fVar8 = (float)FUN_000224d8(&local_20,&local_20);
          if (fVar7 < fVar8) {
            iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar4);
            iVar9 = *(int *)(iVar1 + 0x20) % 7;
            if ((iVar9 != 0) || (fVar6 <= 0.25f)) {
              if ((iVar9 != 1) || (fVar6 <= 0.25f)) {
                if ((iVar9 != 2) || (fVar6 <= 0.25f)) {
                  if ((2 < iVar9) || (fVar6 < 0.25f)) {
                    *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 0.2f;
                  }
                }
                else {
                  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - 0.2f;
                }
              }
              else {
                *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 0.2f;
              }
LAB_00268258:
              iVar1 = *(int *)(param_1 + 0x50);
            }
            else {
              *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - 0.2f;
              iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar4);
              local_50 = *(undefined4 *)(iVar1 + 0x10);
              local_4c = *(float *)(iVar1 + 0x14) - 1.2f;
              local_48 = *(undefined4 *)(iVar1 + 0x18);
              local_44 = *(undefined4 *)(iVar1 + 0x1c);
              if (*(char *)(param_1 + 0x4c) != '\0') {
                if (*(char *)(param_1 + 100) == '\0') {
                  FUN_000fb4d0(DAT_00338c20,2,&local_50);
                }
                goto LAB_00268258;
              }
              iVar1 = *(int *)(param_1 + 0x50);
            }
            *(int *)(*(int *)(iVar1 + iVar4) + 0x20) = *(int *)(*(int *)(iVar1 + iVar4) + 0x20) + 1;
          }
          else {
            iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar4);
            if (*(int *)(iVar1 + 0x20) % 7 == 0) {
              if (0.25f < fVar6) {
                *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 0.2f;
                iVar1 = *(int *)(*(int *)(param_1 + 0x50) + iVar4);
                local_60 = *(undefined4 *)(iVar1 + 0x10);
                local_5c = *(float *)(iVar1 + 0x14) - 1.2f;
                local_58 = *(undefined4 *)(iVar1 + 0x18);
                local_54 = *(undefined4 *)(iVar1 + 0x1c);
                if ((*(char *)(param_1 + 0x4c) != '\0') && (*(char *)(param_1 + 100) == '\0')) {
                  FUN_000fb4d0(DAT_00338c20,2,&local_60);
                }
                goto LAB_002683dc;
              }
            }
            else {
              if (*(int *)(iVar1 + 0x20) % 7 == 1) {
                *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - 0.2f;
              }
              else if (*(int *)(iVar1 + 0x20) % 7 == 2) {
                if (0.25f < fVar6) {
                  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 0.2f;
                }
              }
              else {
                *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - 0.2f;
              }
LAB_002683dc:
              iVar1 = *(int *)(param_1 + 0x50);
            }
            *(int *)(*(int *)(iVar1 + iVar4) + 0x20) = *(int *)(*(int *)(iVar1 + iVar4) + 0x20) + 1;
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_1 + 0x54));
  }
  return;
}
// near miss from lane s10171846g1r1-0 (unreviewed)
