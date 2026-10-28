/* HSTMATCH module=hstp_trans_main.prx start=0x0020c8c4 end=0x0020c948 symbol=FUN_0020c8c4 lang=c99 */
/* Clone of src/eboot/poll_with_timeout_001fe0f4.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: type the callback result as int and preserve its negated condition through the polling loop; exact match verified; names and types await human review. */
extern unsigned char DAT_003f3478;
extern int FUN_00048e38(int);
extern void FUN_002c76f8(int);

void FUN_0020c8c4(int param_1)
{
  int iVar1;
  int iVar2;

  if (param_1 == 0) {
    iVar2 = 0;
    iVar1 = !FUN_00048e38(1);
    while (iVar1 != 0) {
      FUN_002c76f8(100000);
      iVar2++;
      if (iVar2 > 100)
        return;
      iVar1 = !FUN_00048e38(1);
    }
  } else {
    DAT_003f3478 = 1;
  }
}
