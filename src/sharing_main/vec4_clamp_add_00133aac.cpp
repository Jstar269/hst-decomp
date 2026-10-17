/* HSTMATCH module=hstp_trans_main.prx start=0x00133aac end=0x00133b80 symbol=FUN_00133aac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Obj { char pad[0x1a0]; Vec4 vel; Vec4 pos; };

extern float DAT_00381458;
extern float DAT_00381464;
extern "C" void FUN_00022440(Vec4 *, Vec4 *, Vec4 *);

extern "C" void FUN_00133aac(Obj *o)
{
    Vec4 g;
    g.x = 0.0f;
    g.y = DAT_00381458;
    g.z = 0.0f;
    g.w = 0.0f;
    FUN_00022440(&o->vel, &o->vel, &g);
    float w = o->vel.w;
    float k = DAT_00381464;
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
    FUN_00022440(&o->pos, &o->pos, &o->vel);
}
