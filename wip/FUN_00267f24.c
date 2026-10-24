/* HSTMATCH module=EBOOT.BIN start=0x00267f24 end=0x00268454 symbol=FUN_00267f24 lang=c99 */
/*
 * STATUS CORRECTION 2026-10-24 (frame): 317/332 words, 314 differ, first diff +0x24.
 * Was 266/332, 321 differ. The 66-word gap was NOT missing code: our source declared the
 * nine address-taken Vec4 temporaries as loose floats, and mwcc slot-merges temporaries
 * whose lifetimes do not overlap, so nine 16-byte homes collapsed into three (frame 80
 * instead of retail's 176). Declaring them as nine distinct V4 objects in retail's own
 * slot order restores the frame exactly (prologue now byte-identical for 8 words).
 * Retail slot <- object (ascending): 32<-p0, 48<-p1, 64<-p2, 80<-p3, 96<-p4,
 * 112<-p5, 128<-p6, 144<-p7, 160<-p8(camera, .y zeroed). p0/p1 are the probe-sub outputs,
 * p2 the distance-sub output, p3/p4 the two sound positions, p5/p6 the probe inputs,
 * p7 the length_sq operand, p8 the camera copy.
 * DISPROVED: one float v[9][4] array also gives frame 176 but overshoots to 407/332,
 * because array subscripts force every component through memory instead of registers.
 * Remaining 15 words are downstream of the loop tail.
 */
/*
 * STATUS CORRECTION 2026-10-24: measured 266/332 words, 321 differ (was 254/332; the 315/332 below was never re-measured).
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

typedef struct { float x, y, z, w; } V4;

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
  V4 p0, p1, p2, p3, p4, p5, p6, p7, p8;

  uVar5 = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    do {
      iVar4 = uVar5 * 4;
      iVar1 = *(int *)(DAT_003386b0 + 0x88);
      p8.x = *(float *)(iVar1 + 0x2f0);
      p8.z = *(float *)(iVar1 + 0x2f8);
      p8.w = *(float *)(iVar1 + 0x2fc);
      p8.y = 0;
      FUN_00022434(&p2,*(undefined4 *)(*(int *)(param_1 + 0x50) + iVar4),&p8);
      p7.z = p2.z;
      p7.x = p2.x;
      p7.y = p2.y;
      p7.w = p2.w;
      fVar6 = (float)FUN_000224d8(&p7,&p7);
      if (fVar6 < 6.25f) {
        pfVar3 = *(float **)(*(int *)(param_1 + 0x50) + iVar4);
        if ((int)pfVar3[8] < 7) {
          p6.y = pfVar3[1];
          p5.x = *pfVar3 - 0.5f;
          p6.z = pfVar3[2];
          p6.x = *pfVar3 + 0.5f;
          p6.w = pfVar3[3];
          p5.y = p6.y;
          p5.z = p6.z;
          p5.w = p6.w;
          FUN_00022434(&p0,&p5,&p8);
          p7.z = p0.z;
          p7.x = p0.x;
          p7.y = p0.y;
          p7.w = p0.w;
          fVar7 = (float)FUN_000224d8(&p7,&p7);
          FUN_00022434(&p1,&p6,&p8);
          p7.z = p1.z;
          p7.x = p1.x;
          p7.y = p1.y;
          p7.w = p1.w;
          fVar8 = (float)FUN_000224d8(&p7,&p7);
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
              p3.x = *(float *)(iVar1 + 0x10);
              p3.y = *(float *)(iVar1 + 0x14) - 1.2f;
              p3.z = *(float *)(iVar1 + 0x18);
              p3.w = *(float *)(iVar1 + 0x1c);
              if (*(char *)(param_1 + 0x4c) != '\0') {
                if (*(char *)(param_1 + 100) == '\0') {
                  FUN_000fb4d0(DAT_00338c20,2,&p3);
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
                p4.x = *(float *)(iVar1 + 0x10);
                p4.y = *(float *)(iVar1 + 0x14) - 1.2f;
                p4.z = *(float *)(iVar1 + 0x18);
                p4.w = *(float *)(iVar1 + 0x1c);
                if ((*(char *)(param_1 + 0x4c) != '\0') && (*(char *)(param_1 + 100) == '\0')) {
                  FUN_000fb4d0(DAT_00338c20,2,&p4);
                }
                goto LAB_002683dc;
              }
            }
            else {
              if (*(int *)(iVar1 + 0x20) % 7 == 1) {
                if (0.25f < fVar6) {
                  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) - 0.2f;
                }
              }
              else if (*(int *)(iVar1 + 0x20) % 7 == 2) {
                if (0.25f < fVar6) {
                  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + 0.2f;
                }
              }
              else if (fVar6 < 0.25f) {
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
// improved by lane fm10 (unreviewed): 321 -> 314 differing words
