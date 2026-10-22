/* HSTMATCH module=EBOOT.BIN start=0x00046880 end=0x000468c8 symbol=FUN_00046880 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern unsigned char DAT_00311029;
extern unsigned char DAT_0030fbfe;

int FUN_00046880(int unused, int a1)
{
  if (a1 == 2 || a1 < 0) {
    DAT_00311029 = 1;
    DAT_0030fbfe = 1;
  }
  if (a1 == 1) {
    DAT_0030fbfe = 1;
  }
  return 0;
}
