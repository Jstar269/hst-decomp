/* HSTMATCH module=hstp_trans_main.prx start=0x000ec00c end=0x000ec120 symbol=FUN_000ec00c lang=c99 */
/* Clone of src/eboot/vec4_append_000e7010.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000ec00c { float x, y, z, w; };
struct Pair_000ec00c { struct Vec4_000ec00c a, b; };

void FUN_000ec00c(char *self, struct Vec4_000ec00c a, struct Vec4_000ec00c b)
{
    if (*(unsigned char *)(self + 0xf0) != 0) {
        struct Pair_000ec00c p;
        p.a = a;
        p.b = b;
        int i = *(int *)(self + 0x60);
        *(int *)(self + 0x60) = i + 1;
        struct Pair_000ec00c *dst = (struct Pair_000ec00c *)(*(int *)(self + 0x3c) + i * 0x20);
        *dst = p;
        *(int *)(self + 0x60) = *(int *)(self + 0x60) % *(int *)(self + 0x5c);
        *(int *)(self + 0x64) = *(int *)(self + 0x64) + 1;
    }
    *(unsigned char *)(self + 0xf0) = *(unsigned char *)(self + 0x24);
}
