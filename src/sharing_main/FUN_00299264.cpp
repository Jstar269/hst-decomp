/* HSTMATCH module=hstp_trans_main.prx start=0x00299264 end=0x00299394 symbol=FUN_00299264 lang=c++ */
/* Clone of src/eboot/FUN_00287b30.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (tag a1 candidate used only for the pseudocode shape); matching idioms: Obj is 16-byte aligned through its Vec4 member, and the container call takes its position by const reference to an rvalue so the return slot and the position temp are call temporaries below the named record; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Iter { int p; };

struct Rec {
    int type;
    int n;
    int z;
    int a;
    int b;
    float f;
};

struct Mat34 { float m[12]; };

struct Obj {
    void *vptr;
    char base[12];
    Mat34 m;
    Vec4 pos;
    int a;
    float f;
    float g;
    int h;
    char c;
};

struct Game {
    char pad[0x164];
    void *list;
};

struct Self {
    char pad[100];
    char c100[4];
    char c104[4];
};

extern char DAT_002cc260[];
extern char DAT_003b0830[];
extern char DAT_003b0808[];
extern Game *DAT_003f344c;

extern "C" {
void FUN_000d24e4(Obj *);
void FUN_0005931c(Mat34 *, const void *);
int FUN_001d94ec(Game *, int, Vec4 *, void *);
void FUN_00068be4(void *, Obj *);
Iter FUN_0029ace0(void *, const int &, Rec *);
}

extern "C" void FUN_00299264(Self *self, int a, int b, int mode, float f)
{
    Rec rec;
    Obj o;
    Vec4 v;
    Vec4 tmp;

    if (mode < 1) {
        FUN_000d24e4(&o);
        o.vptr = DAT_003b0830;
        FUN_0005931c(&o.m, DAT_002cc260);
        o.f = 1.0f;
        o.g = 3000.0f;
        o.a = 0;
        o.h = 0;
        o.c = 0;
        if (FUN_001d94ec(DAT_003f344c, b, &v, &tmp) != 0) {
            o.pos.z = v.z;
            o.g = 3500.0f;
            o.pos.x = v.x;
            o.pos.y = v.y;
            o.pos.w = v.w;
            o.a = a;
            o.f = f;
            FUN_00068be4(DAT_003f344c->list, &o);
        }
        o.vptr = DAT_003b0808;
    } else {
        rec.type = 0x4f;
        rec.z = 0;
        rec.n = mode;
        rec.a = a;
        rec.b = b;
        rec.f = f;
        FUN_0029ace0(self->c100, (int)self + 0x68, &rec);
    }
}
