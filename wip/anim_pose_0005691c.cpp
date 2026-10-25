/* HSTMATCH module=EBOOT.BIN start=0x0005691c end=0x00056b98 symbol=FUN_0005691c lang=c++ */
struct V4 {
    float x, y, z, w;
};

struct M4 {
    V4 r0, r1, r2, r3;
};

struct Clip {
    int data;
    int bones;
    int m8;
    M4 *baked;
    M4 *Frame(int f) { return &baked[f * bones]; }
};

struct Src {
    int *h;
};

struct Anim {
    Clip *clip;
    unsigned short *remap;
    char pad8;
    unsigned char mirror;
    short boneA;
    short boneB;
};

extern "C" {
extern char DAT_0032b300[];
extern M4 DAT_0032b280;
extern M4 DAT_0032b2c0;
void FUN_00030ed0(int, void *, int, Src *, float, float);
void FUN_00030948(int, void *, float);
void FUN_00031130(void *, M4 *, unsigned short *);
void FUN_00022570(M4 *, M4 *, const M4 *);
}

extern "C" void FUN_0005691c(Anim *self, M4 *out, Src *src, float t, float t2)
{
    Clip *c = self->clip;
    if (c->baked != 0) {
        M4 *m = c->Frame((int)t);
        unsigned short *map = self->remap;
        for (int i = 0; i < c->bones; i++) {
            if (map[1] != 0xffff)
                out[map[1]] = *m;
            map++;
            m++;
        }
    } else {
        if (src != 0)
            FUN_00030ed0(*src->h, DAT_0032b300, c->data, src, t2 * (1.0f / 30.0f), t * (1.0f / 30.0f));
        else
            FUN_00030948(c->data, DAT_0032b300, t * (1.0f / 30.0f));
        FUN_00031130(DAT_0032b300, out, self->remap);
    }
    if (self->mirror) {
        int n = self->clip->bones;
        for (int i = 0; i < n; i++) {
            unsigned short idx = self->remap[i + 1];
            if (idx != 0xffff) {
                M4 *m = &out[idx];
                m->r0.y *= -1.0f;
                m->r0.z *= -1.0f;
                m->r1.x *= -1.0f;
                m->r2.x *= -1.0f;
                m->r3.x *= -1.0f;
                if (idx == self->boneA)
                    FUN_00022570(m, m, &DAT_0032b280);
                else if (idx == self->boneB)
                    FUN_00022570(m, m, &DAT_0032b2c0);
            }
        }
    }
}
// NEAR (2 words short): retail reloads c->baked (lw 12(t0)) after the null test and parks src in a1 (move a1,a2 then
// move a3,a1) where MWCC CSEs the load and keeps src in a3; rest of body matches once shifted. Tried &baked[], Frame() inline,
// union int/pointer test, whole-branch inline. ~6 compiles.
// near miss from lane ol2 (unreviewed)
