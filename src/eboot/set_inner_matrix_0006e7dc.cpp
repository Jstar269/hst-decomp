/* HSTMATCH module=EBOOT.BIN start=0x0006e7dc end=0x0006e870 symbol=FUN_0006e7dc lang=c++ */
/* Clone of src/sharing_main/set_inner_matrix_0006ff9c.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (Mat4 of four Vec4 rows, Vec4 with a user constructor gives the row-batched lwc1/swc1 copy); exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
};
struct Mat4 {
  Vec4 r0, r1, r2, r3;
};
struct Inner {
  char pad[0x10];
  Mat4 mat;
};
struct Obj {
  int pad;
  Inner *inner;
};

extern "C" void FUN_0006e7dc(Obj *obj, const Mat4 *m)
{
  Inner *in = obj->inner;
  if (in != 0) {
    in->mat = *m;
  }
}
