/* HSTMATCH module=EBOOT.BIN start=0x00054358 end=0x000543c4 symbol=FUN_00054358 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g1) corrected by hand: typed four-float copy of a stack result; exact match verified; names and types await human review. */
extern "C" int *FUN_0002e7d0(int obj);
extern "C" void FUN_00022548(float *out, int a1, int a2);

extern "C" void FUN_00054358(float *dst, char *src, int a2)
{
    float local[4];
    int *p = FUN_0002e7d0(*(int *)(src + 8) + 0x10);

    FUN_00022548(local, a2, *p + 0x30);
    dst[0] = local[0];
    dst[1] = local[1];
    dst[2] = local[2];
    dst[3] = local[3];
}
