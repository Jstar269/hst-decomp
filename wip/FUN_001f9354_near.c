/* HSTMATCH module=EBOOT.BIN start=0x001f9354 end=0x001f9390 symbol=FUN_001f9354 lang=c99 */
struct S { char pad[64]; int f40; char pad2[1384 - 68]; unsigned char f568; };

int FUN_001f9354(struct S *s)
{
    int m = s->f40;
    if (m == 6 || m == 5)
        return s->f568 != 0;
    return 0;
}

// NEAR (9 vs 15 words, 60 bytes): retail keeps `beq a1,6` (move v0,zero in the delay) and
// `beql a1,5` (lbu f568 in the delay) as two separate tests that both fall into `beqz v1; li v0,1`.
// `m == 6 || m == 5` folds to a range test; two separate ifs hoist the f568 load.
// near miss from lane dsn3 (unreviewed)
