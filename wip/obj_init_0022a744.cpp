/* HSTMATCH module=EBOOT.BIN start=0x0022a744 end=0x0022a930 symbol=FUN_0022a744 lang=c++ */

struct Entry {
    int f0;
    int f4;
    short f8;
    short fa;
    short fc;
    char fe;
    char ff;
    float m[8];
};

struct Obj {
    Entry entries[48];
    char pad[0x10]; // 2304 to 2320
    int t0;         // 2320
    int t1;         // 2324
    int t2;         // 2328
    int t3;         // 2332
    int t4;         // 2336
    int t5;         // 2340
    int t6;         // 2344
    int t7;         // 2348
    int t8;         // 2352
    int t9;         // 2356
    int t10;        // 2360
    char b0;        // 2364
    char b1;        // 2365
    char b2;        // 2366
    char b3;        // 2367
    char b4;        // 2368
};

extern "C" {
    extern float DAT_002bc440;
    extern float DAT_002bc444;
    extern float DAT_002bc448;
    extern float DAT_002bc44c;
    extern float DAT_002bc430;
    extern float DAT_002bc434;
    extern float DAT_002bc438;
    extern float DAT_002bc43c;

    void FUN_000114c0(void *dst, int val, unsigned int size);
}

extern "C" Obj *FUN_0022a744(Obj *self) {
    Entry *cur = self->entries;
    Entry *end = self->entries + 48;
    do {
        cur->f0 = -1;
        cur->f4 = -1;
        cur->f8 = -1;
        cur->fa = -1;
        cur->fc = 0;
        cur->fe = 1;
        cur->ff = 0;
        cur->m[0] = DAT_002bc440;
        cur->m[1] = DAT_002bc444;
        cur->m[2] = DAT_002bc448;
        cur->m[3] = DAT_002bc44c;
        cur->m[4] = DAT_002bc430;
        cur->m[5] = DAT_002bc434;
        cur->m[6] = DAT_002bc438;
        cur->m[7] = DAT_002bc43c;
        cur++;
    } while (cur < end);

    FUN_000114c0(self, 0, 0x1250);

    for (unsigned int i = 0; i < 48; i++) {
        volatile float u[8];
        u[0] = DAT_002bc440;
        u[1] = DAT_002bc444;
        u[2] = DAT_002bc448;
        u[3] = DAT_002bc44c;
        u[4] = DAT_002bc430;
        u[5] = DAT_002bc434;
        u[6] = DAT_002bc438;
        u[7] = DAT_002bc43c;

        self->entries[i].f0 = -1;
        self->entries[i].f4 = -1;
        self->entries[i].f8 = -1;
        self->entries[i].fa = -1;
        self->entries[i].fc = 0;
        self->entries[i].fe = 1;
        self->entries[i].ff = 0;
        self->entries[i].m[0] = u[0];
        self->entries[i].m[1] = u[1];
        self->entries[i].m[2] = u[2];
        self->entries[i].m[3] = u[3];
        self->entries[i].m[4] = u[4];
        self->entries[i].m[5] = u[5];
        self->entries[i].m[6] = u[6];
        self->entries[i].m[7] = u[7];
    }

    self->t0 = -1;
    self->t1 = -1;
    self->t2 = 0;
    self->t3 = -1;
    self->t4 = -1;
    self->t5 = 0;
    self->t6 = -1;
    self->t7 = 0;
    self->t8 = -1;
    self->t9 = 0;
    self->t10 = 0;
    self->b0 = 0;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;

    return self;
}
// near miss from lane ag4 (unreviewed)
