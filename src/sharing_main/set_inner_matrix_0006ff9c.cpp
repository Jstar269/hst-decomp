/* HSTMATCH module=hstp_trans_main.prx start=0x0006ff9c end=0x00070030 symbol=FUN_0006ff9c lang=c++ */
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

extern "C" void FUN_0006ff9c(Obj *obj, const Mat4 *m)
{
  Inner *in = obj->inner;
  if (in != 0) {
    in->mat = *m;
  }
}
