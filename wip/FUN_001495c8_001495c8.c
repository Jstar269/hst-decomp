/* HSTMATCH module=EBOOT.BIN start=0x001495c8 end=0x001498ac symbol=FUN_001495c8 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned int uint;

extern void FUN_000043b4();
extern void FUN_0014b358();
extern void FUN_0014aa34();

struct BV {
  char *p;
  uint n;
  uint cap;
};

void FUN_001495c8(uint *param_1, int param_2, undefined4 *param_3)
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint local_30;
  uint local_2c;
  uint local_28[5];
  struct BV v;
  struct BV *vp;
  volatile uint *local_8;
  volatile int local_4;

  local_8 = param_1 + 2;
  vp = &v;
  v.p = 0;
  v.n = 0;
  v.cap = 0;
  local_4 = 0;
  local_28[0] = (param_1[1] + param_2) - param_1[2];
  uVar9 = param_1[2];
  if (0x5555555 - uVar9 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar9 < 0x1c71c71) {
    local_2c = ((uVar9 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_2c;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else if (uVar9 < 0x38e38e2) {
    local_30 = (uVar9 + 1) >> 1;
    if (local_30 < local_28[0]) {
      puVar2 = local_28;
    }
    else {
      puVar2 = &local_30;
    }
    iVar7 = uVar9 + *puVar2;
  }
  else {
    iVar7 = 0x5555555;
  }
  FUN_0014b358(vp, iVar7, 0);
  local_4 = param_1[1];
  puVar3 = (undefined4 *)(vp->p + local_4 * 0x30 + vp->n * 0x30);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = *param_3;
      puVar3[1] = param_3[1];
      puVar3[2] = param_3[2];
      puVar3[3] = param_3[3];
      puVar3[4] = param_3[4];
      puVar3[5] = param_3[5];
      puVar3[6] = param_3[6];
      puVar3[7] = param_3[7];
      puVar3[8] = param_3[8];
      *(undefined1 *)(puVar3 + 9) = *(undefined1 *)(param_3 + 9);
      puVar3[10] = param_3[10];
    }
    puVar3 = puVar3 + 0xc;
    *(uint *)((char *)vp + 4) = *(uint *)((char *)vp + 4) + 1;
  }
  puVar8 = (undefined4 *)*param_1;
  puVar3 = puVar8 + param_1[1] * 0xc;
  puVar1 = (undefined4 *)(vp->p + local_4 * 0x30);
  uVar9 = vp->n;
  while (puVar8 < puVar3) {
    puVar6 = puVar1 + -0xc;
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = puVar3[-0xc];
      puVar1[-0xb] = puVar3[-0xb];
      puVar1[-10] = puVar3[-10];
      puVar1[-9] = puVar3[-9];
      puVar1[-8] = puVar3[-8];
      puVar1[-7] = puVar3[-7];
      puVar1[-6] = puVar3[-6];
      puVar1[-5] = puVar3[-5];
      puVar1[-4] = puVar3[-4];
      *(undefined1 *)(puVar1 + -3) = *(undefined1 *)(puVar3 + -3);
      puVar1[-2] = puVar3[-2];
    }
    local_4 = local_4 - 1;
    uVar9 = uVar9 + 1;
    puVar3 = puVar3 + -0xc;
    puVar1 = puVar6;
  }
  uVar4 = param_1[2];
  param_1[2] = vp->cap;
  uVar5 = *param_1;
  *param_1 = (uint)vp->p;
  vp->n = param_1[1];
  param_1[1] = uVar9;
  vp->p = (char *)uVar5;
  vp->cap = uVar4;
  FUN_0014aa34(vp, 0xffffffff);
  return;
}
// near miss from lane fm10 (unreviewed)
