/* HSTMATCH module=EBOOT.BIN start=0x0012883c end=0x00128910 symbol=FUN_0012883c lang=c99 */
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

extern float DAT_002da3d8;
extern float DAT_002da3e4;
extern undefined4 * FUN_00022418();

void FUN_0012883c(int param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_10 [4];
  
  local_10[1] = DAT_002da3d8;
  local_10[0] = 0;
  local_10[2] = 0;
  local_10[3] = 0;
  FUN_00022418((undefined4 *)(param_1 + 0x1a0),(undefined1 (*) [16])(param_1 + 0x1a0),
               (undefined1 (*) [16])local_10);
  fVar1 = DAT_002da3e4;
  fVar3 = *(float *)(param_1 + 0x1ac);
  if (fVar3 < 0.0f) {
    fVar4 = *(float *)(param_1 + 0x1a8);
  }
  else {
    fVar3 = 0.0f;
    fVar4 = *(float *)(param_1 + 0x1a8);
  }
  fVar4 = fVar4 < 0.0f ? fVar4 : 0.0f;
  fVar2 = *(float *)(param_1 + 0x1a4);
  fVar2 = fVar2 < fVar1 ? fVar2 : fVar1;
  fVar1 = *(float *)(param_1 + 0x1a0);
  fVar1 = fVar1 < 0.0f ? fVar1 : 0.0f;
  *(float *)(param_1 + 0x1a0) = fVar1;
  *(float *)(param_1 + 0x1a4) = fVar2;
  *(float *)(param_1 + 0x1a8) = fVar4;
  *(float *)(param_1 + 0x1ac) = fVar3;
  FUN_00022418((undefined4 *)(param_1 + 0x1b0),(undefined1 (*) [16])(param_1 + 0x1b0),
               (undefined1 (*) [16])(param_1 + 0x1a0));
  return;
}
// Near miss: 0x00128898 and 0x0012889c emit lwc1 x2 before mov.s x3,zero; retail has the reverse order.
// A shared post-condition load changed bc1f polarity and increased the mismatch, so this branch form is the best checked variant.
// near miss from lane cx10 (unreviewed)
