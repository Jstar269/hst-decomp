/* HSTMATCH module=EBOOT.BIN start=0x00226fc0 end=0x002270a0 symbol=FUN_00226fc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copies the object's matrix at +0x60, replaces its translation row with `pos` (a Vec4 passed by value, so the
   callee first copies it into its own frame at 80(sp)) and hands the result to FUN_00055044, which stores it as the
   matrix of the node at +0x414. The user default ctor makes Mat4 non-POD, so its implicit copy is memberwise (one
   lwc1/swc1 batch per Vec4 row) instead of a POD block-copy loop. Names provisional. */
struct Vec4 { float x, y, z, w; };
struct Mat4 {
  Vec4 r0, r1, r2, r3;
  Mat4() {}
};
struct Obj {
  char pad[0x60];
  Mat4 mat;
  char pad1[0x414 - 0xa0];
  void *node;
};
extern "C" void FUN_00055044(void *node, Mat4 *m);

extern "C" void FUN_00226fc0(Obj *o, Vec4 pos)
{
  Mat4 m = o->mat;
  m.r3 = pos;
  FUN_00055044(o->node, &m);
}
