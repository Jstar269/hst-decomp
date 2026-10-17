/* HSTMATCH module=EBOOT.BIN start=0x001d6208 end=0x001d621c symbol=FUN_001d6208 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { short pad0[2]; short lo; short pad1; short hi; } Span16;

short FUN_001d6208(Span16 *s)
{
    return s->hi - s->lo;
}
