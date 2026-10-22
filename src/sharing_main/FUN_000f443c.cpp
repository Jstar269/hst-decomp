/* HSTMATCH module=hstp_trans_main.prx start=0x000f443c end=0x000f4528 symbol=FUN_000f443c lang=c++ */
/* Clone of src/eboot/FUN_000eed74.cpp (hstclone.py tag c25unfold): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int idx; char *name; int out; } Ent;

extern "C" Ent DAT_0037de2c[];
extern "C" float DAT_0037da74;
extern "C" char DAT_0037de5c[];
extern "C" char DAT_0037de00[];
extern "C" char DAT_003b0be0[];

extern "C" void FUN_0010873c();
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void *FUN_00109304(void *, void *, int);
extern "C" void *FUN_00108124(void *, void *);
extern "C" void FUN_000f4560(void *);

extern "C" void *FUN_000f443c(char *p) {
    int i;
    Ent *e;
    int off;
    FUN_0010873c();
    *(void **)p = &DAT_003b0be0;
    FUN_00109a44(p, DAT_0037de5c, 0);
    FUN_00108e6c(p, DAT_0037da74);
    FUN_001090f4(p, 0xffffff05);
    {
    void **pq = (void **)&DAT_0037de00;
    int j;
    for (j = 0; j < 1; j++) {}
    *(void **)(p + 0x58) = FUN_00109304(p, *pq, 0);
    }
    i = 0;
    e = DAT_0037de2c;
    off = 0;
    do {
        void *q = FUN_00108124(*(void **)(p + 0x58 + e->idx * 4), e->name);
        *(void **)(p + 0x5c + off) = q;
        i = i + 1;
        off = off + 4;
        e->out = *(int *)((char *)q + 0x24);
        e++;
    } while (i < 4);
    FUN_000f4560(p);
    return p;
}
// near miss from lane ds7 (unreviewed)
