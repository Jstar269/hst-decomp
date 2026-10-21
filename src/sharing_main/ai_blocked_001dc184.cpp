/* HSTMATCH module=hstp_trans_main.prx start=0x001dc184 end=0x001dc378 symbol=FUN_001dc184 lang=c++ */
/* Clone of src/eboot/ai_blocked_001cdaa8.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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

extern World *DAT_003f3450;
extern float DAT_00391f2c;
extern float DAT_00391f30;

extern "C" {
int FUN_001dc504(Ent *);
int FUN_001dc48c(Self *, Ent *);
void FUN_00054e34(Vec4 *, const Vec4 *, Vec4 *);
void FUN_000c77a0(Vec4 *, Vec4 *);
float FUN_001dc484(Vec4 *, Vec4 *);
float FUN_001dc444(float *, float *, float *);
float FUN_0000c5d4(float);
int FUN_001dc3f0(Ent *);
int FUN_001dc38c(Ent *);
Ent *FUN_001dc3e8(Ent *);
Ent *FUN_001dc384(Ent *);
int FUN_001dc3b8(Ent *, int);
int FUN_00132ae0(int);
int FUN_00132c90(int);
Vec4 *FUN_0009573c(Ent *);
Vec4 *FUN_001dc378(Ent *);

bool FUN_001dc184(Self *self, Ent **pp)
{
    bool r;
    Ent *e = *pp;
    if (FUN_001dc504(e) != 0 && FUN_001dc48c(self, e) != 0) {
        Ent *g = DAT_003f3450;
        if (e != g) {
            Vec4 v;
            Vec4 a;
            FUN_00054e34(&a, e->GetPos(), &self->f30);
            FUN_000c77a0(&v, &a);
            float d = FUN_001dc484(&self->f20, &v);
            float c = FUN_0000c5d4(FUN_001dc444(&d, &DAT_00391f2c, &DAT_00391f30));
            if (c < self->f40) {
                if (FUN_001dc3f0(e) != 0) {
                    Ent *u = FUN_001dc3e8(e);
                    if (FUN_00132ae0(FUN_001dc3b8(u, 0)) == 0 && FUN_00132c90(FUN_001dc3b8(u, 0)) == 0) {
                        d = FUN_001dc484(FUN_0009573c(u) + 2, &self->f20);
                        if (d >= 0.0f) {
                            r = false;
                            goto end;
                        }
                    }
                } else if (FUN_001dc38c(e) != 0) {
                    Ent *u = FUN_001dc384(e);
                    d = FUN_001dc484(FUN_001dc378(u) + 2, &self->f20);
                    if (d >= 0.0f) {
                        r = false;
                        goto end;
                    }
                    d = FUN_001dc484(FUN_001dc378(u) + 2, &v);
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
