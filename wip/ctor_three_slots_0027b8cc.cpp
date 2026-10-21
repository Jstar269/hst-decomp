/* HSTMATCH module=EBOOT.BIN start=0x0027b8cc end=0x0027ba20 symbol=FUN_0027b8cc lang=c++ */
extern int DAT_00309c44;
extern int DAT_0035a7e4;
extern "C" void FUN_0001f06c();
extern "C" void *FUN_00000bcc(int size);
extern "C" void *FUN_0027caa0(void *mem);
extern "C" void FUN_0027c008(void *self);
extern "C" void FUN_0027c328(void *self, int a1);
extern "C" void FUN_0027c774(void *self, int a1);
extern "C" void FUN_0027c2c8(void *self, const void *a1, const void *a2, float f);
extern "C" void FUN_0027dc90(int a0, int *out);
extern "C" void *FUN_0027b8cc(char *self) {
    FUN_0001f06c();
    *(unsigned int **)self = (unsigned int *)&DAT_00309c44;
    int i = 0;
    do {
        int off = i * 4;
        *(int *)(self + off + 0x3c) = 0;
        void *obj = FUN_00000bcc(160);
        if (obj != 0)
            obj = FUN_0027caa0(obj);
        *(int *)(self + off + 0x3c) = (int)obj;
        *(int *)(self + off + 0x48) = 0;
        *(int *)((char *)obj + 0x90) = (int)(self + off + 0x48);
        *(int *)((char *)obj + 0x94) = i;
        i++;
    } while (i < 3);
    self[100] = 0;
    *(int *)(self + 0x68) = -1;
    *(float *)(self + 0x6c) = -1.0f;
    *(int *)(self + 0x70) = 0;
    *(int *)(self + 0x54) = 0;
    *(int *)(self + 0x58) = 0;
    *(int *)(self + 0x5c) = 0;
    *(int *)(self + 0x60) = 0;
    FUN_0027c008(self);
    *(int *)(self + 0x74) = 0;
    const char *tbl = (const char *)(*(int *)&DAT_0035a7e4);
    char *ent = (char *)(tbl + (*(int *)(self + 0x54) << 6));
    if (*(int *)(ent + 0x24) != 0) {
        int iv = (int)*(float *)(ent + 0x2c);
        int tmp;
        FUN_0027dc90(*(int *)(ent + 0x34), &tmp);
        FUN_0027c774(self, tmp);
        FUN_0027c2c8(self, tbl + (*(int *)(self + 0x54) << 6), tbl + (0 << 6), (float)iv);
    } else {
        *(int *)(self + 0x48) = (int)ent;
        FUN_0027c328(self, 0);
    }
    return self;
}
// NEAR MISS: 84/85 words; the body logic matches but the compiler keeps `self + off` in callee-saved
// s4 (and self+off+0x3c in s3) across the FUN_00000bcc call, while retail recomputes `addu a0,s2,s0`
// after the call and keeps only s0/s1. Ruled out: typed struct-array access, hoisting the base into a
// local (worse), separate `int *a`/`int *b` locals.
// near miss from lane ds10 (unreviewed)
