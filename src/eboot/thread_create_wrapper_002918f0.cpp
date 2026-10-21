/* HSTMATCH module=EBOOT.BIN start=0x002918f0 end=0x002919d4 symbol=FUN_002918f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { float v[3]; };

extern "C" char DAT_002ffa04[];
extern "C" char DAT_002ff9dc[];
extern "C" void LAB_002919d4();

extern "C" int FUN_002b7920(void *, void *, int, int, int, int);
extern "C" int FUN_002b78d8(int, int, void *);
extern "C" void FUN_002b79a8(int);
extern "C" void FUN_0028fb44(char *, int);

extern "C" int FUN_002918f0(char *p, void *entry, int a2, float *v, int a4, int a5, int a6) {
    int r;
    V tmp = *(V *)v;
    char *local;
    *(int *)(p + 4) = a2;
    *(float *)(p + 8) = tmp.v[0];
    *(float *)(p + 0xc) = tmp.v[1];
    *(float *)(p + 0x10) = tmp.v[2];
    *(void **)(p + 0x18) = entry;
    r = FUN_002b7920(entry, (void *)&LAB_002919d4, a4, a5, a6, 0);
    *(int *)(p + 0x14) = r;
    if (r < 0) {
        FUN_0028fb44(DAT_002ffa04, r);
    } else {
        local = p;
        if (FUN_002b78d8(*(int *)(p + 0x14), 4, &local) < 0) {
            FUN_0028fb44(DAT_002ff9dc, *(int *)(p + 0x14));
        } else {
            return 1;
        }
    }
    if (*(int *)(p + 0x14) > 0) {
        FUN_002b79a8(*(int *)(p + 0x14));
        *(int *)(p + 0x14) = -1;
    }
    return 0;
}
