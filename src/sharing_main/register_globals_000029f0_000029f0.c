/* HSTMATCH module=hstp_trans_main.prx start=0x000029f0 end=0x00002a14 symbol=FUN_000029f0 lang=c99 */
/* Clone of src/eboot/register_globals_000029f0.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: `opt_common_subs off` — the 3rd and 4th arguments are the SAME address (0x3b32e0),
   which mwcc otherwise CSEs into `move a3,a2` (7 words instead of retail's 9). */
#pragma opt_common_subs off
extern char DAT_003b00f0;
extern char DAT_003b01a4;
extern char DAT_003b32e0;
extern void FUN_00000f98(void *,void *,void *,void *);

void FUN_000029f0(void)
{
    FUN_00000f98(&DAT_003b00f0, &DAT_003b01a4, &DAT_003b32e0, &DAT_003b32e0);
}
