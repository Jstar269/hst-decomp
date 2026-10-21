/* HSTMATCH module=hstp_trans_main.prx start=0x0001c848 end=0x0001c8a0 symbol=FUN_0001c848 lang=c99 */
/* Clone of src/eboot/lazy_region_init_0001cbfc.c (hstclone.py tag c21rt1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Sharing twin's near-miss wip (lane u1r2-1, Ghidra pseudocode) retargeted to EBOOT and corrected by hand: the lazily created region pointer is returned (Ghidra typed the function void), which colours the first load into v0; exact match verified; names and types await human review. */
extern int DAT_003751d0;
extern char *DAT_003b8efc;
extern char *DAT_003b8f00;
extern char *DAT_003b8f04;
extern void *FUN_00010184(int, int);

void *FUN_0001c848(void)
{
  char *p = DAT_003b8efc;
  if (p == 0) {
    p = FUN_00010184(0x40, DAT_003751d0);
    DAT_003b8efc = p;
    DAT_003b8f00 = p;
    DAT_003b8f04 = p + DAT_003751d0;
  }
  return p;
}
