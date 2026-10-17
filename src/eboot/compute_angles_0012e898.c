/* HSTMATCH module=EBOOT.BIN start=0x0012e898 end=0x0012e924 symbol=FUN_0012e898 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: fixed unused first param type to int and typed float return values; exact match verified; names and types await human review. */

extern void *FUN_00022570(void *, void *, void *);
extern void FUN_00049970(void *, void *);
extern float FUN_00049da4(void *);
extern float FUN_00049e68(void *);
extern float FUN_00049ec4(void *);

struct Dst {
    char pad[0x40];
    float a;
    float b;
    float c;
};

void FUN_0012e898(int unused, struct Dst *dest, void *src)
{
    char mat[64];
    void *sub = (char *)*(void **)src + 0x30;
    FUN_00049970(mat, src);
    FUN_00022570(dest, sub, mat);
    dest->a = FUN_00049da4(src) * 57.29578f;
    dest->b = FUN_00049e68(src);
    dest->c = FUN_00049ec4(src);
}
