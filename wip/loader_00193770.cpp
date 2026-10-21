/* HSTMATCH module=EBOOT.BIN start=0x00193770 end=0x001938d8 symbol=FUN_00193770 lang=c++ */
extern int DAT_00341730;
extern int DAT_002e1420;
extern int DAT_002e1524;
extern int DAT_0008d650;
extern "C" int FUN_0004cad0(int, void *, int, int);
extern "C" void FUN_00011090(void *, void *, int);
extern "C" void *FUN_00000bcc(unsigned int);
extern "C" int FUN_00000a90(int);
extern "C" int FUN_000008d8(int, int, int, int, int);
extern "C" void FUN_000104e0(int);

extern "C" int FUN_00193770(void) {
    int count;
    int size;
    int ok = 0;
    if (DAT_00341730 != 0) {
        return 0;
    }
    int h = FUN_0004cad0(DAT_002e1420, &size, 16, 1);
    if (h == 0) {
        return 0;
    }
    FUN_00011090(&count, (void *)h, 4);
    if (size == count * 156 + 4) {
        int *p = (int *)FUN_00000bcc(8);
        if (p != 0) {
            p[0] = 0;
            p[1] = 0;
        }
        DAT_00341730 = (int)p;
        if (p != 0) {
            int n = count;
            int mem = FUN_00000a90(n * 156 + 16);
            mem = FUN_000008d8(mem, DAT_0008d650, 0, 156, n);
            p[1] = mem;
            p[0] = n;
            FUN_00011090((void *)p[1], (void *)(h + 4), n * 156);
            ok = 1;
            if (DAT_002e1524 == 0) {
                DAT_002e1524 = 0;
            }
        }
    } else {
        ok = 1;
    }
    if (h != 0) {
        FUN_000104e0(h);
    }
    return ok;
}
// near miss (87/90 words): retail keeps only s0/s1 (no third saved register), returns through a
// single epilogue (`bnez v0,epilogue` with `move s0,zero` in the slot), reads size at sp+28 and
// count at sp+24 (declaration order `int size; int count;`), and treats a size mismatch as a
// success path that skips the allocation; our version branches earlier and keeps `ok` live.
// near miss from lane ds10 (unreviewed)
