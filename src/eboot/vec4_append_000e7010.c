/* HSTMATCH module=EBOOT.BIN start=0x000e7010 end=0x000e7124 symbol=FUN_000e7010 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000e7010 { float x, y, z, w; };
struct Pair_000e7010 { struct Vec4_000e7010 a, b; };

void FUN_000e7010(char *self, struct Vec4_000e7010 a, struct Vec4_000e7010 b)
{
    if (*(unsigned char *)(self + 0xf0) != 0) {
        struct Pair_000e7010 p;
        p.a = a;
        p.b = b;
        int i = *(int *)(self + 0x60);
        *(int *)(self + 0x60) = i + 1;
        struct Pair_000e7010 *dst = (struct Pair_000e7010 *)(*(int *)(self + 0x3c) + i * 0x20);
        *dst = p;
        *(int *)(self + 0x60) = *(int *)(self + 0x60) % *(int *)(self + 0x5c);
        *(int *)(self + 0x64) = *(int *)(self + 0x64) + 1;
    }
    *(unsigned char *)(self + 0xf0) = *(unsigned char *)(self + 0x24);
}
