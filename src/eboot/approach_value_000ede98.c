/* HSTMATCH module=EBOOT.BIN start=0x000ede98 end=0x000edec0 symbol=FUN_000ede98 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

/* Move a toward b by s*(b-a) unless the gap is below lim, in which case snap to b. */
float FUN_000ede98(float a, float b, float s, float lim)
{
    float d = b - a;

    if (fabsf(d) >= lim) a = a + s * d;
    else a = b;
    return a;
}
