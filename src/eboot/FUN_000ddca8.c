/* HSTMATCH module=EBOOT.BIN start=0x000ddca8 end=0x000ddce4 symbol=FUN_000ddca8 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x5c]; int a; int b; } Totals5c;
typedef struct { char pad[0xa0]; Totals5c *totals; } MatchMgrA0;
typedef struct { char pad[0xb8]; int a; int b; } Delta;
extern MatchMgrA0 *DAT_003386b0;

void FUN_000ddca8(Delta *d)
{
    DAT_003386b0->totals->a += d->a;
    DAT_003386b0->totals->b += d->b;
}
