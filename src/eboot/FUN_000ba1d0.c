/* HSTMATCH module=EBOOT.BIN start=0x000ba1d0 end=0x000ba23c symbol=FUN_000ba1d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modeled the 64-byte matrix temporary and copied its fourth row field by field; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 row[4]; } Mat4;
extern int DAT_003386b0;
extern void FUN_0005548c(Mat4 *, int, int);
void FUN_000ba1d0(Vec4 *out, int self)
{
    Mat4 matrix;
    int index = *(int *)(self + 8);
    int *table = (int *)DAT_003386b0;
    int object = table[index + 28];
    int subobject = *(int *)(object + 0x5bc);
    int value = *(int *)(subobject + 100);
    FUN_0005548c(&matrix, value, self + 0x1c);
    out->x = matrix.row[3].x;
    out->y = matrix.row[3].y;
    out->z = matrix.row[3].z;
    out->w = matrix.row[3].w;
}
