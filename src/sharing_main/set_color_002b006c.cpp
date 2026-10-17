/* HSTMATCH module=hstp_trans_main.prx start=0x002b006c end=0x002b0188 symbol=FUN_002b006c lang=c++ */
/* Clone of src/eboot/set_color_00115cac.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Packed-colour setter: store the 32-bit RGBA word at +0x118 and a float copy of its four bytes (unsigned
   to float) scaled by 0.008f into the vector at +0x120 through the VFPU scale routine 0x22498, written as an
   inline operator* returning by value (gives the scheduled 4-load/4-store copy; a named local result
   copies in unscheduled pairs). Names provisional. */
struct Vec4_002b006c { float x, y, z, w; };
extern "C" Vec4_002b006c *FUN_000224c0(Vec4_002b006c *out, const Vec4_002b006c *v, float s);
inline Vec4_002b006c operator*(const Vec4_002b006c &v, float s)
{
    Vec4_002b006c r;
    FUN_000224c0(&r, &v, s);
    return r;
}
struct Obj_002b006c {
    char pad0[0x118];
    unsigned color_;
    int pad11c;
    Vec4_002b006c colorf_;
};
extern "C" void FUN_002b006c(Obj_002b006c *self, unsigned c)
{
    self->color_ = c;
    Vec4_002b006c v;
    v.x = (float)(c & 0xff);
    v.y = (float)((c >> 8) & 0xff);
    v.z = (float)((c >> 16) & 0xff);
    v.w = (float)((c >> 24) & 0xff);
    self->colorf_ = v * 0.008f;
}
