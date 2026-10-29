/* HSTMATCH module=EBOOT.BIN start=0x0012e898 end=0x0012e924 symbol=FUN_0012e898 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: fixed unused first param type to int and typed float return values; readability pass; exact match verified; names and types await human review. */

extern void *FUN_00022570(void *, void *, void *);
extern void FUN_00049970(void *, void *);
extern float FUN_00049da4(void *);
extern float FUN_00049e68(void *);
extern float FUN_00049ec4(void *);

/* Destination record: a 4x4 matrix followed by three angles. */
struct AngleDst {
    char matrix[0x40];
    float angle_deg;            /* 0x40 first angle, in degrees */
    float angle_b;              /* 0x44 */
    float angle_c;              /* 0x48 */
};

/* Writes a matrix built from src into dest, then stores three angles read from src (the first in degrees). */
void FUN_0012e898(int unused, struct AngleDst *dest, void *src)
{
    char mat[64];
    void *sub = (char *)*(void **)src + 0x30;
    FUN_00049970(mat, src);
    FUN_00022570(dest, sub, mat);
    dest->angle_deg = FUN_00049da4(src) * 57.29578f;
    dest->angle_b = FUN_00049e68(src);
    dest->angle_c = FUN_00049ec4(src);
}
