/* HSTMATCH module=EBOOT.BIN start=0x00197464 end=0x00197504 symbol=FUN_00197464 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Hand-written from the disassembly; exact match verified. Names and types await human review. */
/* Matching idiom: a 16-byte `V4 v = *src;` local stages the vector through sp+16..31 (frame 32) for
   both the memberwise p->v copy and the four products into p->t. */
struct V4 {
    float x, y, z, w;
};

struct Obj {
    void *f0;       /* 0x00 */
    char pad0[0x10 - 4];
    V4 v;           /* 0x10 */
    V4 s;           /* 0x20 */
    V4 t;           /* 0x30 */
};

extern "C" {
    extern void FUN_00043004(void *, void *);
}

extern "C" void FUN_00197464(Obj *p, const V4 *src)
{
    V4 v = *src;
    p->v = v;
    p->t.x = v.x * p->s.x;
    p->t.y = v.y * p->s.y;
    p->t.z = v.z * p->s.z;
    p->t.w = v.w * p->s.w;
    FUN_00043004(p->f0, &p->t);
}
