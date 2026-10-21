/* HSTMATCH module=EBOOT.BIN start=0x000e7cdc end=0x000e7df0 symbol=FUN_000e7cdc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000e7cdc { float x, y, z, w; };
struct Pair_000e7cdc { struct Vec4_000e7cdc a, b; };

void FUN_000e7cdc(char *self, struct Vec4_000e7cdc a, struct Vec4_000e7cdc b)
{
    if (*(unsigned char *)(self + 0xb0) != 0) {
        struct Pair_000e7cdc p;
        p.a = a;
        p.b = b;
        int i = *(int *)(self + 0x64);
        *(int *)(self + 0x64) = i + 1;
        struct Pair_000e7cdc *dst = (struct Pair_000e7cdc *)(*(int *)(self + 0x3c) + i * 0x20);
        *dst = p;
        *(int *)(self + 0x64) = *(int *)(self + 0x64) % *(int *)(self + 0x60);
        *(int *)(self + 0x68) = *(int *)(self + 0x68) + 1;
    }
    *(unsigned char *)(self + 0xb0) = *(unsigned char *)(self + 0x24);
}
