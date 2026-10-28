/* HSTMATCH module=EBOOT.BIN start=0x0011a4ac end=0x0011a4e8 symbol=FUN_0011a4ac lang=c99 */
struct S { char pad[612]; unsigned char b[6]; };

void FUN_0011a4ac(struct S *s)
{
    int i;
    for (i = 0; i < 6; i++)
        s->b[i] = 1;
}

// NEAR (whole-function shape, 60 bytes): `for (i = 0; i < 6; i++) s->b[i] = 1;` is fully unrolled by this
// MWCC (6 sb). Retail instead runs a 5x-unrolled loop (`move a2,zero; li a1,1; addu v1,a0,a2; 5x sb;
// addiu a2,a2,5; slti v1,a2,6; bnezl ...`) and peels the 6th store into the jr delay slot, which needs a
// loop whose trip count is not a compile-time constant in the same way.
// near miss from lane dsn3 (unreviewed)
