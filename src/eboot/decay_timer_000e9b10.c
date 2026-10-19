/* HSTMATCH module=EBOOT.BIN start=0x000e9b10 end=0x000e9b50 symbol=FUN_000e9b10 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S {
    char pad[0x5f0];
    float f5f0;
    int f5f4;
    int f5f8;
    int f5fc;
};

void FUN_000e9b10(struct S *s)
{
    if (s->f5f4 > s->f5fc - 20) {
        s->f5f0 = s->f5f0 - 0.1f;
    }
    s->f5f4++;
}
