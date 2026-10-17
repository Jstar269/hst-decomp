/* HSTMATCH module=hstp_trans_main.prx start=0x00139df0 end=0x00139e7c symbol=FUN_00139df0 lang=c99 */
/* Clone of src/eboot/compute_angles_0012e898.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: fixed unused first param type to int and typed float return values; exact match verified; names and types await human review. */

extern void *FUN_00022598(void *, void *, void *);
extern void FUN_00049820(void *, void *);
extern float FUN_00049cb4(void *);
extern float FUN_00049da8(void *);
extern float FUN_00049e34(void *);

struct Dst {
    char pad[0x40];
    float a;
    float b;
    float c;
};

void FUN_00139df0(int unused, struct Dst *dest, void *src)
{
    char mat[64];
    void *sub = (char *)*(void **)src + 0x30;
    FUN_00049820(mat, src);
    FUN_00022598(dest, sub, mat);
    dest->a = FUN_00049cb4(src) * 57.29578f;
    dest->b = FUN_00049da8(src);
    dest->c = FUN_00049e34(src);
}
