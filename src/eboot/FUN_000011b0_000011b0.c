/* HSTMATCH module=EBOOT.BIN start=0x000011b0 end=0x00001314 symbol=FUN_000011b0 lang=c99 */
/* Clone of src/sharing_main/FUN_000011b0.c (hstclone.py tag c042120): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: unsigned char read pointer for the 32-bit little-endian load, redundant first store of info.b before the ternary; names and types await human review. */
struct Ctx {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};

struct Info {
    int a;
    int b;
};

struct Rec {
    char *a;
    char *b;
    int c;
    char *d;
    int e;
};

struct Obj {
    char *f0;
    char *f4;
    int f8;
    int fc;
    int f10;
    int f14;
    unsigned f18;
};

extern void FUN_00000ec0(void);
extern void *FUN_00001040(void *, int *);
extern void *FUN_000010dc(void *, int *);
extern unsigned char *FUN_00001314(struct Obj *, struct Ctx *, struct Info *);
extern int FUN_0000180c(struct Obj *, struct Ctx *);
extern void FUN_00001960(struct Obj *, struct Ctx *, void *);
extern void FUN_00002408(int, struct Ctx *);
extern void FUN_000025a8(struct Obj *, struct Ctx *, int);
extern void FUN_000027d4(struct Obj *, struct Ctx *);

void FUN_000011b0(struct Obj *self)
{
    struct Ctx ctx;
    int delta;
    int len;
    struct Info info;
    int v;
    unsigned char *rec;
    struct Rec *r;
    void *p;
    unsigned char *q;
    int off;

    FUN_00002408(self->f10, &ctx);
    if (ctx.b == 0) {
        FUN_00000ec0();
    }
    FUN_000027d4(self, &ctx);
    if (self->f0 == 0) {
        self->fc = FUN_0000180c(self, &ctx);
    } else {
        self->fc = 0;
    }
    rec = FUN_00001314(self, &ctx, &info);
    {
        unsigned char *pp = rec + 1;
        v = pp[0] | (pp[1] << 8) | (pp[2] << 16) | (pp[3] << 24);
    }
    q = rec + 5;
    info.b = v;
    info.b = v != 0 ? v : 0;
    p = FUN_00001040(q, &len);
    FUN_000010dc(p, &delta);
    FUN_00001960(self, &ctx, rec);
    off = info.a;
    r = (struct Rec *)(self->f18 + delta);
    r->a = self->f4;
    r->b = self->f0;
    r->c = self->f8;
    if (*self->f0 == '*') {
        r->d = (char *)&r->e;
        r->e = *(int *)self->f4 + off;
    } else {
        r->d = self->f4 + off;
    }
    FUN_000025a8(self, &ctx, ctx.a + len);
}
