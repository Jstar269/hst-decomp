/* HSTMATCH module=EBOOT.BIN start=0x0027e0e8 end=0x0027e3dc symbol=FUN_0027e0e8 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned int uint;

extern struct BV {
  char *p;
  uint n;
  uint cap;
};

void FUN_000043b4();
extern void FUN_0027e614();
extern void FUN_0027e584();

void FUN_0027e0e8(int *param_1, int param_2, undefined1 *param_3)
{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint local_30;
  uint local_2c;
  uint local_28[5];
  struct BV v;
  struct BV *vp;
  volatile int *local_8;
 volatile int local_4;

  local_8 = param_1 + 2;
  vp = &v;
  v.p = 0;
  v.n = 0;
  v.cap = 0;
  local_4 = 0;
  local_28[0] = (param_1[1] + param_2) - param_1[2];
  uVar14 = param_1[2];
  if (0x2762762 - uVar14 < local_28[0]) {
    FUN_000043b4();
  }
  if (uVar14 < 0xd20d20) {
    local_2c = ((uVar14 + 1) * 3) / 5;
    if (local_2c < local_28[0]) {
      puVar4 = local_28;
    }
    else {
      puVar4 = &local_2c;
    }
    iVar7 = uVar14 + *puVar4;
  }
  else if (uVar14 < 0x1a41a40) {
    local_30 = (uVar14 + 1) >> 1;
    if (local_30 < local_28[0]) {
      puVar4 = local_28;
    }
    else {
      puVar4 = &local_30;
    }
    iVar7 = uVar14 + *puVar4;
  }
  else {
    iVar7 = 0x2762762;
  }
  FUN_0027e614(vp, iVar7, 0);
  local_4 = param_1[1];
  puVar11 = (undefined1 *)(vp->p + local_4 * 0x68 + vp->n * 0x68);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (puVar11 != (undefined1 *)0x0) {
      iVar7 = 0x32;
      puVar8 = puVar11;
      puVar5 = param_3;
      do {
        uVar1 = puVar5[1];
        iVar7 = iVar7 + -1;
        *puVar8 = *puVar5;
        puVar8[1] = uVar1;
        puVar5 = puVar5 + 2;
        puVar8 = puVar8 + 2;
      } while (0 < iVar7);
      uVar1 = param_3[0x65];
      uVar2 = param_3[0x66];
      uVar3 = param_3[0x67];
      puVar11[100] = param_3[100];
      puVar11[0x65] = uVar1;
      puVar11[0x66] = uVar2;
      puVar11[0x67] = uVar3;
    }
    puVar11 = puVar11 + 0x68;
    *(uint *)((char *)vp + 4) = *(uint *)((char *)vp + 4) + 1;
  }
  puVar5 = (undefined1 *)*param_1;
  puVar11 = puVar5 + param_1[1] * 0x68;
  puVar8 = (undefined1 *)(vp->p + local_4 * 0x68);
  iVar7 = vp->n;
  while (puVar5 < puVar11) {
    puVar13 = puVar8 + -0x68;
    if (puVar13 != (undefined1 *)0x0) {
      iVar9 = 0x32;
      puVar10 = puVar13;
      puVar12 = puVar11 + -0x68;
      do {
        uVar1 = puVar12[1];
        iVar9 = iVar9 + -1;
        *puVar10 = *puVar12;
        puVar10[1] = uVar1;
        puVar12 = puVar12 + 2;
        puVar10 = puVar10 + 2;
      } while (0 < iVar9);
      uVar1 = puVar11[-3];
      uVar2 = puVar11[-2];
      uVar3 = puVar11[-1];
      puVar8[-4] = puVar11[-4];
      puVar8[-3] = uVar1;
      puVar8[-2] = uVar2;
      puVar8[-1] = uVar3;
    }
    local_4 = local_4 + -1;
    iVar7 = iVar7 + 1;
    puVar11 = puVar11 + -0x68;
    puVar8 = puVar13;
  }
  iVar9 = param_1[2];
  param_1[2] = vp->cap;
  iVar6 = *param_1;
  *param_1 = (uint)vp->p;
  vp->n = param_1[1];
  param_1[1] = iVar7;
  vp->p = (char *)iVar6;
  vp->cap = (uint)iVar9;
  FUN_0027e584(vp, 0xffffffff);
  return;
}
// near miss from lane fm10 (unreviewed)
