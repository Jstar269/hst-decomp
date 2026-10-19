/* HSTMATCH module=hstp_trans_main.prx start=0x00176064 end=0x001760cc symbol=FUN_00176064 lang=c99 */
/* Clone of src/eboot/lane_mid_select_00169ea0.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char uchar;

void FUN_00176064(float *out, const float *a, const float *b, const int *c)
{
    uchar flag = (uchar)(*a < *b);
    int same = flag ^ (*c >= 0);

    if (same != 0)
        out[1] = out[2];
    else
        out[0] = out[2];
    out[2] = (out[1] + out[0]) / 2.0f;
}
