/* HSTMATCH module=EBOOT.BIN start=0x002ade48 end=0x002ade6c symbol=FUN_002ade48 lang=c99 */
struct S { int f0, f4; };

int FUN_002ade48(struct S *a, struct S *b)
{
    return a->f0 == b->f0 && a->f4 == b->f4;
}
// NEAR (12 vs 9 words, 36 bytes): retail folds the two int compares into one `or` + `sltiu v0,v0,1`
// (`((a.f0-b.f0) | (a.f4-b.f4)) == 0`) and loads both of b's words before a's second word. The `&&`
// spelling branches instead. Not tried: explicit subtract/or expression (next pass).
// near miss from lane dsn3 (unreviewed)
