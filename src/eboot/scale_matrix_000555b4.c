/* HSTMATCH module=EBOOT.BIN start=0x000555b4 end=0x000556b0 symbol=FUN_000555b4 lang=c99 */
/* Clone of src/sharing_main/scale_matrix_00056160.c (hstclone.py tag ag56e): addresses substituted; exact match verified; names and types await human review. */
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
    char pad2[24];
    float scale;
};

extern void FUN_00022498(struct Vec4 *out, const struct Vec4 *in, float scale);

void FUN_000555b4(struct Mat4 *out, const struct Target *src)
{
    struct Mat4 m;
    FUN_00022498(&m.r0, &src->mat.r0, src->scale);
    FUN_00022498(&m.r1, &src->mat.r1, src->scale);
    FUN_00022498(&m.r2, &src->mat.r2, src->scale);

    m.r3.x = src->mat.r3.x;
    m.r3.y = src->mat.r3.y;
    m.r3.z = src->mat.r3.z;
    m.r3.w = src->mat.r3.w;

    ((float *)out)[0] = ((float *)&m)[0];
    ((float *)out)[1] = ((float *)&m)[1];
    ((float *)out)[2] = ((float *)&m)[2];
    ((float *)out)[3] = ((float *)&m)[3];
    ((float *)out)[4] = ((float *)&m)[4];
    ((float *)out)[5] = ((float *)&m)[5];
    ((float *)out)[6] = ((float *)&m)[6];
    ((float *)out)[7] = ((float *)&m)[7];
    ((float *)out)[8] = ((float *)&m)[8];
    ((float *)out)[9] = ((float *)&m)[9];
    ((float *)out)[10] = ((float *)&m)[10];
    ((float *)out)[11] = ((float *)&m)[11];
    ((float *)out)[12] = ((float *)&m)[12];
    ((float *)out)[13] = ((float *)&m)[13];
    ((float *)out)[14] = ((float *)&m)[14];
    ((float *)out)[15] = ((float *)&m)[15];
}
