/* HSTMATCH module=hstp_trans_main.prx start=0x001a3db4 end=0x001a3e54 symbol=FUN_001a3db4 lang=c++ */
/* Clone of src/eboot/FUN_00197464.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
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
    extern void FUN_000430e8(void *, void *);
}

extern "C" void FUN_001a3db4(Obj *p, const V4 *src)
{
    V4 v = *src;
    p->v = v;
    p->t.x = v.x * p->s.x;
    p->t.y = v.y * p->s.y;
    p->t.z = v.z * p->s.z;
    p->t.w = v.w * p->s.w;
    FUN_000430e8(p->f0, &p->t);
}
