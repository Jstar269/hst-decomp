/* HSTMATCH module=EBOOT.BIN start=0x002392dc end=0x002395f8 symbol=FUN_002392dc lang=c99 rodata=0x002f5314 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

extern char s_Status_002f531c[];
extern char s_menu_status_01_xb_002f5324[];
extern char s_data_menu_status_status_param_cs_002f5338[];
extern char s_data_menu_status_status_param_co_002f535c[];
extern char s_data_menu_status_status_param_sc_002f5384[];
extern char s_data_menu_status_sort_csv_002f53b4[];
extern undefined4 DAT_002f53b0;
extern undefined4 DAT_002f5314;
extern undefined4 DAT_002f5318;
extern unsigned char DAT_00341ccc[];
extern char DAT_0034179c[];

extern void FUN_00000020();
extern void FUN_0001ca58();
extern void FUN_0017ae48();
extern void FUN_0017b260();
extern void FUN_000651b8();
extern void FUN_001b3378();
extern void FUN_0001cb88();
extern void FUN_000114c0();
extern void FUN_0023b020();
extern int FUN_00193474();
extern int FUN_002acd28();
extern void FUN_00054510();
extern void FUN_001a5bcc();
extern undefined4 FUN_00065104();
extern void FUN_0023a928();
extern void FUN_0023c040();
extern void FUN_001b3ce8();
extern void FUN_00000028();

undefined4 FUN_002392dc(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  unsigned char *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  undefined1 auStack_8[8];

  FUN_00000020(s_Status_002f531c);
  FUN_0001ca58(0x30ebf4, s_menu_status_01_xb_002f5324);
  FUN_0017ae48(param_1 + 0x18b8, param_1 + 0x1858,
               s_data_menu_status_status_param_cs_002f5338, 4);
  FUN_0017b260(param_1 + 0x18bc, param_1 + 0x1888,
               s_data_menu_status_status_param_co_002f535c, 0x18);
  FUN_000651b8(param_1 + 0x18d4, s_data_menu_status_status_param_sc_002f5384, 1, 0,
               &DAT_002f53b0);
  FUN_000651b8(param_1 + 0x1904, s_data_menu_status_sort_csv_002f53b4, 0, 0,
               &DAT_002f53b0);
  if (*(char *)(param_1 + 0x4c) != '\0') {
    FUN_001b3378(0x34179c, 6);
  }
  FUN_0001cb88(0x30ebf4);
  FUN_000114c0(auStack_8, 0, 8);
  FUN_0023b020(param_1 + 0x1818, 0xf, auStack_8, 0);
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    iVar1 = FUN_00193474(iVar5);
    if (iVar5 < 0) {
      pbVar3 = (unsigned char *)0x0;
    }
    else if (iVar5 < 0xf) {
      pbVar3 = &DAT_00341ccc[iVar4 + 4];
    }
    else {
      pbVar3 = (unsigned char *)0x0;
    }
    if (*(char *)(iVar1 + 0x2c) == '\0') {
      *(unsigned char **)(*(int *)(param_1 + 0x1818) + iVar6 * 8) = pbVar3;
      *(int *)(*(int *)(param_1 + 0x1818) + iVar6 * 8 + 4) = iVar5;
LAB_00239474:
      iVar6 = iVar6 + 1;
    }
    else if (*(unsigned char *)((char *)pbVar3 - 4) < 2) {
      *(unsigned char **)(*(int *)(param_1 + 0x1818) + iVar6 * 8) = pbVar3;
      *(int *)(*(int *)(param_1 + 0x1818) + iVar6 * 8 + 4) = iVar5;
      goto LAB_00239474;
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar5 < 0xf);
  local_c = 0;
  do {
    iVar4 = FUN_002acd28(local_c);
    if (iVar4 != 0) {
      if (*(unsigned int *)(param_1 + 0x1830) < *(unsigned int *)(param_1 + 0x1834)) {
        iVar4 = *(unsigned int *)(param_1 + 0x1830) + 1;
        *(int *)(param_1 + 0x1830) = iVar4;
        *(int *)(*(int *)(param_1 + 0x182c) + iVar4 * 4 + -4) = local_c;
      }
      else {
        FUN_00054510(param_1 + 0x182c, &local_c, 0);
      }
    }
    local_c = local_c + 1;
  } while (local_c < 0x28);
  FUN_001a5bcc(param_1 + 0x1838, 0x28, &DAT_002f5314, 0);
  iVar4 = 0;
  do {
    uVar2 = FUN_00065104(param_1 + 0x1904, iVar4 + 1, 0);
    iVar5 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1838) + iVar5) = uVar2;
  } while (iVar4 < 0x28);
  FUN_001a5bcc(param_1 + 0x1844, 0x28, &DAT_002f5318, 0);
  iVar4 = 0;
  do {
    uVar2 = FUN_00065104(param_1 + 0x1904, iVar4 + 1, 0);
    iVar5 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1844) + iVar5) = uVar2;
  } while (iVar4 < 0x28);
  FUN_0023a928(*(int *)(param_1 + 0x1844),
               *(int *)(param_1 + 0x1844) + *(int *)(param_1 + 0x1848) * 4, 0);
  FUN_0023c040(param_1 + 0x50);
  if (*(char *)(param_1 + 0x4c) != '\0') {
    FUN_001b3ce8(0x34179c, 6);
  }
  *(undefined4 *)(param_1 + 0x3c) = 1;
  FUN_00000028();
  return 1;
}
// near miss from lane fm10 (unreviewed)
