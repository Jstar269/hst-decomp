/* HSTMATCH module=hstp_trans_main.prx start=0x000a1634 end=0x000a1698 symbol=FUN_000a1634 */
/* Clone of src/eboot/FUN_0009f088.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
struct Vec4f { float x, y, z, w; Vec4f &operator=(const Vec4f &o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Obj88 { char pad[0x10]; Vec4f v; char pad2[0x22c - 0x20]; int mode; };
struct MatchMgr88 { char pad[0x88]; Obj88 *obj; };
extern "C" MatchMgr88 *DAT_003e19f0;
extern "C" Vec4f FUN_000a1698(void *src);
extern "C" void FUN_000a1634(void *src)
{
    Obj88 *o = DAT_003e19f0->obj;
    if (o->mode == 1) o->v = FUN_000a1698(src);
}
