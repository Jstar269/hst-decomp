/* HSTMATCH module=EBOOT.BIN start=0x00090144 end=0x00090214 symbol=FUN_00090144 lang=c++ */
/* Clone of src/sharing_main/FUN_00091d44.cpp (hstclone.py tag s10170158a1r4e): addresses substituted; exact match verified; names and types await human review. */
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

extern int DAT_00338b44;
extern "C" void FUN_000c29bc(Obj *, Vec4 *, Vec4 *);
extern "C" void FUN_000550c8(char *, Vec4 *);
extern "C" void FUN_000dcd6c(int, int, int);

extern "C" void FUN_00090144(Obj *o, Vec4 a, Vec4 b, int param_4, int c)
{
    Vec4 t;

    FUN_000c29bc(o, &a, &b);
    t.x = o->v10.x;
    t.y = o->v10.y;
    t.z = o->v10.z;
    t.w = o->v10.w;
    FUN_000550c8(o->sub, &t);
    if (o->mode == 4) {
        FUN_000dcd6c(DAT_00338b44, c < 0, c);
    }
}
