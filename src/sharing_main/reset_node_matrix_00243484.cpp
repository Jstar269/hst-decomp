/* HSTMATCH module=hstp_trans_main.prx start=0x00243484 end=0x002435e0 symbol=FUN_00243484 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Resets the matrix of the first node of the DAT_003ea8ec manager from the 64-byte global DAT_002cc260 (zero in the
   image), puts (float)w/(float)h into its translation x/y, writes that x/y pair back through an inline setter, and
   sets the two floats at +0x74/+0x78 to 1.0f. The node's transform is a second base class at +48: the explicit
   Node* -> Xform* conversion gives retail's null-checked `addiu t0,t0,48`. Mat4 (four POD Vec4 rows, user default
   ctor) is assigned row by row. Each statement re-reads the manager global, while the inline setters keep their
   `this`; that is what gives retail's three reloads of DAT_003ea8ec and the reload of nodes[0] after each store. */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 {
  Vec4 r0, r1, r2, r3;
  Mat4() {}
};
struct NodeBase { char pad[48]; };
struct Xform { Mat4 m; };
struct Node : NodeBase, Xform { };
struct Mgr {
  int f0;
  Node **nodes;
  char pad8[0x74 - 8];
  float f74;
  float f78;
  Node *Top() { return nodes[0]; }
  void SetXY(float x, float y) { Top()->m.r3.x = x; Top()->m.r3.y = y; }
  void SetF74F78(float v) { f74 = v; f78 = v; }
};
extern "C" {
extern Mgr *DAT_003ea8ec;
extern const Mat4 DAT_002cc260;
}
extern "C" void FUN_00243484(void *self, int w, int h)
{
  if (DAT_003ea8ec != 0) {
    Xform *x = DAT_003ea8ec->Top();
    x->m = DAT_002cc260;
    DAT_003ea8ec->Top()->m.r3.x = (float)w;
    DAT_003ea8ec->Top()->m.r3.y = (float)h;
    DAT_003ea8ec->SetXY(DAT_003ea8ec->Top()->m.r3.x, DAT_003ea8ec->Top()->m.r3.y);
    DAT_003ea8ec->SetF74F78(1.0f);
  }
}
