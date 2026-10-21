/* HSTMATCH module=EBOOT.BIN start=0x0015c854 end=0x0015cbc4 symbol=FUN_0015c854 lang=c++ data=0x002de514 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the nine message names are a local `const char *names[9]` initialiser (its strings and the pointer table are the anonymous .data placed with data=0x002de514), the directory string is a local pointer kept in s0 for the "%s%s" format, the reload helper is `static inline` with the merged-store form `r = alloc; if (r) r = ctor(r); *slot = r;`; names (from the message strings) and types await human review. */
struct Res {
    virtual ~Res();
};

struct Vec4 { float x, y, z, w; };

struct Obj {
    char pad0[0x34];
    Res *f34;
    Res *f38;
    char pad3c[4];
    Vec4 v40;
    Vec4 v50;
    char pad60[0x70 - 0x60];
    char cache70[0x100];
    char cache170[0x200];
    char buf370[1];
};

extern "C" {
extern char DAT_002de614[];
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001cad0(void *a, int b, char *c);
void FUN_0001cb88(void *a);
void FUN_0015a4c8(Obj *o, int n);
void FUN_0015a62c(Obj *o);
void FUN_001b3378(void *p, int n);
int FUN_00014934(char *cache, char *name);
void *FUN_00000bcc(unsigned n);
Res *FUN_00050fc0(void *p);
void FUN_000511c4(Res *r, char *name, int n);
void FUN_00051398(float f, Res *r);
void FUN_000149a8(char *cache, char *name);
extern char DAT_0030ebf4[];
extern char DAT_0034179c[];
}

static inline void Reload(Res **slot, char *cache, char *buf, Vec4 *v)
{
    if (*slot == 0 || FUN_00014934(cache, buf) != 0) {
        if (*slot != 0) {
            delete *slot;
            *slot = 0;
        }
        Res *r = (Res *)FUN_00000bcc(0x48);
        if (r != 0)
            r = FUN_00050fc0(r);
        *slot = r;
        FUN_000511c4(r, buf, 0);
        FUN_00051398(3000.0f, *slot);
        FUN_000149a8(cache, buf);
        v->x = 0;
        v->y = 0;
        v->z = 0;
        v->w = 1.0f;
    }
}

extern "C" void FUN_0015c854(Obj *self, int n)
{
    const char *dir = "data/menu/";
    const char *names[9] = {
        "trial/trial_tutorial/usage", "trial/trial_loadmes/A04", "trial/trial_loadmes/A03",
        "trial/trial_loadmes/A00", "trial/trial_loadmes/A01", "trial/trial_loadmes/A02",
        "trial/trial_loadmes/A05", "trial/trial_sale/sale00", "trial/trial_loadmes/A06"};
    if (n != 0 && n != 7)
        FUN_0015a4c8(self, 0);
    FUN_000143b0(self->buf370, "menu/loadmes/trial/loadmes_t%02d.xb", n);
    FUN_0001cad0(DAT_0030ebf4, 1, self->buf370);
    if (n == 0) {
        FUN_000143b0(self->buf370, "data/menu/trial/trial_tutorial/tutorial_bg");
        Reload(&self->f34, self->cache70, self->buf370, &self->v40);
    } else if (n == 7) {
        FUN_000143b0(self->buf370, "data/menu/trial/trial_sale/salebg");
        Reload(&self->f34, self->cache70, self->buf370, &self->v40);
    }
    FUN_000143b0(self->buf370, "%s%s", dir, names[n]);
    Reload(&self->f38, self->cache170, self->buf370, &self->v50);
    if (n == 7) {
        FUN_0015a62c(self);
        FUN_001b3378(DAT_0034179c, 0);
    }
    FUN_0001cb88(DAT_0030ebf4);
}
