/* HSTMATCH module=EBOOT.BIN start=0x0018b8b8 end=0x0018b8f8 symbol=FUN_0018b8b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
void FUN_0018b8b8(char *p, int row, int col, char v)
{
    char *r;

    if (row < 0) return;
    if (row >= 15) return;
    if (col < 0) return;
    if (col >= 4) return;
    r = p + row * 4;
    r[col] = v;
}
