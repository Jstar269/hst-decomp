/* HSTMATCH module=EBOOT.BIN start=0x000b9208 end=0x000b939c symbol=FUN_000b9208 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Globals { char pad[0x1d0]; Vec4 f1d0; };
struct Obj {
    char pad0[0xc8];
    int fc8;
    char pad1[0xf0 - 0xcc];
    float f0f0;
    int f0f4;
    int f0f8;
};

extern Globals *DAT_003313c4;
extern int DAT_00340284;
extern char DAT_0030fc10[];
extern char DAT_002d49dc[];
extern char DAT_002d49f0[];
extern char DAT_002d4a04[];
extern char DAT_002d4a18[];
extern char DAT_002d4a2c[];

extern "C" {
void FUN_00047d58(...);
float sqrtf(float);
void FUN_0015f8f4(int);
void FUN_00131198(Vec4 *, int, int, int);
float FUN_0016a93c(Vec4 *, Vec4 *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_00131db8(int, int);

void FUN_000b9208(Obj *o)
{
    if (o->fc8 > 0) {
        if (o->fc8 == 1) {
            FUN_0015f8f4(o->f0f8);
        } else {
            Vec4 p;
            FUN_00131198(&p, DAT_00340284, o->f0f4, -1);
            Vec4 g;
            g.x = DAT_003313c4->f1d0.x;
            g.y = DAT_003313c4->f1d0.y;
            g.z = DAT_003313c4->f1d0.z;
            g.w = DAT_003313c4->f1d0.w;
            Vec4 v;
            float d; float dy; float len;
            d = 360.0f - FUN_0016a93c(&p, &g);
            FUN_00022434(&v, &p, &g);
            len = sqrtf(v.x * v.x + v.z * v.z);
            dy = p.y - g.y;
            FUN_00047d58(DAT_0030fc10, DAT_002d49dc, (double)d);
            FUN_00047d58(DAT_0030fc10, DAT_002d49f0, (double)len);
            FUN_00047d58(DAT_0030fc10, DAT_002d4a04, (double)dy);
            FUN_00047d58(DAT_0030fc10, DAT_002d4a18, (double)o->f0f0);
            FUN_00047d58(DAT_0030fc10, DAT_002d4a2c, FUN_00131db8(DAT_00340284, o->f0f4));
        }
    }
}
}
