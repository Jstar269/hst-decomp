/* HSTMATCH module=EBOOT.BIN start=0x000d61fc end=0x000d6450 symbol=FUN_000d61fc lang=c99 */
// NOT MATCHED (127/149 words, 147 differ, first at +0x0, measured from the generated baseline): same family as 0x0014f70c with 16-byte elements
// (four word copies per iteration, 4*4 index scaling) and the halved growth thresholds (0xfffffff guard,
// 0x5555555 then 0xaaaaaaa for the 1.5x / 2x policies). The head, the guard call FUN_000043b4, the
// conditional-pointer select between `need` and the candidate, FUN_000d7b58(&tmp, newcap, 0), the copy
// loop over param_2 elements and the two tail helpers (FUN_000d780c / FUN_000d7b58 family) all correspond
// one-to-one with the 0x0014f70c reconstruction; retail's frame is 96 bytes and its local slots must be
// rebuilt before either twin can be finished.
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

extern void FUN_000043b4();
extern int * FUN_000d780c();
extern void FUN_000d7b58();

void FUN_000d61fc(int *param_1,int param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int local_4;
  int *local_8;
  int local_c;
  int local_10;
  int local_14;
  uint local_28 [5];
  uint local_2c;
  uint local_30;
  
  local_8 = param_1 + 2;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_4 = 0;
  local_28[0] = (param_1[1] + param_2) - param_1[2];
  uVar9 = param_1[2];
  if (0xfffffff - uVar9 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar9 < 0x5555555) {
    local_2c = ((uVar9 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_2c;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else if (uVar9 < 0xaaaaaaa) {
    local_30 = uVar9 + 1 >> 1;
    if (local_30 < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_30;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else {
    iVar7 = 0xfffffff;
  }
  FUN_000d7b58(&local_14,iVar7,0);
  local_4 = param_1[1];
  puVar3 = (undefined4 *)(local_14 + local_4 * 0x10 + local_10 * 0x10);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *param_3;
      puVar3[1] = param_3[1];
      puVar3[2] = param_3[2];
      puVar3[3] = param_3[3];
    }
    puVar3 = puVar3 + 4;
    local_10 = local_10 + 1;
  }
  puVar8 = (undefined4 *)*param_1;
  puVar3 = puVar8 + param_1[1] * 4;
  puVar1 = (undefined4 *)(local_14 + local_4 * 0x10);
  iVar7 = local_10;
  while (puVar8 < puVar3) {
    puVar6 = puVar1 + -4;
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = puVar3[-4];
      puVar1[-3] = puVar3[-3];
      puVar1[-2] = puVar3[-2];
      puVar1[-1] = puVar3[-1];
    }
    local_4 = local_4 + -1;
    iVar7 = iVar7 + 1;
    puVar3 = puVar3 + -4;
    puVar1 = puVar6;
  }
  iVar4 = param_1[2];
  param_1[2] = local_c;
  iVar5 = *param_1;
  *param_1 = local_14;
  local_10 = param_1[1];
  param_1[1] = iVar7;
  local_14 = iVar5;
  local_c = iVar4;
  FUN_000d780c(&local_14,0xffffffff);
  return;
}
// near miss from lane ds1 (unreviewed)
