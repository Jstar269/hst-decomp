/* HSTMATCH module=hstp_trans_main.prx start=0x001fadcc end=0x001faf20 symbol=FUN_001fadcc lang=c++ */
/* Hand-written reconstruction (port of src/eboot/set_default_view_matrix_001eca5c.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* If the global object DAT_003ea8ec exists: load the 4x4 matrix constant DAT_002cc260 into the matrix member
   (+0x30 of the object behind its holder; the base-pointer conversion is null-checked), set the translation row
   to (240.0f, 136.0f), re-set the same x/y through a two-float setter fed with its own values, and set both
   floats at +0x74/+0x78 to 1.0f. Matching idioms: `Holder *&hr = g->h` (retail keeps &g->h in a1 and reloads it
   after the matrix copy), explicit `MatHolder *mh = hr->obj` for the null-checked +0x30 conversion, V4 has a user
   ctor (row-batched lwc1/swc1 copy as in FUN_000ed084), and the inline setters SetOrigin/SetScale (retail's
   self-assignment with reloaded pointer chain, one shared global load for both 1.0f stores). Names provisional. */
struct V4 {
  float x, y, z, w;
  V4() {}
};
struct M4 { V4 r0, r1, r2, r3; };
struct Base0 { char pad[0x30]; };
struct MatHolder {
  M4 m;
};
struct Obj : Base0, MatHolder {};
struct Holder { Obj *obj; };
struct Game {
  char pad0[4];
  Holder *h;
  char pad1[0x74 - 8];
  float scale_x;
  float scale_y;
  void SetOrigin(float x, float y)
  {
    h->obj->m.r3.x = x;
    h->obj->m.r3.y = y;
  }
  void SetScale(float s) { scale_x = s; scale_y = s; }
};
extern "C" {
extern Game *DAT_003ea8ec;
extern const M4 DAT_002cc260;
}

/* Reset the view: default matrix, centred origin and unit scale. */
extern "C" void FUN_001fadcc(void)
{
  Game *g = DAT_003ea8ec;
  if (g) {
    Holder *&hr = g->h;
    MatHolder *mh = hr->obj;
    mh->m = DAT_002cc260;
    hr->obj->m.r3.x = 240.0f;
    DAT_003ea8ec->h->obj->m.r3.y = 136.0f;
    DAT_003ea8ec->SetOrigin(DAT_003ea8ec->h->obj->m.r3.x, DAT_003ea8ec->h->obj->m.r3.y);
    DAT_003ea8ec->SetScale(1.0f);
  }
}
