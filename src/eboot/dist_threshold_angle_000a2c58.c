/* HSTMATCH module=EBOOT.BIN start=0x000a2c58 end=0x000a2cb4 symbol=FUN_000a2c58 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern float FUN_0000c6dc(float x, float y);

int FUN_000a2c58(float x, float y, int unused, float *out)
{
    int ok = 0;
    if (x * x + y * y >= 0.25f) {
        ok = 1;
        *out = FUN_0000c6dc(x, y);
    }
    return ok;
}
