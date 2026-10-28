/* HSTMATCH module=EBOOT.BIN start=0x00128910 end=0x00128970 symbol=FUN_00128910 lang=c99 */
/* Clone of src/sharing_main/update_mode_state_00133b80.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: used an ordered mode switch and unsigned flag test to preserve the clear/call paths; exact match verified; names and types await human review. */

extern void FUN_0012883c();

void FUN_00128910(int param_1)
{
  switch (*(int *)(param_1 + 400)) {
    case 0xb:
      FUN_0012883c();
      break;
    default:
      if (*(unsigned char *)(param_1 + 0x220) != 0) {
        *(unsigned int *)(param_1 + 0x1a0) = 0;
        *(unsigned int *)(param_1 + 0x1a4) = 0;
        *(unsigned int *)(param_1 + 0x1a8) = 0;
        *(unsigned int *)(param_1 + 0x1ac) = 0;
      } else {
        FUN_0012883c();
      }
      break;
  }
}
