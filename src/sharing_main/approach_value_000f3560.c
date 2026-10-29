/* HSTMATCH module=hstp_trans_main.prx start=0x000f3560 end=0x000f3588 symbol=FUN_000f3560 lang=c99 */
/* Clone of src/eboot/approach_value_000ede98.c (hstclone.py tag c180307): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

/* Move a toward b by s*(b-a) unless the gap is below lim, in which case snap to b. */
float FUN_000f3560(float a, float b, float s, float lim)
{
    float d = b - a;

    if (fabsf(d) >= lim) a = a + s * d;
    else a = b;
    return a;
}
