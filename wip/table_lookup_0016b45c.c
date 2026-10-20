/* HSTMATCH module=EBOOT.BIN start=0x0016b45c end=0x0016b4c0 symbol=FUN_0016b45c lang=c99 */
extern unsigned char DAT_00341ccc[];

char *FUN_0016b45c(int a0, int a1)
{
    char *r = 0;

    if (a0 >= 0 && a0 < 15 && a1 >= 0 && a1 < 4)
        r = (char *)(DAT_00341ccc + a0 * 56 + a1 * 12 + 0xd0);
    return r;
}
// 23/25 words, 9 differ. All four bound checks and the whole index computation (a0*56 as
// (a0*8-a0)*8, a1*12 as (a1*2+a1)*4, +0xd0) are word-for-word; retail is 2 words LONGER because it
// does NOT reuse the first check's `move v0,zero` delay slot: its first check is a likely branch to
// jr (`bltzl a0,JR; move v0,zero`), checks 2-4 jump to a separate `move v0,zero` block before jr, and
// the success path ends `b JR; addiu v0,v0,0xd0`. Ours hoists v0=0 into the first delay slot and
// merges the zero block away. Early-return, `||`-chain, value-variable and compute-first spellings
// all give other layouts (b: 25/25 words 18 differ, d: 23/25 25 differ).
// near miss from lane ds3 (unreviewed)
