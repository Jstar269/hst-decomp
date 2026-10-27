/* HSTMATCH module=EBOOT.BIN start=0x00233384 end=0x002334e0 symbol=FUN_00233384 lang=c++ */
/* Clone of src/sharing_main/reset_node_matrix_00243484.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Resets the matrix of the first node of the DAT_003415ac manager from the 64-byte global DAT_002bc410 (zero in the
   image), puts (float)w/(float)h into its translation x/y, writes that x/y pair back through an inline setter, and
   sets the two floats at +0x74/+0x78 to 1.0f. The node's transform is a second base class at +48: the explicit
   Node* -> Xform* conversion gives retail's null-checked `addiu t0,t0,48`. Mat4 (four POD Vec4 rows, user default
   ctor) is assigned row by row. Each statement re-reads the manager global, while the inline setters keep their
   `this`; that is what gives retail's three reloads of DAT_003415ac and the reload of nodes[0] after each store. */
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
extern Mgr *DAT_003415ac;
extern const Mat4 DAT_002bc410;
}
extern "C" void FUN_00233384(void *self, int w, int h)
{
  if (DAT_003415ac != 0) {
    Xform *x = DAT_003415ac->Top();
    x->m = DAT_002bc410;
    DAT_003415ac->Top()->m.r3.x = (float)w;
    DAT_003415ac->Top()->m.r3.y = (float)h;
    DAT_003415ac->SetXY(DAT_003415ac->Top()->m.r3.x, DAT_003415ac->Top()->m.r3.y);
    DAT_003415ac->SetF74F78(1.0f);
  }
}
