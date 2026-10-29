/* HSTMATCH module=EBOOT.BIN start=0x0001cbfc end=0x0001cc54 symbol=FUN_0001cbfc lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Sharing twin's near-miss wip (lane u1r2-1, Ghidra pseudocode) retargeted to EBOOT and corrected by hand: the lazily created region pointer is returned (Ghidra typed the function void), which colours the first load into v0; exact match verified; names and types await human review. */
extern int DAT_002cfc88;
extern char *DAT_0030fc04;
extern char *DAT_0030fc08;
extern char *DAT_0030fc0c;
extern void *FUN_00010184(int, int);

/* Create the region on first use (start, cursor and end globals) and return its start. */
void *FUN_0001cbfc(void)
{
  char *region = DAT_0030fc04;
  if (region == 0) {
    region = FUN_00010184(0x40, DAT_002cfc88);
    DAT_0030fc04 = region;
    DAT_0030fc08 = region;
    DAT_0030fc0c = region + DAT_002cfc88;
  }
  return region;
}
