/* HSTMATCH module=EBOOT.BIN start=0x001b4d4c end=0x001b4dfc symbol=FUN_001b4d4c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_0034178c;
extern char DAT_002e7700[];
extern int FUN_00062b64(void *, int, int);

int FUN_001b4d4c(int **ctx, int slot, int row_index)
{
    int *base = *ctx;
    char *row = DAT_002e7700 + row_index * 0x1c;
    int id = *(int *)row;
    int seed = DAT_0034178c * 0x343fd + 0x269ec3;
    int idx;
    int p;
    int r;

    DAT_0034178c = seed;
    idx = (int)(((unsigned int)seed >> 16) & 0x7fff) % (int)*(unsigned char *)(row + 4);
    if (id == 0x15b && (p = ((int *)((char *)base + 0x778))[slot]) != 0)
        r = FUN_00062b64((void *)p, ((int *)(row + 8))[idx], 0);
    else
        r = -1;
    return r;
}
