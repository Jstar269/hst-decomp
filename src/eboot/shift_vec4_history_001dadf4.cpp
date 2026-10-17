/* HSTMATCH module=EBOOT.BIN start=0x001dadf4 end=0x001daeb4 symbol=FUN_001dadf4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Shifts a three-entry Vec4 history at +0x90/+0xa0/+0xb0 (c = b, b = a), loads the newest entry from the vector
   at +0x10 of the object behind DAT_003386b0 + 0x88, passes a copy of the oldest entry (c) to FUN_001daeb4 and
   finishes with FUN_001db1ec(this). Matching idiom: Vec4 has a user ctor (`Vec4() {}`) and the newest entry is
   read through a by-value getter (retail's batched lwc1 +4,+8,+12,+0 / swc1 copy); the other copies are plain
   member assignments (interleaved lwc1/swc1). Names provisional. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
};
struct Src {
  char pad[0x10];
  Vec4 v;
  Vec4 GetV() const { return v; }
};
struct Game {
  char pad[0x88];
  Src *src;
};
struct Self {
  char pad[0x90];
  Vec4 a;
  Vec4 b;
  Vec4 c;
};
extern "C" {
extern Game *DAT_003386b0;
void FUN_001daeb4(Self *, float, Vec4 *);
void FUN_001db1ec(Self *);
}

extern "C" void FUN_001dadf4(Self *self)
{
  Src *src = DAT_003386b0->src;
  self->c = self->b;
  self->b = self->a;
  self->a = src->GetV();
  Vec4 t;
  t = self->c;
  FUN_001daeb4(self, 0.0f, &t);
  FUN_001db1ec(self);
}
