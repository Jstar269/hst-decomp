/* HSTMATCH module=EBOOT.BIN start=0x00060758 end=0x0006078c symbol=FUN_00060758 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
int FUN_002b7a80(int *a, int *b, int *c, int d);

int FUN_00060758(void)
{
    int a, b, c;
    if (FUN_002b7a80(&a, &b, &c, 0) == 0)
        return a;
    return 0;
}
