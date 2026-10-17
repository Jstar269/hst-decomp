/* HSTMATCH module=hstp_trans_main.prx start=0x000a539c end=0x000a53f8 symbol=FUN_000a539c lang=c99 */
/* Clone of src/eboot/dist_threshold_angle_000a2c58.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_0000c6f4(float x, float y);

int FUN_000a539c(float x, float y, int unused, float *out)
{
    int ok = 0;
    if (x * x + y * y >= 0.25f) {
        ok = 1;
        *out = FUN_0000c6f4(x, y);
    }
    return ok;
}
