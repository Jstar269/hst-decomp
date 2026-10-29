/* HSTMATCH module=EBOOT.BIN start=0x000029f0 end=0x00002a14 symbol=FUN_000029f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: `opt_common_subs off` — the 3rd and 4th arguments are the SAME address (0x0030a010),
   which mwcc otherwise CSEs into `move a3,a2` (7 words instead of retail's 9). */
#pragma opt_common_subs off
extern char DAT_00306e24;
extern char DAT_00306ed8;
extern char DAT_0030a010;
extern void FUN_00000f98(void *,void *,void *,void *);

void FUN_000029f0(void)
{
    FUN_00000f98(&DAT_00306e24, &DAT_00306ed8, &DAT_0030a010, &DAT_0030a010);
}
