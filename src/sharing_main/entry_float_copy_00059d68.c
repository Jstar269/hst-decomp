/* HSTMATCH module=hstp_trans_main.prx start=0x00059d68 end=0x00059de4 symbol=FUN_00059d68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed copied fields as float, scoped loop locals, and formed the direct-path offset before adding the object base; exact match verified; names and types await human review. */

void FUN_00059d68(int param_1,int param_2)
{
  if (param_2 < 0) {
    int iVar2 = *(int *)(param_1 + 0x158);
    if (iVar2 <= *(int *)(param_1 + 0x15c)) {
      int iVar1 = param_1 + iVar2 * 0x34;
      do {
        iVar2 = iVar2 + 1;
        *(float *)(iVar1 + 0x10c) = *(float *)(iVar1 + 0x100);
        iVar1 = iVar1 + 0x34;
      } while (iVar2 <= *(int *)(param_1 + 0x15c));
    }
  }
  else {
    int offset = param_2 * 0x34;
    offset += param_1;
    *(float *)(offset + 0x10c) = *(float *)(offset + 0x100);
  }
}
