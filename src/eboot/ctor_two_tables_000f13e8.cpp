/* HSTMATCH module=EBOOT.BIN start=0x000f13e8 end=0x000f1560 symbol=FUN_000f13e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00307874;
extern int DAT_002d776c;
extern int DAT_002d6c9c;
extern int DAT_002d75d8;
extern int DAT_002d76ac;
extern int DAT_00338b44;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_00103480(void *);
extern "C" void FUN_000f1568(void *);

class Base2 {
public:
    virtual void m0();
    virtual void m1(int v);
};

#define PART_COUNT 4      /* layout parts loaded from the first table */
#define MODEL_COUNT 16    /* named models looked up through the second table */
#define DIGIT_BASE 10
#define INIT_ID (-251)
#define PART2_VALUE 385.0f

/* Second-table row: which part to search, the model name, and where the looked-up value is written back. */
struct Entry {
    int idx;
    int id;
    int out;
};

struct Self {
    void *vt;
    char pad[0x50];
    int part[PART_COUNT];     /* 0x54 */
    int model[MODEL_COUNT];   /* 0x64 */
    int digitA;               /* 0xa4 first config value modulo 10 */
    int digitB;               /* 0xa8 second config value modulo 10 */
    int unkac;                /* 0xac */
    int unkb0;                /* 0xb0 */
    int unkb4;                /* 0xb4 */
};

/* Constructor: loads the layout, resolves the four parts and sixteen named models through the two tables,
   then reads two digit values from the global config block and resets the state. */
extern "C" Self *FUN_000f13e8(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00307874;
    FUN_00104118(self, &DAT_002d776c, 0);
    FUN_00103540(self, *(float *)&DAT_002d6c9c);
    FUN_001037c8(self, INIT_ID);
    int i = 0;
    int *tab = (int *)&DAT_002d75d8;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x54) = FUN_001039d8(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < PART_COUNT);
    int k = 0;
    Entry *e = (Entry *)&DAT_002d76ac;
    int off2 = 0;
    do {
        int *n = (int *)FUN_001026b8(self->part[e->idx], e->id);
        *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
        e->out = n[9];
        k++;
        off2 += 4;
        e++;
    } while (k < MODEL_COUNT);
    int a = *(int *)(DAT_00338b44 + 0xb8);
    self->digitA = a % DIGIT_BASE;
    int b = *(int *)(DAT_00338b44 + 0xbc);
    self->digitB = b % DIGIT_BASE;
    ((Base2 *)self->part[2])->m1(1);
    self->unkac = 0;
    self->unkb0 = 0;
    self->unkb4 = 0;
    *(float *)(self->part[2] + 0x60) = PART2_VALUE;
    FUN_00103480(self);
    FUN_000f1568(self);
    return self;
}
