/* HSTMATCH module=hstp_trans_main.prx start=0x001d6fa8 end=0x001d708c symbol=FUN_001d6fa8 lang=c++ */
/* Clone of src/eboot/closer_to_point_001c8b14.cpp (hstclone.py tag s10170158a1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the b-side difference vector is built by the inline Sub (copy-constructor copy, z/x/y load order), the a-side one by a direct
   FUN_0002245c call into a named local followed by `da = ra` (batched struct assignment); locals declared da, db, ra. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
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
    FUN_0002245c(&r, &a, &b);
    return r;
}

extern "C" bool FUN_001d6fa8(const Vec4 *p, VObj *a, VObj *b)
{
    Vec4 da;
    Vec4 db = Sub(*p, *b->GetPos());
    Vec4 ra;
    float lb = FUN_00022500(&db, &db);
    FUN_0002245c(&ra, p, a->GetPos());
    da = ra;
    float la = FUN_00022500(&da, &da);
    return la < lb;
}
