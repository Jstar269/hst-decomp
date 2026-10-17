/* HSTMATCH module=EBOOT.BIN start=0x001041dc end=0x001041f4 symbol=FUN_001041dc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x1c]; int a; int b; } Pair1c;
extern const char DAT_002d8ad0[];
extern void FUN_001041f4(Pair1c *p, const char *s, int c);

void FUN_001041dc(Pair1c *p, int a, int b, int c)
{
    p->a = a;
    p->b = b;
    FUN_001041f4(p, DAT_002d8ad0, c);
}
