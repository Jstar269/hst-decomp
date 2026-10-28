/* HSTMATCH module=EBOOT.BIN start=0x000dbc54 end=0x000dbc90 symbol=FUN_000dbc54 lang=c99 */
extern signed char DAT_003417b8[];

int FUN_000dbc54(void *self, int ch)
{
    int i;
    for (i = 0; i < 2; i++) {
        if (DAT_003417b8[i + 9] == ch)
            return 1;
    }
    return 0;
}
// NEAR (15 words vs 14, 60 bytes): retail indexes the table with a per-iteration `addu v0,v1,a0` +
// `lb v0,9(v0)` and tests with `sltiu` (unsigned counter); ours strength-reduces to a pointer walk
// (`lb 9(v1)` hoisted + `addiu v1,v1,1`) and tests with `slti`. Everything else (bnel/b + li v0,1 layout,
// sltiu placement) already matches.
// near miss from lane dsn3 (unreviewed)
