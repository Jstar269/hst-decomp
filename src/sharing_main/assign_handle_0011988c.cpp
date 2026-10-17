/* HSTMATCH module=hstp_trans_main.prx start=0x0011988c end=0x001199c8 symbol=FUN_0011988c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Max() is the std::max shape (returns a const reference, the first argument is a stack temporary), which gives retail's address select between the temporary and the global; the cached Child/Glob pointers are the reads retail shares. */
struct Child {
    char pad0[0xf8];
    int fF8;
    char pad1[0x3c];
    int f138;
};
struct Glob {
    char pad0[0x70];
    float f70;
    float f74;
    char pad1[0xc];
    int f84;
};
struct Obj {
    char pad0[0x54];
    int f54;
    Child *f58;
    Child *f5c;
    int f60;
    int f64;
    int f68;
    float f6c;
    float f70;
    float f74;
    float f78;
};

extern Glob *DAT_003eaaac;
extern float DAT_003800fc;
extern "C" int FUN_00014934(int);
extern "C" void FUN_00113a50(Child *);
extern "C" int FUN_00177e98(void);
extern "C" void FUN_001a3da8(Glob *, float, float);
extern "C" int FUN_001a517c(Glob *, int, int, int);

inline const float &Max(const float &a, const float &b) { return (a < b) ? b : a; }

extern "C" void FUN_0011988c(Obj *self, int h, int force)
{
    if (force != 0 || FUN_00014934(self->f54) != 0) {
        self->f54 = h;
        if (h != 0) {
            Child *c = self->f58;
            c->fF8 = h;
            c->f138 = 0;
            FUN_00113a50(c);
            c = self->f5c;
            c->fF8 = self->f54;
            c->f138 = 0;
            FUN_00113a50(c);
            Glob *g = DAT_003eaaac;
            g->f70 = 1.0f;
            g->f74 = 0.0f;
            FUN_001a3da8(DAT_003eaaac, 1.0f, 1.0f);
            DAT_003eaaac->f84 = 0;
            int n = FUN_001a517c(DAT_003eaaac, self->f54, 0, 0);
            self->f78 = (float)n;
            self->f74 = Max((float)n + 64.0f, DAT_003800fc);
            self->f6c = 480.0f;
            self->f70 = self->f74 + 480.0f;
        }
        if (FUN_00177e98() != 0)
            self->f68 = 10;
        else
            self->f68 = self->f64;
        self->f60 = 0;
    }
}
