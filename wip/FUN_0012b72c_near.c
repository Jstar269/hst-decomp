/* HSTMATCH module=EBOOT.BIN start=0x0012b72c end=0x0012b760 symbol=FUN_0012b72c lang=c99 */
struct S { char pad[868]; unsigned char f364, pad2[1]; unsigned char f366, f367; };

int FUN_0012b72c(struct S *s, int a1, int mode)
{
    switch (mode) {
    case 0:
        return s->f364;
    case 4:
        return s->f366;
    case 5:
        return s->f367;
    }
    return 0;
}

// NEAR (11 vs 13 words, 52 bytes): retail's chain is beq 5 (move v0,zero in the always-executed delay),
// beql 4 (lbu 870 in the delay), beqzl 0 (lbu 868 in the delay), b, and a shared `lbu v0,871` block for
// mode 5 at the end. A switch with cases 0/4/5 folds the tests; separate ifs give the right order but
// hoist the loads.
// near miss from lane dsn3 (unreviewed)
