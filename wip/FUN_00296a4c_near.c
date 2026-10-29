
// NEAR (15/14 words, 14 differ - INSTRUCTION ORDER IS NOW EXACT, only colour + one delay fill left).
// The structure is: nested positive guards, single `return n`, and a do/while whose condition carries the
// pointer advance and whose body is a lone increment:
//   unsigned n = 0; if (max != 0) { if (*s != 0) { do { n++; } while (n < max && *++s != 0); } } return n;
// Why each piece is needed (all measured this pass, 6 compiles):
//  - nested positive guards (NOT `if (max == 0) return 0;`): the block-terminating returns make mwcc invert the
//    first test into a branch-likely (`bnezl a1,...`), retail branches TO the shared epilogue (`beqz a1,...`).
//  - `do { n++; } while (...)` (NOT `for`/`while`, NOT `n = 1` before it): a pre-loop `n = 1` becomes a separate
//    block terminated by `b` with the `li` in its delay; the do/while body falls straight into the condition,
//    giving retail's contiguous `addiu n / sltu / beqz` at the loop head with no branch.
//  - the pointer advance inside the condition (`*++s`): with `s++` as a body statement mwcc ROTATES the loop
//    (test duplicated at the bottom, `s++` sunk into the back-edge delay); the side effect in the condition
//    pins the back edge on the bounds test with the increment in its delay - retail's `bnezl a3,<sltu>` slot.
// Residual: n is coloured v0 with the compare in `at` and both byte loads in v1; retail has n in v1 with the copy
// `move v0,v1` in the `jr ra` delay slot, the compare in a2 and the loads in a2/a3. A 7th compile with an `int`
// return type (to force a conversion node and a separate return pseudo) produced byte-identical code - ruled out.
/* HSTMATCH module=EBOOT.BIN start=0x00296a4c end=0x00296a84 symbol=FUN_00296a4c lang=c99 */
unsigned int FUN_00296a4c(const char *s, unsigned int max)
{
    unsigned int n = 0;
    if (max != 0) {
        if (*s != 0) {
            do {
                n++;
            } while (n < max && *++s != 0);
        }
    }
    return n;
}
// improved by lane dsn3 (unreviewed): 19 -> 14 differing words
