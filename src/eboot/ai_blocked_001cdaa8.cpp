/* HSTMATCH module=EBOOT.BIN start=0x001cdaa8 end=0x001cdc9c symbol=FUN_001cdaa8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

class Ent {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual const Vec4 *GetPos();
};

struct Base0 { char pad[0xe0]; };
struct World : Base0, Ent {};

struct Self {
    char pad0[0x20];
    Vec4 f20;
    Vec4 f30;
    float f40;
};

extern World *DAT_0034a118;
extern float DAT_002ea2d4;
extern float DAT_002ea2d8;

extern "C" {
int FUN_001cde28(Ent *);
int FUN_001cddb0(Self *, Ent *);
void FUN_000542e8(Vec4 *, const Vec4 *, Vec4 *);
void FUN_000c3f38(Vec4 *, Vec4 *);
float FUN_001cdda8(Vec4 *, Vec4 *);
float FUN_001cdd68(float *, float *, float *);
float FUN_0000c5bc(float);
int FUN_001cdd14(Ent *);
int FUN_001cdcb0(Ent *);
Ent *FUN_001cdd0c(Ent *);
Ent *FUN_001cdca8(Ent *);
int FUN_001cdcdc(Ent *, int);
int FUN_00127870(int);
int FUN_00127a20(int);
Vec4 *FUN_00093818(Ent *);
Vec4 *FUN_001cdc9c(Ent *);

bool FUN_001cdaa8(Self *self, Ent **pp)
{
    bool r;
    Ent *e = *pp;
    if (FUN_001cde28(e) != 0 && FUN_001cddb0(self, e) != 0) {
        Ent *g = DAT_0034a118;
        if (e != g) {
            Vec4 v;
            Vec4 a;
            FUN_000542e8(&a, e->GetPos(), &self->f30);
            FUN_000c3f38(&v, &a);
            float d = FUN_001cdda8(&self->f20, &v);
            float c = FUN_0000c5bc(FUN_001cdd68(&d, &DAT_002ea2d4, &DAT_002ea2d8));
            if (c < self->f40) {
                if (FUN_001cdd14(e) != 0) {
                    Ent *u = FUN_001cdd0c(e);
                    if (FUN_00127870(FUN_001cdcdc(u, 0)) == 0 && FUN_00127a20(FUN_001cdcdc(u, 0)) == 0) {
                        d = FUN_001cdda8(FUN_00093818(u) + 2, &self->f20);
                        if (d >= 0.0f) {
                            r = false;
                            goto end;
                        }
                    }
                } else if (FUN_001cdcb0(e) != 0) {
                    Ent *u = FUN_001cdca8(e);
                    d = FUN_001cdda8(FUN_001cdc9c(u) + 2, &self->f20);
                    if (d >= 0.0f) {
                        r = false;
                        goto end;
                    }
                    d = FUN_001cdda8(FUN_001cdc9c(u) + 2, &v);
                    if (d >= 0.0f) {
                        r = false;
                        goto end;
                    }
                }
                r = true;
                goto end;
            }
        }
    }
    r = false;
end:
    return !r;
}
}
