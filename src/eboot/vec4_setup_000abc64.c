/* HSTMATCH module=EBOOT.BIN start=0x000abc64 end=0x000abdcc symbol=FUN_000abc64 lang=c99 */
/* Clone of src/sharing_main/vec4_setup_000ae658.c (hstclone.py tag s10170049c1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: the local result vector is a struct of four named floats (v.w = 1.0f assigned last) instead of float[4], the 2.0574f factor sits in a non-const local k, and the two 6.4008-scaled globals are named locals a, b (acc4 first); exact match verified; names and types await human review. */
/* Same code as EBOOT 0xabc64 (wip/vec4_setup_000abc64.c, 22 words off there). Matching idioms: `float k = 2.0574f;` (a literal factor beside fVar1 otherwise swaps the add operands), locals a/b in that order (they fix the DAT load order and the sub/add operand order), v.w assigned after v.z. Names provisional. */
typedef struct { float x, y, z, w; } Vec4;
extern float DAT_002d46b8;
extern float DAT_002d46bc;
extern float DAT_002d46c0;
extern int DAT_003386b0;
extern void FUN_00022450(Vec4 *param_1, Vec4 *param_2, int param_3);
extern void FUN_000adb10(int param_1, float *param_2, float *param_3, int param_4);

void FUN_000abc64(float *param_1, int param_2, int param_3, float *param_4,
                  float *param_5)
{
  float fVar1;
  Vec4 v;
  if (*(float *)(param_2 + 0x580) > 0.0f) {
    fVar1 = -1.0f;
  }
  else {
    fVar1 = 1.0f;
  }
  *param_4 = 0.0f;
  *param_5 = 0.0f;
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x140);
  }
  FUN_000adb10(param_2, param_4, param_5, param_3);
  float k = 2.0574f;
  v.x = *param_4 * (1.3716f * DAT_002d46b8) + k * fVar1;
  v.y = -*(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x110);
  float a = DAT_002d46bc * 6.4007998f;
  float b = DAT_002d46c0 * 6.4007998f;
  v.z = *param_5 * (0.5f * (b - a)) + 0.5f * (a + b);
  v.w = 1.0f;
  FUN_00022450(&v, &v, param_2 + 0x5a0);
  param_1[0] = v.x;
  param_1[1] = v.y;
  param_1[2] = v.z;
  param_1[3] = v.w;
}
