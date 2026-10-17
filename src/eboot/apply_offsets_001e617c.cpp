/* HSTMATCH module=EBOOT.BIN start=0x001e617c end=0x001e6224 symbol=FUN_001e617c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot-1 call on the object held at +0x1ab0, its fields +0xf8/+0x138 set (0x10d4a8 takes the object), then two
   widget offsets updated (+0x24 = +0x28 + b / c). Matching idiom: the sub-object addresses hp = &self->h and wp = &self->w1a5c are
   locals used twice each (declared at the call that precedes the second use), which keeps them in a saved register. Names provisional. */
extern "C" {
void FUN_000ffb3c(void *, int);
void FUN_0010d4a8(void *);
}
struct Obj1 {
    virtual void d0();
    virtual void m(int);
    char pad[0xf8 - 4];
    int f_f8;
    char pad2[0x138 - 0xfc];
    int f_138;
};
struct Rect { char pad[0x24]; int f24; int f28; };
struct Holder { int x; Obj1 *p; };
struct WRef { Rect *r; };
struct Self {
    char pad[0x1a5c];
    WRef w1a5c;
    char pad2[0x1a84 - 0x1a60];
    Rect *w1a84;
    char pad3[0x1aac - 0x1a88];
    Holder h;
};
extern "C" void FUN_001e617c(Self *self, int a, int b, int c)
{
    Holder *hp = &self->h;
    hp->p->m(0);
    Obj1 *o = hp->p;
    o->f_f8 = a;
    o->f_138 = 1;
    FUN_0010d4a8(o);
    Rect *r = self->w1a84;
    r->f24 = r->f28 + b;
    WRef *wp = &self->w1a5c;
    FUN_000ffb3c(wp->r, 0);
    Rect *w = wp->r;
    w->f24 = w->f28 + c;
}
