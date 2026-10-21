/* HSTMATCH module=EBOOT.BIN start=0x00244188 end=0x00244308 symbol=FUN_00244188 lang=c++ */
struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct Globals {
    char pad[0x1d0];
    Vec4 f1d0;
};

struct Ctx {
    char pad[0x8c];
    int f8c;
};

extern Globals *DAT_003313c4;
extern Ctx *DAT_00340284;
extern "C" void FUN_00055724(void *, void *);
extern "C" Vec4 FUN_00022434(Vec4 *, Vec4 *);
extern "C" float FUN_00055768(void *);
extern "C" float FUN_000224d8(Vec4 *, Vec4 *);
extern "C" void FUN_0005f1e8(void *, int);

struct Self {
    char pad0[0x3c];
    unsigned char f3c;
    int f40;
    char pad1[0x10];
    unsigned char f54;
    char pad2[0xb];
    Vec4 f60;
    char pad3[0x1f0];
    int f260;
    char pad4[0x48];
    int f2ac;
};

extern "C" void FUN_00244188(Self *self) {
    if (self->f3c == 0) return;
    if ((unsigned int)(self->f2ac - 4) < 2) {
        if (self->f40 == 1) return;
    }
    if (self->f40 == 1) {
        int s = self->f260;
        if (s == 10 || s == 9 || s == 7 || s == 44) return;
    }
    if (self->f54 == 0) return;
    Vec4 q;
    FUN_00055724(&q, &self->f60);
    Vec4 c;
    c.x = DAT_003313c4->f1d0.x;
    c.y = DAT_003313c4->f1d0.y;
    c.z = DAT_003313c4->f1d0.z;
    c.w = DAT_003313c4->f1d0.w;
    Vec4 v = FUN_00022434(&c, &q);
    float ang = FUN_00055768(&self->f60);
    float dist = FUN_000224d8(&v, &v);
    if (DAT_00340284->f8c == 2) {
        float d = 3.0f + ang;
        if (d * d < dist) FUN_0005f1e8(&self->f60, 0);
    } else {
        FUN_0005f1e8(&self->f60, 0);
    }
}
// NEAR 7 words (96/96). Everything matches except one scheduling block: the struct-return copy at
// 0x244264..0x244280. Retail copies the 16-byte return slot with `lwc1 f0,40; lwc1 f2,32; lwc1 f1,36;
// swc1 f0,56; lwc1 f0,44; swc1 f2,48; swc1 f1,52` (z,x,y then w); MWCC always emits x,y,z then w.
// Ruled out: returning Vec4 by value and copying member-wise (adds a fifth temp, frame 112), declaring
// FUN_00022434 as returning Vec4& (worse), and swapping the two if arms.
// Useful (kept): a 16-byte global->local copy matches retail only when written member-wise
// (c.x = g->f1d0.x; ...) - one lwc1/swc1 pair per field, the struct assignment batches the loads.
// near miss from lane ds10 (unreviewed)
