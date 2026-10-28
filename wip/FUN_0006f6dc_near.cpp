/* HSTMATCH module=EBOOT.BIN start=0x0006f6dc end=0x0006f748 symbol=FUN_0006f6dc lang=c++ */
/* Hand-written reconstruction from the disassembly (lane dsn2, DeepSeek V4.1 Flash (Freebuff)). */
extern "C" int FUN_0006f6dc(unsigned char *pa, char *pb)
{
    unsigned char ua = *pa;
    char cb;

    if ((char)ua != 0 && (cb = *pb) != 0 && (char)ua == cb) {
        do {
            ua = *++pa;
            cb = *++pb;
            if ((char)ua == 0 || cb == 0)
                break;
        } while ((char)ua == cb);
    }
    if ((char)ua != 0)
        return cb;
    return *pb == 0;
}

// NEAR 27/27 words (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); correct length and correct control shape,
// but a different (equivalent) compilation. Two concrete residues:
// (1) retail reads the raw byte UNFOLDED - `lbu v0,0(a0); seb a2,v0` - and keeps the unsigned byte (v0)
//     live to the shared join, where it re-sign-extends it in the branch delay slot (`seb v0,v0; bnez v0`).
//     Ours always comes out as a single `lb`, including when the source keeps both an `unsigned char ua`
//     and `(char)ua` views (MWCC folds lbu+seb into lb). The fold does not happen for retail, so the
//     original probably makes the signed view come from something opaque (an inline helper, or a
//     `(char)` cast through a differently-typed pointer); try `static inline char AsChar(unsigned char c)`.
// (2) the loop body is duplicated in retail (entry at 0x6f6dc == body at 0x6f71c, body end jumps back to
//     0x6f71c via `beql a2,v1`), i.e. the do-while/inverted-loop form of the Ghidra candidate; the current
//     file keeps that shape, and the 27 differing slots are all shifted by the (1) difference.
// Verified semantics (from the byte behaviour): returns 1 when both strings end together, 0 when b ends
// first (or a ends first while b has more), else b's differing byte - the tail is `if ((char)ua != 0)
// return cb; return *pb == 0;`.
// near miss from lane dsn2 (unreviewed)
