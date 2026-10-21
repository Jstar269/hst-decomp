/* HSTMATCH module=hstp_trans_main.prx start=0x002a2efc end=0x002a2fe0 symbol=FUN_002a2efc lang=c++ */
/* Clone of src/eboot/thread_create_wrapper_002918f0.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V { float v[3]; };

extern "C" char DAT_003a8910[];
extern "C" char DAT_003a88e8[];
extern "C" void LAB_002a2fe0();

extern "C" int FUN_002c76c0(void *, void *, int, int, int, int);
extern "C" int FUN_002c7678(int, int, void *);
extern "C" void FUN_002c7748(int);
extern "C" void FUN_002a130c(char *, int);

extern "C" int FUN_002a2efc(char *p, void *entry, int a2, float *v, int a4, int a5, int a6) {
    int r;
    V tmp = *(V *)v;
    char *local;
    *(int *)(p + 4) = a2;
    *(float *)(p + 8) = tmp.v[0];
    *(float *)(p + 0xc) = tmp.v[1];
    *(float *)(p + 0x10) = tmp.v[2];
    *(void **)(p + 0x18) = entry;
    r = FUN_002c76c0(entry, (void *)&LAB_002a2fe0, a4, a5, a6, 0);
    *(int *)(p + 0x14) = r;
    if (r < 0) {
        FUN_002a130c(DAT_003a8910, r);
    } else {
        local = p;
        if (FUN_002c7678(*(int *)(p + 0x14), 4, &local) < 0) {
            FUN_002a130c(DAT_003a88e8, *(int *)(p + 0x14));
        } else {
            return 1;
        }
    }
    if (*(int *)(p + 0x14) > 0) {
        FUN_002c7748(*(int *)(p + 0x14));
        *(int *)(p + 0x14) = -1;
    }
    return 0;
}
