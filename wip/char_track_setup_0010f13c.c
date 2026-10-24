/* HSTMATCH module=EBOOT.BIN start=0x0010f13c end=0x0010f38c symbol=FUN_0010f13c lang=c99 */

typedef struct { float x, y, z, w; } V4;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_00102490(int, int);
extern void FUN_00042ff4(float, int);
extern void FUN_00043150(int, void *);
extern void FUN_00043580(int, int, int, int);
extern void FUN_00197464(int, void *);
extern void FUN_00197458(float, float, int);
extern void FUN_00198228(int, int, int);
extern int DAT_00310fc4;
extern int DAT_0034176c;
extern int DAT_003417a4;

void FUN_0010f13c(int param_1)
{  V4 slot0;

  undefined2 uVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;

  if ((*(unsigned short *)(**(int **)(param_1 + 0x10) + 0xe) & 3) == 0) {
    FUN_00102490(param_1, 1);
    if (DAT_003417a4 < 9) {
      fVar2 = 1.15f;
    }
    else {
      fVar2 = 0.85f;
    }
    *(float *)(param_1 + 0xdc) = *(float *)(param_1 + 0x80) * fVar2;
    *(float *)(param_1 + 0xe0) = *(float *)(param_1 + 0x94) * fVar2;
    if (*(unsigned char *)(param_1 + 0x90a) == '\0') {
      *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xb0);
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0xb4);
    }
    else {
      *(float *)(param_1 + 0xd0) =
           *(float *)(param_1 + 0xb0) -
           *(float *)(param_1 + 0xdc) * *(float *)(param_1 + 0x900) * 0.5f;
      *(float *)(param_1 + 0xd4) =
           *(float *)(param_1 + 0xb4) -
           *(float *)(param_1 + 0xe0) * *(float *)(param_1 + 0x904) * 0.5f;
    }
    *(undefined2 *)(param_1 + 0xd8) = *(undefined2 *)(param_1 + 0x908);
    iVar3 = (int)*(short *)(param_1 + 0x8fc);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
    }
    *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) - (float)(iVar3 >> 1);
    if (DAT_003417a4 < 9) {
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    *(undefined4 *)(param_1 + 0xe8) = 0;
    local_1 = (undefined1)(int)(*(float *)(param_1 + 0x7c) * 128.0f);
    local_4 = 0;
    local_3 = 0;
    local_2 = 0;
    slot0.w = *(float *)(param_1 + 0x7c);
    slot0.x = 0;
    slot0.y = 0;
    slot0.z = 0;
    FUN_00042ff4(100000.0f, DAT_00310fc4);
    if (*(unsigned char *)(param_1 + 0x90a) == '\0') {
      FUN_00043150(DAT_00310fc4, &local_4);
      FUN_00043580(DAT_00310fc4, *(undefined4 *)(param_1 + 0xf8), param_1 + 0xd0, 1);
    }
    else {
      FUN_00197464(DAT_0034176c, &slot0);
      iVar3 = DAT_0034176c;
      uVar1 = *(undefined2 *)(param_1 + 0xd8);
      uVar4 = *(undefined4 *)(param_1 + 0xd4);
      *(undefined4 *)(DAT_0034176c + 0x40) = *(undefined4 *)(param_1 + 0xd0);
      *(undefined4 *)(iVar3 + 0x44) = uVar4;
      *(undefined2 *)(iVar3 + 0x50) = uVar1;
      FUN_00197458(*(float *)(param_1 + 0xdc), *(float *)(param_1 + 0xe0), DAT_0034176c);
      iVar3 = DAT_0034176c;
      uVar4 = *(undefined4 *)(param_1 + 0xe8);
      *(undefined4 *)(DAT_0034176c + 0x70) = *(undefined4 *)(param_1 + 0xe4);
      *(undefined4 *)(iVar3 + 0x74) = uVar4;
      FUN_00198228(DAT_0034176c, *(undefined4 *)(param_1 + 0xf8), 1);
    }
  }
  return;
}
// NEAR (121/148). Logic matches the pseudocode 1:1 but the frame is 32 bytes instead of 48, so every
// sp-relative access is shifted and the comparison is dominated by that. Retail places the 16-byte
// temp (slot0.x..slot0.w) at sp+16 and the 4-byte buffer at sp+44, i.e. there are an extra 12
// bytes and 16 total bytes of locals that this reconstruction does not declare (Ghidra sees only the
// fields that are touched). Note 0x90a must be `unsigned char` (retail loads it with `lbu`).
// near miss from lane fm8 (unreviewed)
/* STATUS CORRECTION 2026-10-24 (slot refactor): measured 125/148 words, 124 differ; first at +0x1c -- four contiguous address-taken locals declared as one V4 object. */
// improved by lane fm10 (unreviewed): 126 -> 124 differing words
