/* HSTMATCH module=EBOOT.BIN start=0x001fe0f4 end=0x001fe178 symbol=FUN_001fe0f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: type the callback result as int and preserve its negated condition through the polling loop; exact match verified; names and types await human review. */
extern unsigned char DAT_0034a140;
extern int FUN_00049094(int);
extern void FUN_002b7958(int);

void FUN_001fe0f4(int param_1)
{
  int iVar1;
  int iVar2;

  if (param_1 == 0) {
    iVar2 = 0;
    iVar1 = !FUN_00049094(1);
    while (iVar1 != 0) {
      FUN_002b7958(100000);
      iVar2++;
      if (iVar2 > 100)
        return;
      iVar1 = !FUN_00049094(1);
    }
  } else {
    DAT_0034a140 = 1;
  }
}
