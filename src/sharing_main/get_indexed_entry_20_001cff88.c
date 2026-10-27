/* HSTMATCH module=hstp_trans_main.prx start=0x001cff88 end=0x001d0034 symbol=FUN_001cff88 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/get_indexed_entry_20_001c1d74.c: addresses retargeted, DAT_003386c8/DAT_00338ac4/DAT_003415a8/FUN_000bbba4 -> DAT_003e1a08/DAT_003e1e04/DAT_003ea8e8/FUN_000bf018); exact match verified; names and types await human review. */
extern unsigned char *DAT_003e1a08;
extern unsigned char *DAT_003e1e04;
extern char *DAT_003ea8e8;
extern int FUN_000bf018(void *, void *);

static inline char *GetField20(void)
{
    char *r = 0;
    char *g = DAT_003ea8e8;
    if (g != 0) {
        r = g + 0x20;
    }
    return r;
}

void *FUN_001cff88(void)
{
    int iVar4;
    char *iVar3;
    char *iVar2;
    int iVar1;

    iVar3 = 0;
    if (DAT_003e1a08 != 0 && DAT_003e1e04 != 0) {
        iVar2 = *(char **)(DAT_003e1a08 + 0x40);
        if (DAT_003e1e04[0x178] != 0) {
            iVar3 = GetField20();
        } else {
            iVar4 = 0;
            do {
                iVar1 = FUN_000bf018(DAT_003e1e04, DAT_003e1e04 + 0x3e);
                if (*(int *)(iVar2 + 0x1bd8) == iVar1) {
                    iVar3 = iVar2 + 0x1bac;
                }
                iVar4 = iVar4 + 1;
                iVar2 = iVar2 + 0x458;
            } while (iVar4 < 4);
        }
    }
    return iVar3;
}
