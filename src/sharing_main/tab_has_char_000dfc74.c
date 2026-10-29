/* HSTMATCH module=hstp_trans_main.prx start=0x000dfc74 end=0x000dfcb0 symbol=FUN_000dfc74 lang=c99 */
/* Clone of src/eboot/tab_has_char_000dbc54.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: `#pragma opt_strength_reduction off` (without it mwcc turns `base[i + 9]` into a pointer
   walk) and the byte is read into a `signed char` local before the compare (comparing the loaded expression
   directly puts the parameter in rs; retail's `bnel v0,a1` needs the byte first). */
#pragma opt_strength_reduction off
extern signed char DAT_003eaaf0[];

int FUN_000dfc74(void *self, int ch)
{
    signed char *base = DAT_003eaaf0;
    unsigned i;
    signed char c;
    for (i = 0; i < 2; i++) {
        c = base[i + 9];
        if (c == ch)
            return 1;
    }
    return 0;
}
