/* HSTMATCH module=EBOOT.BIN start=0x001734b8 end=0x0017358c symbol=FUN_001734b8 lang=c99 */
/* Hand-written reconstruction from Ghidra pseudocode: branch order (count > 0 first); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

extern undefined *DAT_003415ac;
extern void FUN_00114168(undefined *, int, undefined4, int, int);
extern void FUN_00115040(undefined *, int, undefined4, int, int);
extern void FUN_00187294(undefined4, int);
extern undefined *FUN_001fea10(int, int, int);

void FUN_001734b8(int param_1)
{
  if (*(int *)(param_1 + 0x56c) > 0) {
    int iVar1 = (int)(DAT_003415ac);
    *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43a10000;
    *(undefined4 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
    iVar1 = (int)(DAT_003415ac);
    *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f666666;
    *(undefined4 *)(iVar1 + 0x78) = 0x3f666666;
    undefined4 uVar2 = (unsigned int)(FUN_001fea10(0x11,5,1));
    FUN_00115040(DAT_003415ac,0,uVar2,0,0);
    FUN_00187294(*(undefined4 *)(param_1 + 0x174),0);
  }
  else {
    undefined4 uVar2 = (unsigned int)(FUN_001fea10(0x11,5,5));
    FUN_00114168(DAT_003415ac,0,uVar2,0,0);
  }
  return;
}
