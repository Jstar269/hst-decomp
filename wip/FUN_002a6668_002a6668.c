/* HSTMATCH module=EBOOT.BIN start=0x002a6668 end=0x002a69e0 symbol=FUN_002a6668 lang=c99 */
typedef unsigned int undefined4;

extern char *DAT_003415a8;
extern int DAT_0030105c;
extern int DAT_00301060;
extern int DAT_00301064;
extern int DAT_00301068;
extern int DAT_00301078;
extern int DAT_0030107c;
extern int DAT_00300d44[];

extern int FUN_002af0c4();
extern int FUN_002af0cc();
extern void FUN_000ffb3c();
extern void FUN_00051490();
extern void FUN_00052154();
extern void FUN_00051b5c();
extern void FUN_0005185c();

void FUN_002a6668(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *puVar5;
  int *piVar6;
  int iVar7;
  char *iVar8;
  int local_1c[4];
  int local_c;
  int local_8;
  int local_4;

  iVar8 = DAT_003415a8 + 0x87128;
  local_4 = FUN_002af0c4(iVar8);
  local_1c[0] = DAT_0030105c;
  local_1c[1] = DAT_00301060;
  local_1c[2] = DAT_00301064;
  local_1c[3] = DAT_00301068;
  if (local_4 < 100) {
    local_c = -1;
  }
  else {
    local_c = (local_4 / 100) % 10;
  }
  if (local_4 < 10) {
    local_8 = -1;
  }
  else {
    local_8 = (local_4 / 10) % 10;
  }
  local_4 = local_4 % 10;
  if ((*(char *)(param_1 + 0x1558) == '\0') || (iVar1 = FUN_002af0cc(iVar8), 100 < iVar1)) {
    iVar7 = 0;
    iVar1 = param_1;
    do {
      FUN_000ffb3c(*(undefined4 *)(iVar1 + 0x68), 1);
      iVar7 = iVar7 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar7 < 7);
  }
  else {
    iVar7 = 0;
    piVar6 = local_1c;
    puVar5 = DAT_00300d44;
    iVar1 = param_1;
    do {
      if (*piVar6 < 0) {
      }
      else {
        FUN_000ffb3c(*(undefined4 *)(iVar1 + 0x68), 0);
        iVar4 = puVar5[5];
        iVar3 = *piVar6;
        iVar2 = *(int *)(iVar1 + 0x68);
        *(int *)(iVar2 + 0x24) = iVar4 + iVar3;
        *(int *)(iVar2 + 0x28) = iVar4 + iVar3;
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 1;
      iVar1 = iVar1 + 4;
      puVar5 = puVar5 + 3;
    } while (iVar7 < 7);
  }
  FUN_002af0cc(iVar8);
  if (*(char *)(param_1 + 0x1558) == '\0') {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x8c), 0);
  }
  else {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x8c), 1);
    FUN_00051490(*(undefined4 *)(param_1 + 0x1700), 0, 0, 0x1e0, 0x110, 0, 0);
    iVar1 = 0;
    iVar8 = (char *)(param_1 + 0x16f0);
    if (0 < *(int *)(param_1 + 0x16f0) + -1) {
      iVar8 = (char *)param_1;
      do {
        FUN_00052154((float)*(int *)(iVar8 + 0x898), (float)*(int *)(iVar8 + 0x8a8), 0x477f0000,
                     (float)*(int *)(iVar8 + 0x89c), (float)*(int *)(iVar8 + 0x8ac), 0x477f0000,
                     (float)*(int *)(iVar8 + 0x8a0), (float)*(int *)(iVar8 + 0x8b0),
                     *(undefined4 *)(param_1 + 0x1700), DAT_00301078, DAT_00301078, DAT_00301078);
        FUN_00052154((float)*(int *)(iVar8 + 0x898), (float)*(int *)(iVar8 + 0x8a8), 0x477f0000,
                     (float)*(int *)(iVar8 + 0x8a0), (float)*(int *)(iVar8 + 0x8b0), 0x477f0000,
                     (float)*(int *)(iVar8 + 0x8a4), (float)*(int *)(iVar8 + 0x8b4),
                     *(undefined4 *)(param_1 + 0x1700), DAT_00301078, DAT_00301078, DAT_00301078);
        FUN_00051b5c((float)*(int *)(iVar8 + 0x898), (float)*(int *)(iVar8 + 0x8a8), 0x477f0000,
                     (float)*(int *)(iVar8 + 0x8a4), (float)*(int *)(iVar8 + 0x8b4), 0x477f0000,
                     *(undefined4 *)(param_1 + 0x1700), DAT_0030107c, DAT_0030107c);
        iVar1 = iVar1 + 1;
        iVar8 = iVar8 + 0x20;
      } while (iVar1 < *(int *)(param_1 + 0x16f0) + -1);
    }
    FUN_0005185c(*(undefined4 *)(param_1 + 0x1700));
  }
  return;
}
// near miss from lane fm10 (unreviewed)
