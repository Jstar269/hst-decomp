/* HSTMATCH module=EBOOT.BIN start=0x00050210 end=0x00050240 symbol=FUN_00050210 lang=c99 */
struct E { int a, b, c, d; };
struct S { char pad[520]; struct E e[576]; };

int FUN_00050210(struct S *s, int i)
{
    int r = 0;
    if (i >= 0 && i < 576)
        r = s->e[i].a;
    return r;
}

// NEAR (5 words, 48 bytes): ours gets the whole shape (bltz guard with move v0,zero in the slot,
// slti at,a1,576, beqz to a zero return, sll/addu, load) but has ONE zero-return site where retail has
// two: retail's bltzl jumps to the final `jr ra` (value already in the delay slot) while the beqz lands on
// a separate 50234 `move v0,zero` that falls into the same `jr ra`. Retail also keeps the load in the
// `b epilogue` delay slot; ours uses `bltz` (not likely) and merges the load into the branch shadow.
// Tried: || guard, two early returns, `int r = 0; if (i >= 0 && i < 576) r = ...; return r;`,
// `if (i>=0) { if (i>=576) return 0; return e[i].a; } return 0;`, ?: in both polarities (10-14 words).
// near miss from lane dsn3 (unreviewed)
