/* HSTMATCH module=EBOOT.BIN start=0x0017e924 end=0x0017e9b0 symbol=FUN_0017e924 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj_0017e924 {
    char pad0[0x10];
    char sub[0x590];
    float x, y, z, w;
};
struct Src_0017e924 {
    char pad0[8];
    float f8;
};
struct Glob_0017e924 {
    char pad0[0x1d0];
    float x, y, z, w;
};
extern "C" {
extern Glob_0017e924 *DAT_003313c4;
extern void FUN_0005ba78(void *, Glob_0017e924 *);
extern void FUN_0005bc58(Glob_0017e924 *);
extern void FUN_0017e6c0(Obj_0017e924 *, Src_0017e924 *);
}

extern "C" void FUN_0017e924(Obj_0017e924 *o, Src_0017e924 *s)
{
    FUN_0017e6c0(o, s);
    float t = s->f8;
    o->x = 0.0f;
    o->y = t;
    o->z = 5.0f;
    o->w = 0.0f;
    Glob_0017e924 *g = DAT_003313c4;
    g->x = o->x;
    g->y = o->y;
    g->z = o->z;
    g->w = o->w;
    FUN_0005bc58(DAT_003313c4);
    FUN_0005ba78(o->sub, DAT_003313c4);
}
