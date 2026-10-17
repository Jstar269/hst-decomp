/* HSTMATCH module=hstp_trans_main.prx start=0x000bd514 end=0x000bd580 symbol=FUN_000bd514 lang=c99 */
/* Clone of src/eboot/FUN_000ba1d0.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modeled the 64-byte matrix temporary and copied its fourth row field by field; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { Vec4 row[4]; } Mat4;
extern int DAT_003e19f0;
extern void FUN_00056008(Mat4 *, int, int);
void FUN_000bd514(Vec4 *out, int self)
{
    Mat4 matrix;
    int index = *(int *)(self + 8);
    int *table = (int *)DAT_003e19f0;
    int object = table[index + 28];
    int subobject = *(int *)(object + 0x5bc);
    int value = *(int *)(subobject + 100);
    FUN_00056008(&matrix, value, self + 0x1c);
    out->x = matrix.row[3].x;
    out->y = matrix.row[3].y;
    out->z = matrix.row[3].z;
    out->w = matrix.row[3].w;
}
