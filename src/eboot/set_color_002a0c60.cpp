/* HSTMATCH module=EBOOT.BIN start=0x002a0c60 end=0x002a0d7c symbol=FUN_002a0c60 lang=c++ */
/* Clone of src/eboot/set_color_00115cac.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Packed-colour setter: store the 32-bit RGBA word at +0x118 and a float copy of its four bytes (unsigned
   to float) scaled by 0.008f into the vector at +0x120 through the VFPU scale routine 0x22498, written as an
   inline operator* returning by value (gives the scheduled 4-load/4-store copy; a named local result
   copies in unscheduled pairs). Names provisional. */
struct Vec4_002a0c60 { float x, y, z, w; };
extern "C" Vec4_002a0c60 *FUN_00022498(Vec4_002a0c60 *out, const Vec4_002a0c60 *v, float s);
inline Vec4_002a0c60 operator*(const Vec4_002a0c60 &v, float s)
{
    Vec4_002a0c60 r;
    FUN_00022498(&r, &v, s);
    return r;
}
struct Obj_002a0c60 {
    char pad0[0x118];
    unsigned color_;
    int pad11c;
    Vec4_002a0c60 colorf_;
};
extern "C" void FUN_002a0c60(Obj_002a0c60 *self, unsigned c)
{
    self->color_ = c;
    Vec4_002a0c60 v;
    v.x = (float)(c & 0xff);
    v.y = (float)((c >> 8) & 0xff);
    v.z = (float)((c >> 16) & 0xff);
    v.w = (float)((c >> 24) & 0xff);
    self->colorf_ = v * 0.008f;
}
