/* HSTMATCH module=EBOOT.BIN start=0x00055044 end=0x000550c8 symbol=FUN_00055044 lang=c99 */
/* Clone of src/sharing_main/matrix_copy_00055b64.c (hstclone.py tag s10172123g5r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    struct Vec4 r0, r1, r2, r3;
};

struct Target {
    char pad[48];
    struct Mat4 mat;
};

void FUN_00055044(struct Target *dst, const struct Mat4 *src)
{
    dst->mat.r0 = src->r0;
    dst->mat.r1 = src->r1;
    dst->mat.r2 = src->r2;
    dst->mat.r3 = src->r3;
}
