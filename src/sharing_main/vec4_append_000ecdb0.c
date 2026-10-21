/* HSTMATCH module=hstp_trans_main.prx start=0x000ecdb0 end=0x000ecec4 symbol=FUN_000ecdb0 lang=c99 */
/* Clone of src/eboot/vec4_append_000e7cdc.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4_000ecdb0 { float x, y, z, w; };
struct Pair_000ecdb0 { struct Vec4_000ecdb0 a, b; };

void FUN_000ecdb0(char *self, struct Vec4_000ecdb0 a, struct Vec4_000ecdb0 b)
{
    if (*(unsigned char *)(self + 0xb0) != 0) {
        struct Pair_000ecdb0 p;
        p.a = a;
        p.b = b;
        int i = *(int *)(self + 0x64);
        *(int *)(self + 0x64) = i + 1;
        struct Pair_000ecdb0 *dst = (struct Pair_000ecdb0 *)(*(int *)(self + 0x3c) + i * 0x20);
        *dst = p;
        *(int *)(self + 0x64) = *(int *)(self + 0x64) % *(int *)(self + 0x60);
        *(int *)(self + 0x68) = *(int *)(self + 0x68) + 1;
    }
    *(unsigned char *)(self + 0xb0) = *(unsigned char *)(self + 0x24);
}
