/* HSTMATCH module=EBOOT.BIN start=0x001a0d78 end=0x001a1068 symbol=FUN_001a0d78 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char undefined1;
typedef unsigned char bool;
typedef unsigned int uint;

extern undefined4 DAT_0034a7ec;

extern uint FUN_0027edb4();
extern void FUN_001a63ec();
extern int FUN_0027edbc();
extern unsigned char *FUN_0016b4c0();
extern int FUN_00000bcc();
extern void FUN_001a63a8();
extern void FUN_0001cfa4();
extern void FUN_001a64e8();

void FUN_001a0d78(int *param_1, int param_2, int param_3, int param_4, int param_5)
{
  short sVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  unsigned char *pbVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 local_2014;
  int local_2010;
  uint local_200c;
  uint local_2008;
  int *local_2004;
  uint local_2000[2048];

  uVar3 = FUN_0027edb4(DAT_0034a7ec);
  if ((uint)param_1[2] < uVar3) {
    FUN_001a63ec(param_1, uVar3);
  }
  iVar4 = 0;
  if ((int)uVar3 < 1) {
    iVar4 = param_1[1];
  }
  else {
    do {
      iVar6 = FUN_0027edbc(DAT_0034a7ec, iVar4);
      if (iVar6 != 0) {
        bVar2 = 0;
        if (param_5 == 0) {
          pbVar5 = FUN_0016b4c0(iVar4);
          if (*(unsigned char *)((char *)pbVar5 - 4) < 2) {
            bVar2 = 1;
          }
          else if ((param_2 == 0) || (*(char *)(param_3 + iVar6 + 0x12) != '\x02')) {
            if ((param_4 != 0) && (param_4 == iVar4)) {
              bVar2 = 1;
            }
          }
          else {
            bVar2 = 1;
          }
        }
        else {
          bVar2 = 1;
        }
        if (bVar2) {
          local_2004 = (int *)FUN_00000bcc(0xc);
          if (local_2004 != (int *)0x0) {
            local_2004[1] = 0;
            *local_2004 = 0;
            local_2004[2] = 0;
          }
          sVar1 = *(short *)(iVar6 + 8);
          *local_2004 = iVar4;
          local_2004[1] = (int)sVar1;
          local_2004[2] = 0;
          if ((uint)param_1[1] < (uint)param_1[2]) {
            iVar6 = param_1[1] + 1;
            param_1[1] = iVar6;
            *(int **)(*param_1 + iVar6 * 4 + -4) = local_2004;
          }
          else {
            FUN_001a63a8(param_1, &local_2004, 0);
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar3);
    iVar4 = param_1[1];
  }
  uVar8 = 0;
  if (iVar4 != 0) {
    puVar7 = local_2000;
    do {
      *puVar7 = *(uint *)(*(int *)(*param_1 + uVar8 * 4) + 4);
      puVar7[1] = uVar8;
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 2;
    } while (uVar8 < (uint)param_1[1]);
  }
  FUN_0001cfa4(local_2000, 0, param_1[1] + -1);
  local_2010 = 0;
  local_200c = 0;
  local_2008 = 0;
  if (uVar3 != 0) {
    FUN_001a63ec(&local_2010, uVar3);
  }
  uVar3 = 0;
  if (param_1[1] != 0) {
    puVar7 = local_2000;
    do {
      local_2014 = *(undefined4 *)(*param_1 + puVar7[1] * 4);
      if (local_200c < local_2008) {
        local_200c = local_200c + 1;
        *(undefined4 *)(local_2010 + local_200c * 4 + -4) = local_2014;
      }
      else {
        FUN_001a63a8(&local_2010, &local_2014, 0);
      }
      uVar3 = uVar3 + 1;
      puVar7 = puVar7 + 2;
    } while (uVar3 < (uint)param_1[1]);
  }
  iVar4 = param_1[2];
  param_1[2] = local_2008;
  iVar6 = *param_1;
  *param_1 = local_2010;
  param_1[1] = local_200c;
  local_200c = 0;
  local_2010 = iVar6;
  local_2008 = iVar4;
  FUN_001a64e8(&local_2010, 0);
  return;
}
// near miss from lane fm10 (unreviewed)
