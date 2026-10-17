/* HSTMATCH module=hstp_trans_main.prx start=0x000e1e94 end=0x000e1ed0 symbol=FUN_000e1e94 */
/* Clone of src/eboot/FUN_000ddca8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
typedef struct { char pad[0x5c]; int a; int b; } Totals5c;
typedef struct { char pad[0xa0]; Totals5c *totals; } MatchMgrA0;
typedef struct { char pad[0xb8]; int a; int b; } Delta;
extern MatchMgrA0 *DAT_003e19f0;

void FUN_000e1e94(Delta *d)
{
    DAT_003e19f0->totals->a += d->a;
    DAT_003e19f0->totals->b += d->b;
}
