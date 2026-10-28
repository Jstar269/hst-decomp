/* HSTMATCH module=hstp_trans_main.prx start=0x00059b34 end=0x00059ba8 symbol=FUN_00059b34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the stored value as float, scoped loop locals, and formed the direct-path offset before adding the object base; exact match verified; names and types await human review. */

void FUN_00059b34(float param_1,int param_2,int param_3)
{
  if (param_3 < 0) {
    int iVar2 = *(int *)(param_2 + 0x158);
    if (iVar2 <= *(int *)(param_2 + 0x15c)) {
      int iVar1 = param_2 + iVar2 * 0x34;
      do {
        *(float *)(iVar1 + 0xfc) = param_1;
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x34;
      } while (iVar2 <= *(int *)(param_2 + 0x15c));
    }
  }
  else {
    int offset = param_3 * 0x34;
    offset += param_2;
    *(float *)(offset + 0xfc) = param_1;
  }
}
