/* HSTMATCH module=hstp_trans_main.prx start=0x0008af28 end=0x0008b034 symbol=FUN_0008af28 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: early return in state 3 and split else-if structure; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern undefined DAT_003e19f8;
extern undefined4 DAT_003e1e30;
extern undefined4 DAT_003e1f60;
extern void FUN_0008a19c(int, int);
extern void FUN_0008c400(int);
extern int FUN_0008c498(int);
extern int FUN_00100f4c(undefined4);
extern void FUN_00100fa4(undefined4);
extern void FUN_0020ae30(int, int);

void FUN_0008af28(int param_1)
{
  int iVar1;

  if (DAT_003e19f8 != 0 && DAT_003e1e30 != 0) {
    iVar1 = FUN_00100f4c(DAT_003e1f60);
    if (*(int *)(iVar1 + 0x4c) == 3) {
      FUN_0008c400(param_1);
      if (FUN_0008c498(param_1) == 0) {
        return;
      }
      FUN_0020ae30(FUN_00100f4c(DAT_003e1f60), 4);
      return;
    }
    iVar1 = FUN_00100f4c(DAT_003e1f60);
    if (*(int *)(iVar1 + 0x4c) == 5) {
      FUN_00100fa4(DAT_003e1f60);
      *(int *)(param_1 + 0x40) = 2;
      FUN_0008a19c(param_1, 0);
    }
  } else {
    iVar1 = FUN_00100f4c(DAT_003e1f60);
    if (*(int *)(iVar1 + 0x4c) == 5) {
      FUN_00100fa4(DAT_003e1f60);
      *(int *)(param_1 + 0x40) = 2;
      FUN_0008a19c(param_1, 0);
    }
  }
}
