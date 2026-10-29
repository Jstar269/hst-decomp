/* HSTMATCH module=EBOOT.BIN start=0x00287b30 end=0x00287c60 symbol=FUN_00287b30 lang=c++ */
/* Hand-written reconstruction from the disassembly (tag a1 candidate used only for the pseudocode shape); matching idioms: Fx is 16-byte aligned through its Vec4 member, and the container call takes its position by const reference to an rvalue so the return slot and the position temp are call temporaries below the named record; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Iter { int p; };

/* 24-byte request record queued when the delay is positive. */
struct Rec {
    int type;
    int count;
    int unk8;
    int a;
    int b;
    float f;
};

struct Mat34 { float m[12]; };

/* Effect object built on the stack (same layout as the one in the neighbouring effect-spawn source). */
struct Fx {
    void *vptr;
    char base[12];
    Mat34 m;
    Vec4 pos;
    int unk50;
    float unk54;
    float unk58;
    int unk5c;
    char unk60;
};

struct World {
    char pad[0x164];
    void *effects;      /* 0x164 list the effect is submitted to */
};

struct Self {
    char pad[100];
    char queueCount[4]; /* 0x64 request list: element count, then the sentinel links at 0x68 */
    char queueLinks[4];
};

enum { REQ_TYPE_4F = 0x4f }; /* request kind, named by its hex value */

extern char DAT_002bc410[];
extern char DAT_00307564[];
extern char DAT_0030753c[];
extern World *DAT_0034a114;

extern "C" {
void FUN_000ce8e8(Fx *);
void FUN_00058694(Mat34 *, const void *);
int FUN_001caee4(World *, int, Vec4 *, void *);
void FUN_00067790(void *, Fx *);
Iter FUN_00289544(void *, const int &, Rec *);
}

/* With delay below 1 build an effect object at the position looked up for index and submit it; otherwise queue a request. */
extern "C" void FUN_00287b30(Self *self, int a, int index, int delay, float f)
{
    Rec rec;
    Fx fx;
    Vec4 pos;
    Vec4 scratch;

    if (delay < 1) {
        FUN_000ce8e8(&fx);
        fx.vptr = DAT_00307564;
        FUN_00058694(&fx.m, DAT_002bc410);
        fx.unk54 = 1.0f;
        fx.unk58 = 3000.0f;
        fx.unk50 = 0;
        fx.unk5c = 0;
        fx.unk60 = 0;
        if (FUN_001caee4(DAT_0034a114, index, &pos, &scratch) != 0) {
            fx.pos.z = pos.z;
            fx.unk58 = 3500.0f;
            fx.pos.x = pos.x;
            fx.pos.y = pos.y;
            fx.pos.w = pos.w;
            fx.unk50 = a;
            fx.unk54 = f;
            FUN_00067790(DAT_0034a114->effects, &fx);
        }
        fx.vptr = DAT_0030753c;
    } else {
        rec.type = REQ_TYPE_4F;
        rec.unk8 = 0;
        rec.count = delay;
        rec.a = a;
        rec.b = index;
        rec.f = f;
        FUN_00289544(self->queueCount, (int)self + 0x68, &rec);
    }
}
