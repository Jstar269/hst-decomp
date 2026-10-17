/* HSTMATCH module=hstp_trans_main.prx start=0x0017f844 end=0x0017f918 symbol=FUN_0017f844 lang=c99 */
/* Clone of src/eboot/update_item_display_001734b8.c (hstclone.py tag u1r5s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: branch order (count > 0 first); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern undefined *DAT_003ea8ec;
extern void FUN_0011e940(undefined *, int, undefined4, int, int);
extern void FUN_0011fe30(undefined *, int, undefined4, int, int);
extern void FUN_001939e0(undefined4, int);
extern undefined *FUN_0020d1e0(int, int, int);

void FUN_0017f844(int param_1)
{
  if (*(int *)(param_1 + 0x56c) > 0) {
    int iVar1 = (int)(DAT_003ea8ec);
    *(undefined4 *)(**(int **)(DAT_003ea8ec + 4) + 0x60) = 0x43a10000;
    *(undefined4 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
    iVar1 = (int)(DAT_003ea8ec);
    *(undefined4 *)(DAT_003ea8ec + 0x74) = 0x3f666666;
    *(undefined4 *)(iVar1 + 0x78) = 0x3f666666;
    undefined4 uVar2 = (unsigned int)(FUN_0020d1e0(0x11,5,1));
    FUN_0011fe30(DAT_003ea8ec,0,uVar2,0,0);
    FUN_001939e0(*(undefined4 *)(param_1 + 0x174),0);
  }
  else {
    undefined4 uVar2 = (unsigned int)(FUN_0020d1e0(0x11,5,5));
    FUN_0011e940(DAT_003ea8ec,0,uVar2,0,0);
  }
  return;
}
