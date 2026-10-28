/* HSTMATCH module=hstp_trans_main.prx start=0x00133b80 end=0x00133be0 symbol=FUN_00133b80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: used an ordered mode switch and unsigned flag test to preserve the clear/call paths; exact match verified; names and types await human review. */

extern void FUN_00133aac();

void FUN_00133b80(int param_1)
{
  switch (*(int *)(param_1 + 400)) {
    case 0xb:
      FUN_00133aac();
      break;
    default:
      if (*(unsigned char *)(param_1 + 0x220) != 0) {
        *(unsigned int *)(param_1 + 0x1a0) = 0;
        *(unsigned int *)(param_1 + 0x1a4) = 0;
        *(unsigned int *)(param_1 + 0x1a8) = 0;
        *(unsigned int *)(param_1 + 0x1ac) = 0;
      } else {
        FUN_00133aac();
      }
      break;
  }
}
