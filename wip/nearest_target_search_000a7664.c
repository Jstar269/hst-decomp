/* HSTMATCH module=EBOOT.BIN start=0x000a7664 end=0x000a7874 symbol=FUN_000a7664 lang=c99 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern void FUN_00022450(void *, void *, int);
extern int FUN_000b3c68(int);

undefined4 FUN_000a7664(int param_1, undefined4 *param_2, int *param_3, undefined4 *param_4,
                        int param_5, int param_6, int param_7)
{
  float fVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float out[4];
  undefined4 local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;

  local_10 = param_4[0];
  local_c = param_4[1];
  fVar9 = (float)param_4[2];
  fVar3 = 3.4028235e+38f;
  local_4 = param_4[3];
  uVar8 = 0;
  uVar7 = 0;
  if (0 < param_3[1] - param_5) {
    uVar4 = param_3[1];
    local_8 = fVar9;
    while (1) {
      uVar6 = uVar7;
      if (uVar4 <= uVar7) {
        uVar6 = uVar4 - 1;
      }
      puVar5 = (undefined4 *)(*param_3 + uVar6 * 0x20);
      local_30 = *puVar5;
      local_2c = *(undefined1 *)(puVar5 + 1);
      local_28 = puVar5[2];
      local_20 = puVar5[4];
      local_1c = puVar5[5];
      local_18 = puVar5[6];
      local_14 = puVar5[7];
      FUN_00022450(out, &local_20, param_1 + 0x5a0);
      fVar1 = out[1];
      fVar10 = out[2];
      if ((param_7 == 0) ||
          (iVar2 = FUN_000b3c68(param_1),
           -(*(float *)(iVar2 + 0x3c) * 0.95f * 0.01f) <= fVar1)) {
        if (((param_6 == 0) || (fVar10 <= fVar9)) && (ABS(fVar10 - fVar9) < fVar3)) {
          uVar8 = 1;
          *param_2 = local_30;
          *(undefined1 *)(param_2 + 1) = local_2c;
          param_2[2] = local_28;
          param_2[4] = local_20;
          param_2[5] = local_1c;
          param_2[6] = local_18;
          param_2[7] = local_14;
          fVar3 = ABS(fVar10 - fVar9);
        }
        iVar2 = param_3[1];
      }
      else {
        iVar2 = param_3[1];
      }
      uVar7 = uVar7 + 1;
      if (iVar2 - param_5 <= (int)uVar7) {
        break;
      }
      uVar4 = param_3[1];
    }
  }
  return uVar8;
}
// NEAR (141/132). Logic matches the pseudocode; the frame is 112 instead of 128. Retail's locals are
// 16-byte aligned blocks: out vec4 at sp+64, a 12-byte source record at sp+80..91, the input vec4 at
// sp+96, the param_4 copy at sp+112..127 (the last three words are written and never read, so they are
// a dead struct copy that MWCC still materialises). Splitting the FUN_00022450 output into a 4-float
// array instead of Ghidra's auStack_40[4]+locals was needed to get `ra` at 60 to match; `__attribute__
// ((aligned(16)))` on the vec4 blows the function up (235 words), so the alignment hint is wrong.
// near miss from lane fm8 (unreviewed)
