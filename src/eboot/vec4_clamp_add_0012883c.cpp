/* HSTMATCH module=EBOOT.BIN start=0x0012883c end=0x00128910 symbol=FUN_0012883c lang=c++ */
/* Clone of src/sharing_main/vec4_clamp_add_00133aac.cpp (hstclone.py tag s10170158a1r4e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Obj { char pad[0x1a0]; Vec4 vel; Vec4 pos; };

extern float DAT_002da3d8;
extern float DAT_002da3e4;
extern "C" void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);

extern "C" void FUN_0012883c(Obj *o)
{
    Vec4 g;
    g.x = 0.0f;
    g.y = DAT_002da3d8;
    g.z = 0.0f;
    g.w = 0.0f;
    FUN_00022418(&o->vel, &o->vel, &g);
    float w = o->vel.w;
    float k = DAT_002da3e4;
    w = w < 0.0f ? w : 0.0f;
    float z = o->vel.z;
    z = z < 0.0f ? z : 0.0f;
    float y = o->vel.y;
    y = y < k ? y : k;
    float x = o->vel.x;
    x = x < 0.0f ? x : 0.0f;
    o->vel.x = x;
    o->vel.y = y;
    o->vel.z = z;
    o->vel.w = w;
    FUN_00022418(&o->pos, &o->pos, &o->vel);
}
