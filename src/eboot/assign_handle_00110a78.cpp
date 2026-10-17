/* HSTMATCH module=EBOOT.BIN start=0x00110a78 end=0x00110bb4 symbol=FUN_00110a78 lang=c++ */
/* Clone of src/sharing_main/assign_handle_0011988c.cpp (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
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

extern Glob *DAT_0034176c;
extern float DAT_002d92b0;
extern "C" int FUN_00014934(int);
extern "C" void FUN_0010d4a8(Child *);
extern "C" int FUN_0016bc70(void);
extern "C" void FUN_00197458(Glob *, float, float);
extern "C" int FUN_001987fc(Glob *, int, int, int);

inline const float &Max(const float &a, const float &b) { return (a < b) ? b : a; }

extern "C" void FUN_00110a78(Obj *self, int h, int force)
{
    if (force != 0 || FUN_00014934(self->f54) != 0) {
        self->f54 = h;
        if (h != 0) {
            Child *c = self->f58;
            c->fF8 = h;
            c->f138 = 0;
            FUN_0010d4a8(c);
            c = self->f5c;
            c->fF8 = self->f54;
            c->f138 = 0;
            FUN_0010d4a8(c);
            Glob *g = DAT_0034176c;
            g->f70 = 1.0f;
            g->f74 = 0.0f;
            FUN_00197458(DAT_0034176c, 1.0f, 1.0f);
            DAT_0034176c->f84 = 0;
            int n = FUN_001987fc(DAT_0034176c, self->f54, 0, 0);
            self->f78 = (float)n;
            self->f74 = Max((float)n + 64.0f, DAT_002d92b0);
            self->f6c = 480.0f;
            self->f70 = self->f74 + 480.0f;
        }
        if (FUN_0016bc70() != 0)
            self->f68 = 10;
        else
            self->f68 = self->f64;
        self->f60 = 0;
    }
}
