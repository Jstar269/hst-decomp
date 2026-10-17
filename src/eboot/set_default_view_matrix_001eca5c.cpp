/* HSTMATCH module=EBOOT.BIN start=0x001eca5c end=0x001ecbb0 symbol=FUN_001eca5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* If the global object DAT_003415ac exists: load the 4x4 matrix constant DAT_002bc410 into the matrix member
   (+0x30 of the object behind its holder; the base-pointer conversion is null-checked), set the translation row
   to (240.0f, 136.0f), re-set the same x/y through a two-float setter fed with its own values, and set both
   floats at +0x74/+0x78 to 1.0f. Matching idioms: `Holder *&hr = g->h` (retail keeps &g->h in a1 and reloads it
   after the matrix copy), explicit `MatHolder *mh = hr->obj` for the null-checked +0x30 conversion, V4 has a user
   ctor (row-batched lwc1/swc1 copy as in FUN_000e7fb0), and the inline setters SetOrigin/SetScale (retail's
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
  float f74;
  float f78;
  void SetOrigin(float x, float y)
  {
    h->obj->m.r3.x = x;
    h->obj->m.r3.y = y;
  }
  void SetScale(float s) { f74 = s; f78 = s; }
};
extern "C" {
extern Game *DAT_003415ac;
extern const M4 DAT_002bc410;
}

extern "C" void FUN_001eca5c(void)
{
  Game *g = DAT_003415ac;
  if (g) {
    Holder *&hr = g->h;
    MatHolder *mh = hr->obj;
    mh->m = DAT_002bc410;
    hr->obj->m.r3.x = 240.0f;
    DAT_003415ac->h->obj->m.r3.y = 136.0f;
    DAT_003415ac->SetOrigin(DAT_003415ac->h->obj->m.r3.x, DAT_003415ac->h->obj->m.r3.y);
    DAT_003415ac->SetScale(1.0f);
  }
}
