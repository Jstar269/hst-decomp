/* HSTMATCH module=hstp_trans_main.prx start=0x00055b64 end=0x00055be8 symbol=FUN_00055b64 lang=c99 */
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

void FUN_00055b64(struct Target *dst, const struct Mat4 *src)
{
    dst->mat.r0 = src->r0;
    dst->mat.r1 = src->r1;
    dst->mat.r2 = src->r2;
    dst->mat.r3 = src->r3;
}
