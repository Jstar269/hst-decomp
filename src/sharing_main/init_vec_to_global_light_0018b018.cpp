/* HSTMATCH module=hstp_trans_main.prx start=0x0018b018 end=0x0018b0a4 symbol=FUN_0018b018 lang=c++ */
/* Clone of src/eboot/init_vec_to_global_light_0017e924.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj_0018b018 {
    char pad0[0x10];
    char sub[0x590];
    float x, y, z, w;
};
struct Src_0018b018 {
    char pad0[8];
    float f8;
};
struct Glob_0018b018 {
    char pad0[0x1d0];
    float x, y, z, w;
};
extern "C" {
extern Glob_0018b018 *DAT_003da704;
extern void FUN_0005c700(void *, Glob_0018b018 *);
extern void FUN_0005c8e0(Glob_0018b018 *);
extern void FUN_0018adb4(Obj_0018b018 *, Src_0018b018 *);
}

extern "C" void FUN_0018b018(Obj_0018b018 *o, Src_0018b018 *s)
{
    FUN_0018adb4(o, s);
    float t = s->f8;
    o->x = 0.0f;
    o->y = t;
    o->z = 5.0f;
    o->w = 0.0f;
    Glob_0018b018 *g = DAT_003da704;
    g->x = o->x;
    g->y = o->y;
    g->z = o->z;
    g->w = o->w;
    FUN_0005c8e0(DAT_003da704);
    FUN_0005c700(o->sub, DAT_003da704);
}
