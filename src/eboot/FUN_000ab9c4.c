/* HSTMATCH module=EBOOT.BIN start=0x000ab9c4 end=0x000aba38 symbol=FUN_000ab9c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: modeled the two copied values as Vec4 floats; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
extern char *DAT_003386b0;
extern void FUN_0008f948(int, const Vec4 *, const Vec4 *);
void FUN_000ab9c4(int unused, const Vec4 *a, const Vec4 *b)
{
    Vec4 first = *a;
    Vec4 second = *b;
    FUN_0008f948(*(int *)(DAT_003386b0 + 0x88), &first, &second);
}
