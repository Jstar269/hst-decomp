/* HSTMATCH module=hstp_trans_main.prx start=0x000635c8 end=0x00063608 symbol=FUN_000635c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern int FUN_00073920();

void FUN_000635c8(int *param_1)
{
  int iVar1;
  
  if ((param_1[1] < 0) && (*param_1 != 0)) {
    iVar1 = FUN_00073920(*param_1,0);
    param_1[1] = iVar1;
  }
}
