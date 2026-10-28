/* HSTMATCH module=EBOOT.BIN start=0x00204400 end=0x0020443c symbol=FUN_00204400 lang=c99 */
extern void *DAT_0034a148;

char *FUN_00204400(int i)
{
    if (DAT_0034a148 == 0)
        return 0;
    if (i < 0)
        return 0;
    if (i >= 15)
        return 0;
    return (char *)DAT_0034a148 + i * 16;
}

// NEAR (2 words, 60 bytes): same inverted-guard structure as 0xde208 - retail branches BOTH range failures
// to one trailing `move v0,zero` block (slti into $at, not v0) after a beqzl on the global, and leaves the
// body in the fall-through. Ours emits bnez/bgezl to the body plus extra `b`s. The `slti at` form (rather
// than slti v0) is the tell that retail's compare result is branch-only.
// near miss from lane dsn3 (unreviewed)
