/* HSTMATCH module=hstp_trans_main.prx start=0x000bc54c end=0x000bc6e0 symbol=FUN_000bc54c lang=c++ */
/* Clone of src/eboot/debug_vec_print_000b9208.cpp (hstclone.py tag sw1): addresses substituted; exact match verified; names and types await human review. */
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

extern Globals *DAT_003da704;
extern int DAT_003e95c4;
extern char DAT_003b8f08[];
extern char DAT_0037b2a4[];
extern char DAT_0037b2b8[];
extern char DAT_0037b2cc[];
extern char DAT_0037b2e0[];
extern char DAT_0037b2f4[];

extern "C" {
void FUN_000481dc(...);
float sqrtf(float);
void FUN_0016be80(int);
void FUN_0013c750(Vec4 *, int, int, int);
float FUN_00176b00(Vec4 *, Vec4 *);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_0013d370(int, int);

void FUN_000bc54c(Obj *o)
{
    if (o->fc8 > 0) {
        if (o->fc8 == 1) {
            FUN_0016be80(o->f0f8);
        } else {
            Vec4 p;
            FUN_0013c750(&p, DAT_003e95c4, o->f0f4, -1);
            Vec4 g;
            g.x = DAT_003da704->f1d0.x;
            g.y = DAT_003da704->f1d0.y;
            g.z = DAT_003da704->f1d0.z;
            g.w = DAT_003da704->f1d0.w;
            Vec4 v;
            float d; float dy; float len;
            d = 360.0f - FUN_00176b00(&p, &g);
            FUN_0002245c(&v, &p, &g);
            len = sqrtf(v.x * v.x + v.z * v.z);
            dy = p.y - g.y;
            FUN_000481dc(DAT_003b8f08, DAT_0037b2a4, (double)d);
            FUN_000481dc(DAT_003b8f08, DAT_0037b2b8, (double)len);
            FUN_000481dc(DAT_003b8f08, DAT_0037b2cc, (double)dy);
            FUN_000481dc(DAT_003b8f08, DAT_0037b2e0, (double)o->f0f0);
            FUN_000481dc(DAT_003b8f08, DAT_0037b2f4, FUN_0013d370(DAT_003e95c4, o->f0f4));
        }
    }
}
}
