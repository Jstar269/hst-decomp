/* HSTMATCH module=EBOOT.BIN start=0x00169ea0 end=0x00169f08 symbol=FUN_00169ea0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

void FUN_00169ea0(float *out, const float *a, const float *b, const int *c)
{
    uchar flag = (uchar)(*a < *b);
    int same = flag ^ (*c >= 0);

    if (same != 0)
        out[1] = out[2];
    else
        out[0] = out[2];
    out[2] = (out[1] + out[0]) / 2.0f;
}
