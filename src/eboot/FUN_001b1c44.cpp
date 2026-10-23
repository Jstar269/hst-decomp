/* HSTMATCH module=EBOOT.BIN start=0x001b1c44 end=0x001b1d10 symbol=FUN_001b1c44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_002e5fe8[];
extern "C" int FUN_00014a40(void *);
extern "C" void FUN_000628b4(void *, int, int);
extern "C" int FUN_00062b64(void *, void *, int);

extern "C" int FUN_001b1c44(int **param_1, int param_2)
{
    int *base = *param_1;
    char *entry = DAT_002e5fe8 + param_2 * 8;
    int id = *(int *)entry;

    if (param_2 >= 29 && param_2 < 117)
        id += *(int *)((char *)base + 0x79c);
    bool ok = id < 0x1da;
    if (ok)
        ok = *(int *)((char *)base + id * 4) != 0;
    if (!ok)
        return -1;
    {
        int r = FUN_00014a40(*(void **)(entry + 4));
        if (r == 0)
            FUN_000628b4(*(void **)((char *)base + id * 4), 0, 0);
        return FUN_00062b64(*(void **)((char *)base + id * 4), *(void **)(entry + 4), 0);
    }
}
