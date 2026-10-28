/* HSTMATCH module=hstp_trans_main.prx start=0x001b1db4 end=0x001b1df0 symbol=FUN_001b1db4 lang=c99 */
/* Clone of src/eboot/FUN_001a47e8.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (range check written as one && condition); exact match verified; names and types await human review. */

void FUN_001b1db4(int param_1,int param_2)
{
  if (param_2 == 0xff) {
    *(int *)(param_1 + 0x2f4) = 0;
  }
  else if (param_2 >= 0 && param_2 < 2) {
    *(int *)(param_1 + 0x2f4) = param_2;
  }
  else {
    *(int *)(param_1 + 0x2f4) = 0;
  }
}
