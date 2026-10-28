/* HSTMATCH module=EBOOT.BIN start=0x00296adc end=0x00296b14 symbol=FUN_00296adc lang=c99 */
int FUN_00296adc(signed char *a, signed char *b, int n)
{
    int r = 0;
    if (n == 0)
        return r;
    do {
        signed char c1 = *a++;
        signed char c2 = *b++;
        n--;
        if (c1 != c2) {
            r = 1;
            break;
        }
    } while (n != 0);
    return r;
}

// NEAR (2 words, 56 bytes): retail keeps the result in a3 (`move a3,zero` at entry and after the loop,
// `li a3,1` in the bne delay, epilogue `move v0,a3`), loads the two bytes into v0/t0 and does
// n--, a++, b++ between the loads and the compare. Tried: do/while with post-increment loads, for(;;)+break,
// early returns; the result variable keeps landing in v0 and the loads in a3/v1.
// near miss from lane dsn3 (unreviewed)
