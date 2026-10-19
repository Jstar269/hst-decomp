/* HSTMATCH module=EBOOT.BIN start=0x002807d0 end=0x00280830 symbol=FUN_002807d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_003386c8;
extern int FUN_0001100c(void *p, void *self, int n);

void FUN_002807d0(void *self)
{
    void *g = DAT_003386c8;
    unsigned char *o;
    unsigned char *base;

    if (g == 0)
        return;
    o = *(unsigned char **)((char *)g + 0x40);
    if (o[0x2c00] == 0)
        return;
    base = o + 0x3078;
    if (*(int *)(o + 0x34d0) <= 0)
        return;
    if (FUN_0001100c(base + 928, self, 6) != 0)
        return;
    base[301] = 0;
}
