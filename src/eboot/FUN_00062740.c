/* HSTMATCH module=EBOOT.BIN start=0x00062740 end=0x00062780 symbol=FUN_00062740 lang=c99 */
/* Clone of src/sharing_main/FUN_000635c8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_00072160();

void FUN_00062740(int *param_1)
{
  int iVar1;
  
  if ((param_1[1] < 0) && (*param_1 != 0)) {
    iVar1 = FUN_00072160(*param_1,0);
    param_1[1] = iVar1;
  }
}
