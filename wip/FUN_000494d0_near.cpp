/* HSTMATCH module=EBOOT.BIN start=0x000494d0 end=0x00049748 symbol=FUN_000494d0 lang=c++ */
typedef struct P8C {
    char pad[8];
    void *handle;               /* +8 */
} P8C;

typedef struct Obj {
    char pad0[0x8c];
    P8C *p8c;                   /* 0x8c */
    char pad90[0xf4 - 0x90];
    int *pf4;                   /* 0xf4 */
} Obj;

typedef struct Self {
    Obj *obj;                   /* 0x00 */
    char pad4[4];
    void *f08;                  /* 0x08 */
    int f0c;                    /* 0x0c */
    int f10;                    /* 0x10 */
    int f14;                    /* 0x14 */
    int f18;                    /* 0x18 */
    int f1c;                    /* 0x1c */
    float f20;                  /* 0x20 */
} Self;

typedef struct Res {
    char pad0[0xc];
    int f0c;
    char pad10[0x52 - 0x10];
    signed char f52;
} Res;

extern "C" {
void FUN_000143b0(char *, char *, void *);
int FUN_0002fe80(void *, char *);
int FUN_00057b58(Obj *, int, int, float);
void FUN_00049748(char *);
void FUN_00058fc0(Obj *, int);
}

extern char *DAT_002d07b8[];
extern char DAT_002d07f4[];
extern Res *DAT_00331b84;
extern Res *DAT_00331b88;

static inline void SetName(Self *s, void *n) { s->f08 = n; }

static inline int NonZero(int *p) { return p != 0 ? *p : 0; }

static inline int Lookup(Obj *obj, char *buf)
{
    void *h = obj->p8c->handle;
    return h != 0 ? FUN_0002fe80(h, buf) : -1;
}

static inline void Reset(Res *r)
{
    r->f0c = 0;
    r->f52 = 0;
}

extern "C" int FUN_000494d0(Self *self, int flags, void *name, float f)
{
    char buf[64];

    self->f08 = (void *)-1;
    self->f0c = -1;
    self->f10 = -1;
    self->f14 = -1;
    self->f18 = -1;
    self->f1c = -1;
    self->f20 = 65534.0f;

    if (flags < 0) {
        Reset(DAT_00331b84);
        Reset(DAT_00331b88);
    }

    if (self->obj->p8c != 0) {
        FUN_00057b58(self->obj, 0, flags, 0.0f);

        if (NonZero(self->obj->pf4) != 0) {
            for (int i = 0; i < 2; i++) {
                FUN_000143b0(buf, DAT_002d07b8[i], name);
                self->f0c = Lookup(self->obj, buf);
                if (self->f0c >= 0)
                    break;
            }
            for (int i = 0; i < 2; i++) {
                FUN_000143b0(buf, DAT_002d07b8[i + 2], name);
                self->f10 = Lookup(self->obj, buf);
                if (self->f10 >= 0)
                    break;
            }
            for (int i = 0; i < 2; i++) {
                FUN_000143b0(buf, DAT_002d07b8[i + 4], name);
                self->f14 = Lookup(self->obj, buf);
                if (self->f14 >= 0)
                    break;
            }

            if (self->f0c >= 0 && self->f10 >= 0 && self->f14 >= 0) {
                FUN_000143b0(buf, DAT_002d07b8[9], name);
                SetName(self, name);
                self->f18 = Lookup(self->obj, buf);
                FUN_000143b0(buf, DAT_002d07b8[14], name);
                self->f1c = Lookup(self->obj, buf);
            } else {
                FUN_00049748(DAT_002d07f4);
            }

            self->f20 = f;
            FUN_00058fc0(self->obj, -1);
        }
    }
    return (int)self->f08 >= 0;
}
// NEAR 158/158 words, 2 differ at 0x4969c/0x496a0: the first success-block call's `move a2,s0` sits in the
// jal delay slot here, while retail has it one word earlier and the `self->f08 = name` store in the delay slot.
// Tried and ruled out (each re-checked with hstdiff): store statement before the call (5 differ, store lands
// before the `lui`), store after the f18 lookup (11 differ), pointer-typed f08 field, char*/void* parameter
// types, and routing the store through a `static inline SetName()` helper - all leave the same 2-word swap.
// Everything else in the function (the three 2-try lookup loops, the NonZero() ternary that reproduces the
// materialised `beqzl v0,L; move v0,zero; lw v0,0(v0)` chain, and the success-first if/else layout) is exact.
// near miss from lane dsn2 (unreviewed)
