/* HSTMATCH module=EBOOT.BIN start=0x00058ec4 end=0x00058f38 symbol=FUN_00058ec4 lang=c99 */
/* Clone of src/sharing_main/entry_float_100_00059ba8.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the stored value as float, scoped loop locals, and formed the direct-path offset before adding the object base; exact match verified; names and types await human review. */

void FUN_00058ec4(float param_1,int param_2,int param_3)
{
  if (param_3 < 0) {
    int iVar2 = *(int *)(param_2 + 0x158);
    if (iVar2 <= *(int *)(param_2 + 0x15c)) {
      int iVar1 = param_2 + iVar2 * 0x34;
      do {
        *(float *)(iVar1 + 0x100) = param_1;
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x34;
      } while (iVar2 <= *(int *)(param_2 + 0x15c));
    }
  }
  else {
    int offset = param_3 * 0x34;
    offset += param_2;
    *(float *)(offset + 0x100) = param_1;
  }
}
