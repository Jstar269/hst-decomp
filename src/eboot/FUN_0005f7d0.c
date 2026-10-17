/* HSTMATCH module=EBOOT.BIN start=0x0005f7d0 end=0x0005f848 symbol=FUN_0005f7d0 lang=c99 */
/* Clone of src/sharing_main/FUN_000605c0.c (hstclone.py tag s10171846c1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: reuse the scaled size for the unsigned boundary and preserve the selected-local branch order; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int uint;
typedef unsigned int undefined4;
extern char DAT_002d0f9c[];
extern int FUN_0000d518(void);
extern undefined1 *FUN_0000fe3c(void);
extern void FUN_0005f300(undefined4, const char *);
int FUN_0005f7d0(int param_1, uint param_2)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint local_4;
  uint local_8;
  local_8 = param_2;
  uVar3 = *(int *)(param_1 + 8) * 0x20;
  local_4 = uVar3;
  if (-1U - uVar3 < param_2) {
    iVar1 = (int)FUN_0000fe3c();
    FUN_0005f300(*(undefined4 *)(iVar1 + 0xc), DAT_002d0f9c);
    FUN_0000d518();
  }
  if (uVar3 < local_8) {
    puVar2 = &local_8;
  } else {
    puVar2 = &local_4;
  }
  return uVar3 + *puVar2;
}
