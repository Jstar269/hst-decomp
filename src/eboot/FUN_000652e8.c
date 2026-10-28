/* HSTMATCH module=EBOOT.BIN start=0x000652e8 end=0x0006531c symbol=FUN_000652e8 lang=c99 */
/* Clone of src/sharing_main/FUN_00066384.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00064a88();
extern void FUN_00066240();

void FUN_000652e8(int param_1)
{
  FUN_00064a88();
  FUN_00066240(param_1 + 0x10);
  FUN_00066240(param_1 + 0x20);
}
