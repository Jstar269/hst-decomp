/* HSTMATCH module=EBOOT.BIN start=0x0012c1c4 end=0x0012c2dc symbol=FUN_0012c1c4 lang=c99 */
extern char DAT_002cfc8c[];
extern int DAT_0033b574;
extern int DAT_0033b4a4;
extern int FUN_0012d76c(void);
extern void FUN_00126d1c(char *msg);
extern char DAT_002da9f3[];

int FUN_0012c1c4(int state)
{
    if (state == 4)
        return ((((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e)) == 0;
    if (state == 3) {
        if (DAT_0033b574 != 0 && FUN_0012d76c() != 0)
            return 0;
        if (((((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1a) >> 0x1e)) != 0)
            return 0;
        return DAT_0033b4a4 != 0;
    }
    if (state == 2)
        return 0;
    if (state == 1)
        return ((((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1a) >> 0x1e)) != 1;
    if (state == 0)
        return 0;
    FUN_00126d1c(DAT_002da9f3);
    return 0;
}
// NEAR MISS: 58/70 words. Retail dispatches with a DESCENDING compare chain (`li v0,4; beq a0,v0,L4;
// li v0,3; beq ...; li v0,2; beql ...; ...`) and places every case body out of line AFTER the chain,
// including two unreachable `move v0,zero; b end` blocks (case 2 and case 0). Ruled out this session:
// `switch (state)` with cases written 4,3,2,1,0 (mwcc reorders to ascending compares and inlines each
// body: 57 words), `else if` chain (58), separate `if {}` blocks (58). The chain forms always inline the
// case bodies right after their compare, so the out-of-line layout is what is missing, not the bodies.
// near miss from lane ds11 (unreviewed)
