/* HSTMATCH module=EBOOT.BIN start=0x000fb590 end=0x000fb5f4 symbol=FUN_000fb590 lang=c99 */
typedef unsigned char uchar;
typedef unsigned char bool;

uchar FUN_000fb590(void *self)
{
    void *o = *(void **)((char *)self + 0x3c);
    void *s;

    if (o == 0) return 1;
    s = *(void **)((char *)o + 0x68);
    if (s == 0) return 1;
    if (*(uchar *)((char *)s + 0x54) == 0)
        return *(float *)((char *)s + 0x94) <= 0.0f;
    return 1;
}
// 22/25 words, 17 differ. Retail merges all three "return 1" sites into one epilogue: `beqzl v0,EPI`
// with `li v0,1` in the delay slot for both null checks, and a shared `li a0,1` early that the float
// select reuses (`bc1tl L; move v0,a0; move a0,zero; move v0,a0; L: andi v0,v0,0xff`), plus one
// unreachable `li v0,1` left before jr. Every source shape tried (early returns, nested ifs with a
// single trailing return 1, || chains, uchar/bool return, r-variable) makes MWCC invert the null
// tests to `bnezl x,CONT; b END; li v0,1` and lose two words.
// near miss from lane ds3 (unreviewed)
