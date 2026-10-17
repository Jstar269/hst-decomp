/* HSTMATCH module=EBOOT.BIN start=0x001c8b14 end=0x001c8bf8 symbol=FUN_001c8b14 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the b-side difference vector is built by the inline Sub (copy-constructor copy, z/x/y load order), the a-side one by a direct
   FUN_00022434 call into a named local followed by `da = ra` (batched struct assignment); locals declared da, db, ra. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
}

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual const Vec4 *GetPos();
};

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

extern "C" bool FUN_001c8b14(const Vec4 *p, VObj *a, VObj *b)
{
    Vec4 da;
    Vec4 db = Sub(*p, *b->GetPos());
    Vec4 ra;
    float lb = FUN_000224d8(&db, &db);
    FUN_00022434(&ra, p, a->GetPos());
    da = ra;
    float la = FUN_000224d8(&da, &da);
    return la < lb;
}
