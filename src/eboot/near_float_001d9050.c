/* HSTMATCH module=EBOOT.BIN start=0x001d9050 end=0x001d9080 symbol=FUN_001d9050 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float fabsf(float);

int FUN_001d9050(float a, float b)
{
    return fabsf(a - b) < 0.001f;
}
