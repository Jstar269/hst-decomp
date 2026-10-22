/* HSTMATCH module=EBOOT.BIN start=0x000eed74 end=0x000eee60 symbol=FUN_000eed74 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { int idx; char *name; int out; } Ent;

extern "C" Ent DAT_002d7054[];
extern "C" float DAT_002d6c9c;
extern "C" char DAT_002d7084[];
extern "C" char DAT_002d7028[];
extern "C" char DAT_00307914[];

extern "C" void FUN_00102e38();
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(void *, void *);
extern "C" void FUN_000eee98(void *);

extern "C" void *FUN_000eed74(char *p) {
    int i;
    Ent *e;
    int off;
    FUN_00102e38();
    *(void **)p = &DAT_00307914;
    FUN_00104118(p, DAT_002d7084, 0);
    FUN_00103540(p, DAT_002d6c9c);
    FUN_001037c8(p, 0xffffff05);
    {
    void **pq = (void **)&DAT_002d7028;
    int j;
    for (j = 0; j < 1; j++) {}
    *(void **)(p + 0x58) = FUN_001039d8(p, *pq, 0);
    }
    i = 0;
    e = DAT_002d7054;
    off = 0;
    do {
        void *q = FUN_001026b8(*(void **)(p + 0x58 + e->idx * 4), e->name);
        *(void **)(p + 0x5c + off) = q;
        i = i + 1;
        off = off + 4;
        e->out = *(int *)((char *)q + 0x24);
        e++;
    } while (i < 4);
    FUN_000eee98(p);
    return p;
}
// near miss from lane ds7 (unreviewed)
