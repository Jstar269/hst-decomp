/* HSTMATCH module=EBOOT.BIN start=0x0012d868 end=0x0012d890 symbol=FUN_0012d868 lang=c99 */
/* Clone of src/sharing_main/FUN_00138d68.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_0005f110();

void FUN_0012d868(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0005f110(*(int *)(param_1 + 4));
  }
}
