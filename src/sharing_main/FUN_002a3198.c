/* HSTMATCH module=hstp_trans_main.prx start=0x002a3198 end=0x002a320c symbol=FUN_002a3198 lang=c99 */
/* Clone of src/eboot/FUN_00291b8c.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: express mode dispatch as a four-case switch with empty cases; exact match verified; names and types await human review. */
extern void FUN_002a320c(void *, int);
void FUN_002a3198(void *param_1, int param_2)
{
  switch (param_2) {
    case 0:
      FUN_002a320c(param_1, 1);
      FUN_002a320c(param_1, 3);
      break;
    case 1:
      break;
    case 2:
      FUN_002a320c(param_1, 4);
      break;
    case 3:
      break;
  }
}
