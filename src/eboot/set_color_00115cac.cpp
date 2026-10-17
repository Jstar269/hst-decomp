/* HSTMATCH module=EBOOT.BIN start=0x00115cac end=0x00115dc8 symbol=FUN_00115cac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Packed-colour setter: store the 32-bit RGBA word at +0x118 and a float copy of its four bytes (unsigned
   to float) scaled by 0.008f into the vector at +0x120 through the VFPU scale routine 0x22498, written as an
   inline operator* returning by value (gives the scheduled 4-load/4-store copy; a named local result
   copies in unscheduled pairs). Names provisional. */
struct Vec4_00115cac { float x, y, z, w; };
extern "C" Vec4_00115cac *FUN_00022498(Vec4_00115cac *out, const Vec4_00115cac *v, float s);
inline Vec4_00115cac operator*(const Vec4_00115cac &v, float s)
{
    Vec4_00115cac r;
    FUN_00022498(&r, &v, s);
    return r;
}
struct Obj_00115cac {
    char pad0[0x118];
    unsigned color_;
    int pad11c;
    Vec4_00115cac colorf_;
};
extern "C" void FUN_00115cac(Obj_00115cac *self, unsigned c)
{
    self->color_ = c;
    Vec4_00115cac v;
    v.x = (float)(c & 0xff);
    v.y = (float)((c >> 8) & 0xff);
    v.z = (float)((c >> 16) & 0xff);
    v.w = (float)((c >> 24) & 0xff);
    self->colorf_ = v * 0.008f;
}
