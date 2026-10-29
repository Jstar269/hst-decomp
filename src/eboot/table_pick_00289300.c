/* HSTMATCH module=EBOOT.BIN start=0x00289300 end=0x00289324 symbol=FUN_00289300 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00286acc(void *, int, void *);   /* formatted output: stream, format, argument */
extern char DAT_002febe4, DAT_002febfc, DAT_002fec04;

/* Print `format` to the stream with one of two texts chosen by `flag`. */
void FUN_00289300(int unused, int format, int flag)
{
    FUN_00286acc(&DAT_002febe4, format, flag ? &DAT_002febfc : &DAT_002fec04);
}
