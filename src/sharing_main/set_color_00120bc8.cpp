/* HSTMATCH module=hstp_trans_main.prx start=0x00120bc8 end=0x00120ce4 symbol=FUN_00120bc8 lang=c++ */
/* Clone of src/eboot/set_color_00115cac.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Packed-colour setter: store the 32-bit RGBA word at +0x118 and a float copy of its four bytes (unsigned
   to float) scaled by 0.008f into the vector at +0x120 through the VFPU scale routine 0x22498, written as an
   inline operator* returning by value (gives the scheduled 4-load/4-store copy; a named local result
   copies in unscheduled pairs). Names provisional. */
struct Vec4_00120bc8 { float x, y, z, w; };
extern "C" Vec4_00120bc8 *FUN_000224c0(Vec4_00120bc8 *out, const Vec4_00120bc8 *v, float s);
inline Vec4_00120bc8 operator*(const Vec4_00120bc8 &v, float s)
{
    Vec4_00120bc8 r;
    FUN_000224c0(&r, &v, s);
    return r;
}
struct Obj_00120bc8 {
    char pad0[0x118];
    unsigned color_;
    int pad11c;
    Vec4_00120bc8 colorf_;
};
extern "C" void FUN_00120bc8(Obj_00120bc8 *self, unsigned c)
{
    self->color_ = c;
    Vec4_00120bc8 v;
    v.x = (float)(c & 0xff);
    v.y = (float)((c >> 8) & 0xff);
    v.z = (float)((c >> 16) & 0xff);
    v.w = (float)((c >> 24) & 0xff);
    self->colorf_ = v * 0.008f;
}
