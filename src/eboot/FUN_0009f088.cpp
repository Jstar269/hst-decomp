/* HSTMATCH module=EBOOT.BIN start=0x0009f088 end=0x0009f0ec symbol=FUN_0009f088 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
struct Vec4f { float x, y, z, w; Vec4f &operator=(const Vec4f &o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
struct Obj88 { char pad[0x10]; Vec4f v; char pad2[0x22c - 0x20]; int mode; };
struct MatchMgr88 { char pad[0x88]; Obj88 *obj; };
extern "C" MatchMgr88 *DAT_003386b0;
extern "C" Vec4f FUN_0009f0ec(void *src);
extern "C" void FUN_0009f088(void *src)
{
    Obj88 *o = DAT_003386b0->obj;
    if (o->mode == 1) o->v = FUN_0009f0ec(src);
}
