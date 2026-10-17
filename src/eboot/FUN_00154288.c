/* HSTMATCH module=EBOOT.BIN start=0x00154288 end=0x001542dc symbol=FUN_00154288 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; void *a; void *b; } Pair154;
extern unsigned char DAT_003402f0;
extern char DAT_002dc88c[];
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt, void *b);
extern void FUN_002889cc(void *a, void *b);

int FUN_00154288(Pair154 *s, void *p)
{
    if (DAT_003402f0) {
        FUN_0014d044(p);
        FUN_0014fd94(DAT_002dc88c, s->b);
    }
    FUN_002889cc(s->a, s->b);
    return 0;
}
