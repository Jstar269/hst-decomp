/* HSTMATCH module=hstp_trans_main.prx start=0x001e3ff8 end=0x001e400c symbol=FUN_001e3ff8 */
/* Clone of src/eboot/FUN_001d6208.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { short pad0[2]; short lo; short pad1; short hi; } Span16;

short FUN_001e3ff8(Span16 *s)
{
    return s->hi - s->lo;
}
