/* HSTMATCH module=EBOOT.BIN start=0x000effa0 end=0x000f037c symbol=FUN_000effa0 lang=c99 rodata=0x002d7320 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned char bool;
typedef int code();
typedef unsigned int uint;

extern undefined4 DAT_002d73c0;
extern undefined4 DAT_002d73c4;
extern undefined4 DAT_002d7320;
extern undefined4 DAT_002d735c;
extern undefined4 DAT_002d7368;
extern undefined4 DAT_002d7374;
extern char DAT_003417bb;
extern undefined4 DAT_00338b44;
extern char DAT_002d73c8[];

extern void FUN_000f0350();
extern void FUN_001036f8();
extern int FUN_000dbc54();
extern void FUN_000ffb3c();
extern undefined4 FUN_001fecb4();
extern void FUN_0010d4a8();
extern void FUN_00022498();

extern void FUN_0000f0350(int);
extern void FUN_0001036f8(int,int);
void FUN_000effa0(int param_1)
{
  int *p0;
  int *vt;
  int s2v, s3v, s3c;
  int *s0p;
  int a0v, v1v, a2v; float f1v, f0v; char sp88[4], sp92[4];
  FUN_0000f0350(param_1);
  *(int *)(param_1 + 0x8c) = 0;
  FUN_0001036f8(param_1, 0);
  a0v = *(int *)(param_1 + 0xb8);
  v1v = *(int *)(param_1 + 0xbc);
  f1v = DAT_002d73c0;
  a2v = a0v + v1v;
  f0v = DAT_002d73c4;
  *(float *)(sp88) = f1v;
  *(float *)(sp92) = f0v;
  a0v = *(int *)(param_1 + 0xb4);
  v1v = *(int *)(param_1 + 0xc0);
  p0 = *(int **)(param_1 + 100);
  v1v = DAT_002d7320 + a2v;
  p0[9] = v1v;
  p0[10] = v1v;
  *(int *)(param_1 + 0x90) = a2v;
  vt = (int *)*(int *)(param_1 + 0x58);
  (*(void (**)(int *, int))(vt[3]))((int *)vt, (unsigned)a2v < 1);
  FUN_0000dbc54(param_1, 1);
  s2v = 1;
  s0p = (int *)sp88;
  for (s3c = 0; s3c < 2; s3c++) {
    do {
      if (FUN_0000dbc54(param_1, s2v) != 0) break;
      s2v = s2v + 1;
      s3v = s3v + 1;
      *s0p = s2v;
      if (s3v >= 2) { s0p = s0p + 1; }
      s2v = s2v + 1;
    } while (s2v < 21);
  }
  bool bVar1;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_8[2];

  FUN_000f0350();
  *(undefined4 *)(param_1 + 0x8c) = 0;
  FUN_001036f8(param_1, 0);
  local_8[0] = DAT_002d73c0;
  iVar11 = *(int *)(DAT_00338b44 + 0xb8) + *(int *)(DAT_00338b44 + 0xbc);
  local_8[1] = DAT_002d73c4;
  iVar9 = *(int *)(DAT_00338b44 + 0xb4);
  iVar7 = *(int *)(DAT_00338b44 + 0xc0);
  bVar1 = DAT_003417bb != '\0';
  iVar5 = *(int *)(param_1 + 100);
  iVar8 = DAT_002d7320 + iVar11;
  *(int *)(iVar5 + 0x24) = iVar8;
  *(int *)(iVar5 + 0x28) = iVar8;
  *(int *)(param_1 + 0x90) = iVar11;
  {
    int *piVar = *(int **)(param_1 + 0x58);
    (**(code **)(*piVar + 0xc))(piVar, iVar11 == 0);
  }
  iVar8 = 0;
  iVar5 = 1;
  piVar10 = local_8;
  do {
    iVar11 = FUN_000dbc54(DAT_00338b44, iVar5);
    if (iVar11 != 0) {
      iVar8 = iVar8 + 1;
      *piVar10 = iVar5;
      piVar10 = piVar10 + 1;
      if (1 < iVar8) break;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x15);
  if (iVar8 < 2) {
    piVar10 = local_8 + iVar8;
    do {
      *piVar10 = -1;
      piVar10[1] = -1;
      piVar10[2] = -1;
      piVar10[3] = -1;
      piVar10[4] = -1;
      piVar10[5] = -1;
      piVar10[6] = -1;
      iVar8 = iVar8 + 8;
      piVar10[7] = -1;
      piVar10 = piVar10 + 8;
    } while (iVar8 < -6);
    if (iVar8 < 2) {
      piVar10 = local_8 + iVar8;
      do {
        iVar8 = iVar8 + 1;
        *piVar10 = -1;
        piVar10 = piVar10 + 1;
      } while (iVar8 < 2);
    }
  }
  iVar8 = 0;
  piVar10 = local_8;
  iVar5 = param_1;
  do {
    if (*piVar10 < 0) {
      FUN_000ffb3c(*(undefined4 *)(iVar5 + 0x70), 1);
      iVar11 = *(int *)(iVar5 + 0x84);
      *(char **)(iVar11 + 0xf8) = DAT_002d73c8;
      *(undefined4 *)(iVar11 + 0x138) = 0;
      FUN_0010d4a8();
    }
    else {
      FUN_000ffb3c(*(undefined4 *)(iVar5 + 0x70), 0);
      uVar6 = FUN_001fecb4(*piVar10);
      iVar11 = *(int *)(iVar5 + 0x84);
      *(undefined4 *)(iVar11 + 0xf8) = uVar6;
      *(undefined4 *)(iVar11 + 0x138) = 1;
      FUN_0010d4a8();
      iVar11 = *(int *)(iVar5 + 0x84);
      *(undefined4 *)(iVar11 + 0x118) = 0x80000000;
      local_14 = 0x43000000;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      FUN_00022498(0x3c03126f, &local_30, &local_20);
      *(undefined4 *)(iVar11 + 0x120) = local_30;
      *(undefined4 *)(iVar11 + 0x124) = local_2c;
      *(undefined4 *)(iVar11 + 0x128) = local_28;
      *(undefined4 *)(iVar11 + 300) = local_24;
    }
    iVar8 = iVar8 + 1;
    piVar10 = piVar10 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar8 < 2);
  iVar5 = *(int *)(param_1 + 0x78);
  iVar8 = DAT_002d735c + iVar9 + -1;
  *(int *)(iVar5 + 0x24) = iVar8;
  *(int *)(iVar5 + 0x28) = iVar8;
  **(undefined4 **)(param_1 + 0x78) = 0x802a237f;
  iVar5 = *(int *)(param_1 + 0x7c);
  iVar7 = DAT_002d7368 + iVar7 + -1;
  *(int *)(iVar5 + 0x24) = iVar7;
  *(int *)(iVar5 + 0x28) = iVar7;
  **(undefined4 **)(param_1 + 0x7c) = 0x80004b7f;
  iVar5 = *(int *)(param_1 + 0x80);
  iVar7 = DAT_002d7374 + (uint)bVar1;
  *(int *)(iVar5 + 0x24) = iVar7;
  *(int *)(iVar5 + 0x28) = iVar7;
  return;
}
// near miss from lane fm10 (unreviewed)
