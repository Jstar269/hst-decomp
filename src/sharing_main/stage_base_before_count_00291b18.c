/* HSTMATCH module=hstp_trans_main.prx start=0x00291b18 end=0x00291b78 symbol=FUN_00291b18 lang=c99 */
/* Clone of src/eboot/stage_base_before_count_002807d0.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *DAT_003e1a08;
extern int FUN_0001100c(void *p, void *self, int n);

void FUN_00291b18(void *self)
{
    void *g = DAT_003e1a08;
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
