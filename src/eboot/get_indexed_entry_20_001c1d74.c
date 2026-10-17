/* HSTMATCH module=EBOOT.BIN start=0x001c1d74 end=0x001c1e20 symbol=FUN_001c1d74 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Derived from: try/gen-a1/v0/FUN_001c1d74.c (tag: a1) */
extern unsigned char *DAT_003386c8;
extern unsigned char *DAT_00338ac4;
extern char *DAT_003415a8;
extern int FUN_000bbba4(void *, void *);

static inline char *GetField20(void)
{
    char *r = 0;
    char *g = DAT_003415a8;
    if (g != 0) {
        r = g + 0x20;
    }
    return r;
}

void *FUN_001c1d74(void)
{
    int iVar4;
    char *iVar3;
    char *iVar2;
    int iVar1;

    iVar3 = 0;
    if (DAT_003386c8 != 0 && DAT_00338ac4 != 0) {
        iVar2 = *(char **)(DAT_003386c8 + 0x40);
        if (DAT_00338ac4[0x178] != 0) {
            iVar3 = GetField20();
        } else {
            iVar4 = 0;
            do {
                iVar1 = FUN_000bbba4(DAT_00338ac4, DAT_00338ac4 + 0x3e);
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
