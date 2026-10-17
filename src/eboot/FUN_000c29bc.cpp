/* HSTMATCH module=EBOOT.BIN start=0x000c29bc end=0x000c2aa0 symbol=FUN_000c29bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
extern "C" void FUN_00022548(void *, void *, const Vec4 *);
extern "C" void FUN_000c29bc(float value1, float value2, int object, const Vec4 *firstArg,
                              const Vec4 *secondArg, const int *valueArg)
{
    Vec4 first = *firstArg;
    Vec4 second = *secondArg;
    char *self = (char *)object;
    if (*(int *)(self + 0x1d4) < 2) {
        *(int *)(self + 4) = 1;
        *(int *)(self + 0x1d4) = *(int *)(self + 0x1d4) + 1;
    }
    *(float *)(self + 0x120) = value1;
    *(float *)(self + 0x124) = value2;
    *(int *)(self + 0x134) = *valueArg;
    *(Vec4 *)(self + 0x30) = first;
    *(Vec4 *)(self + 0x10) = *(Vec4 *)(self + 0x30);
    FUN_00022548(self + 0x40, self + 0x90, &second);
    *(int *)(self + 0x128) = 0;
}
