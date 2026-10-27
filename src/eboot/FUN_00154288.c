/* HSTMATCH module=EBOOT.BIN start=0x00154288 end=0x001542dc symbol=FUN_00154288 data=0x002dc88c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc88c-0x002dc89d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct { int pad0, pad4; void *a; void *b; } Pair154;
extern unsigned char DAT_003402f0;
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt, void *b);
extern void FUN_002889cc(void *a, void *b);

int FUN_00154288(Pair154 *s, void *p)
{
    if (DAT_003402f0) {
        FUN_0014d044(p);
        FUN_0014fd94("LoadKomono [%s]\n", s->b);
    }
    FUN_002889cc(s->a, s->b);
    return 0;
}
