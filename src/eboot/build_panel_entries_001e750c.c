/* HSTMATCH module=EBOOT.BIN start=0x001e750c end=0x001e7700 symbol=FUN_001e750c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (near miss of lane ds1, origin hstgen tag a1) corrected by hand: entries as one `Entry e[10]` indexed `e[i + 4]`/`e[i + 7]`/`e[i + 1]` (gives retail's index+base+field-offset adds), mode dispatch as a switch in case order 0,1,2 through `Holder *h = &p->holder`, call result stored through a reloaded `Scene *o`; exact match verified; names and types await human review. */
extern void FUN_000ffb3c();
extern void FUN_000ffc70();
extern void FUN_00102c54();
extern void FUN_0010b980();
extern void FUN_0010d4a8();
extern int FUN_001ee200();
extern int FUN_001fea10();

typedef struct {
    int f0;
    int pad[3];
    int f10;
} Entry;

typedef struct {
    Entry e[10];
} Sub;

typedef struct Scene_s Scene;

typedef struct {
    int unused;
    Scene *obj;
    int unused2;
} Holder;

typedef struct {
    unsigned char pad0[0x21ec];
    Sub sub;
    Holder holder;
    int arg22c0;
    unsigned char pad1[0x94];
    int n2358;
} Big;

struct Scene_s {
    unsigned char pad0[100];
    float f64;
    unsigned char pad1[0x90];
    int f_f8;
    unsigned char pad2[0x3c];
    int f_138;
};

void FUN_001e750c(Big *p)
{
    Holder *h;

    int mode = *(int *)((char *)FUN_001ee200() + 0x8178);
    FUN_001ee200();
    FUN_0010b980(p->arg22c0, mode, 0);

    for (int i = 0; i < 3; i++) {
        Entry *a = &p->sub.e[i + 4];
        Entry *b = &p->sub.e[i + 7];
        Entry *c = &p->sub.e[i + 1];
        if (mode == i) {
            FUN_000ffb3c(a->f0, 0);
            FUN_000ffb3c(b->f0, 1);
            FUN_000ffc70(c->f0, 0x80808080);
        } else {
            FUN_000ffb3c(a->f0, 1);
            FUN_000ffb3c(b->f0, 0);
            FUN_000ffc70(c->f0, c->f10);
        }
    }
    h = &p->holder;
    switch (mode) {
    case 0:
        h->obj->f64 = (float)(p->n2358 + 9);
        FUN_00102c54(h->obj);
        {
            int v = FUN_001fea10(0x11, 0x12, 6);
            Scene *o = h->obj;
            o->f_f8 = v;
            o->f_138 = 1;
            FUN_0010d4a8(o);
        }
        break;
    case 1:
        h->obj->f64 = (float)p->n2358;
        FUN_00102c54(h->obj);
        {
            int v = FUN_001fea10(0x11, 0x12, 7);
            Scene *o = h->obj;
            o->f_f8 = v;
            o->f_138 = 1;
            FUN_0010d4a8(o);
        }
        break;
    case 2:
        h->obj->f64 = (float)(p->n2358 + 9);
        FUN_00102c54(h->obj);
        {
            int v = FUN_001fea10(0x11, 0x12, 8);
            Scene *o = h->obj;
            o->f_f8 = v;
            o->f_138 = 1;
            FUN_0010d4a8(o);
        }
        break;
    }
}
