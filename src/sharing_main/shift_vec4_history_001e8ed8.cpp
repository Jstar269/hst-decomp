/* HSTMATCH module=hstp_trans_main.prx start=0x001e8ed8 end=0x001e8f98 symbol=FUN_001e8ed8 lang=c++ */
/* Clone of src/eboot/shift_vec4_history_001dadf4.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Shifts a three-entry Vec4 history at +0x90/+0xa0/+0xb0 (c = b, b = a), loads the newest entry from the vector
   at +0x10 of the object behind DAT_003e19f0 + 0x88, passes a copy of the oldest entry (c) to FUN_001e8f98 and
   finishes with FUN_001e9328(this). Matching idiom: Vec4 has a user ctor (`Vec4() {}`) and the newest entry is
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
extern Game *DAT_003e19f0;
void FUN_001e8f98(Self *, float, Vec4 *);
void FUN_001e9328(Self *);
}

extern "C" void FUN_001e8ed8(Self *self)
{
  Src *src = DAT_003e19f0->src;
  self->c = self->b;
  self->b = self->a;
  self->a = src->GetV();
  Vec4 t;
  t = self->c;
  FUN_001e8f98(self, 0.0f, &t);
  FUN_001e9328(self);
}
