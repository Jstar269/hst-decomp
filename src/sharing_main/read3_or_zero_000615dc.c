/* HSTMATCH module=hstp_trans_main.prx start=0x000615dc end=0x00061610 symbol=FUN_000615dc lang=c99 */
/* Clone of src/eboot/read3_or_zero_00060758.c (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_002c7820(int *a, int *b, int *c, int d);

int FUN_000615dc(void)
{
    int a, b, c;
    if (FUN_002c7820(&a, &b, &c, 0) == 0)
        return a;
    return 0;
}
