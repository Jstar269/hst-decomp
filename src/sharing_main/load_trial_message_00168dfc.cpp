/* HSTMATCH module=hstp_trans_main.prx start=0x00168dfc end=0x0016916c symbol=FUN_00168dfc lang=c++ data=0x00385ad0 */
/* Hand-written reconstruction (port of src/eboot/load_trial_message_0015c854.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
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
extern char DAT_00385bd0[];
void FUN_000143b0(char *buf, const char *fmt, ...);
void FUN_0001c684(void *a, int b, char *c);
void FUN_0001c73c(void *a);
void FUN_00166aa0(Obj *o, int n);
void FUN_00166c04(Obj *o);
void FUN_001c16b4(void *p, int n);
int FUN_00014934(char *cache, char *name);
void *FUN_00000bcc(unsigned n);
Res *FUN_000518d4(void *p);
void FUN_00051ad8(Res *r, char *name, int n);
void FUN_00051d38(float f, Res *r);
void FUN_000149a8(char *cache, char *name);
extern char DAT_003b7ebc[];
extern char DAT_003eaad8[];
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
            r = FUN_000518d4(r);
        *slot = r;
        FUN_00051ad8(r, buf, 0);
        FUN_00051d38(3000.0f, *slot);
        FUN_000149a8(cache, buf);
        v->x = 0;
        v->y = 0;
        v->z = 0;
        v->w = 1.0f;
    }
}

extern "C" void FUN_00168dfc(Obj *self, int n)
{
    const char *dir = "data/menu/";
    const char *names[9] = {
        "trial/trial_tutorial/usage", "trial/trial_loadmes/A04", "trial/trial_loadmes/A03",
        "trial/trial_loadmes/A00", "trial/trial_loadmes/A01", "trial/trial_loadmes/A02",
        "trial/trial_loadmes/A05", "trial/trial_sale/sale00", "trial/trial_loadmes/A06"};
    if (n != 0 && n != 7)
        FUN_00166aa0(self, 0);
    FUN_000143b0(self->buf370, "menu/loadmes/trial/loadmes_t%02d.xb", n);
    FUN_0001c684(DAT_003b7ebc, 1, self->buf370);
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
        FUN_00166c04(self);
        FUN_001c16b4(DAT_003eaad8, 0);
    }
    FUN_0001c73c(DAT_003b7ebc);
}
