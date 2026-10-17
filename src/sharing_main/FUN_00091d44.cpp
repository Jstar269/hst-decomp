/* HSTMATCH module=hstp_trans_main.prx start=0x00091d44 end=0x00091e14 symbol=FUN_00091d44 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Obj {
    char pad0[0x10];
    Vec4 v10;
    char pad1[0x20c];
    int mode;
    char pad2[0x60];
    char sub[1];
};

extern int DAT_003e1e84;
extern "C" void FUN_000c618c(Obj *, Vec4 *, Vec4 *);
extern "C" void FUN_00055be8(char *, Vec4 *);
extern "C" void FUN_000e0eb4(int, int, int);

extern "C" void FUN_00091d44(Obj *o, Vec4 a, Vec4 b, int param_4, int c)
{
    Vec4 t;

    FUN_000c618c(o, &a, &b);
    t.x = o->v10.x;
    t.y = o->v10.y;
    t.z = o->v10.z;
    t.w = o->v10.w;
    FUN_00055be8(o->sub, &t);
    if (o->mode == 4) {
        FUN_000e0eb4(DAT_003e1e84, c < 0, c);
    }
}
