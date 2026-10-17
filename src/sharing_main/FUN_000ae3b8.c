/* HSTMATCH module=hstp_trans_main.prx start=0x000ae3b8 end=0x000ae42c symbol=FUN_000ae3b8 lang=c99 */
/* Clone of src/eboot/FUN_000ab9c4.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modeled the two copied values as Vec4 floats; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
extern char *DAT_003e19f0;
extern void FUN_00091548(int, const Vec4 *, const Vec4 *);
void FUN_000ae3b8(int unused, const Vec4 *a, const Vec4 *b)
{
    Vec4 first = *a;
    Vec4 second = *b;
    FUN_00091548(*(int *)(DAT_003e19f0 + 0x88), &first, &second);
}
