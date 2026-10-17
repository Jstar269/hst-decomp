/* HSTMATCH module=hstp_trans_main.prx start=0x00288828 end=0x002889e4 symbol=FUN_00288828 lang=c++ */
/* Clone of src/eboot/copy_matrix_call_slot1_00277678.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: one virtual class for all thirteen slot-1 calls, the 64-byte copy as a whole-struct assignment of a Mat4 of four Vec4 rows (Vec4 with a user constructor), the null-checked +0x30 destination as `p = (Mat4 *)o->f484; if (o->f484 != 0) p = (Mat4 *)((char *)p + 0x30);`; exact match verified; names and types await human review. */
struct V4_00288828 {
  float x, y, z, w;
  V4_00288828() {}
};
struct Mat4_00288828 {
  V4_00288828 r0, r1, r2, r3;
};
struct VC_00288828 {
  virtual void s0();
  virtual void m(int);
};
struct Obj_00288828 {
  char pad0[0x474];
  VC_00288828 *f474;
  char pad1[0x484 - 0x478];
  VC_00288828 *f484;
  char pad2[4];
  VC_00288828 *f48c;
  VC_00288828 *f490;
  VC_00288828 *f494;
  VC_00288828 *f498;
  VC_00288828 *f49c;
  VC_00288828 *f4a0;
  VC_00288828 *f4a4;
  VC_00288828 *f4a8;
  VC_00288828 *f4ac;
  VC_00288828 *f4b0;
  VC_00288828 *f4b4;
  char pad3[0x8e0 - 0x4b8];
  Mat4_00288828 f8e0;
};

extern "C" void FUN_00108558(VC_00288828 *);

extern "C" void FUN_00288828(Obj_00288828 *o)
{
  o->f484->m(1);
  o->f474->m(0);
  Mat4_00288828 *dst = (Mat4_00288828 *)o->f484;
  if (o->f484 != 0) dst = (Mat4_00288828 *)((char *)dst + 0x30);
  *dst = o->f8e0;
  FUN_00108558(o->f484);
  o->f490->m(1);
  o->f494->m(1);
  o->f48c->m(1);
  o->f498->m(1);
  o->f49c->m(1);
  o->f4a0->m(1);
  o->f4a4->m(1);
  o->f4a8->m(1);
  o->f4ac->m(1);
  o->f4b0->m(1);
  o->f4b4->m(1);
}
