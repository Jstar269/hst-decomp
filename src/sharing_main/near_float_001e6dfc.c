/* HSTMATCH module=hstp_trans_main.prx start=0x001e6dfc end=0x001e6e2c symbol=FUN_001e6dfc lang=c99 */
/* Clone of src/eboot/near_float_001d9050.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

int FUN_001e6dfc(float a, float b)
{
    return fabsf(a - b) < 0.001f;
}
