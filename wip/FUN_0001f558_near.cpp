/* HSTMATCH module=EBOOT.BIN start=0x0001f558 end=0x0001f634 symbol=FUN_0001f558 lang=c++ */
struct Self;
struct Entry { int f0; Entry *next; Self *child; };
struct Self {
  virtual void vfn0(); virtual void vfn1(); virtual void vfn2(); virtual void vfn3(); virtual void vfn4();
  int f4; int count; Entry head; Entry *cur;
};
struct Tag {};
static inline void Notify(Self *s, Tag t)
{
  s->vfn4();
}
extern "C" void FUN_0001f558(Self *self, int a1, int a2, int a3)
{
  Notify(self, Tag());
  if (self->count == 0) { return; }
  Entry **cur = &self->cur;
  Entry *head = &self->head;
  Entry *n = self->head.next;
  *cur = n;
// NEAR 55/55 words, 4 differ - lane dsn2, 2026-10-27 session 10 (13 compiles total).
// BEST VERSION. The inline-helper-with-empty-Tag recipe (0x16578c, MWCC-NOTES) removed the frame gap: wrapping
// the virtual call as `static inline void Notify(Self *s, Tag t) { s->vfn4(); }` called `Notify(self, Tag())`
// makes MWCC reserve retail's extra 16 bytes of frame with no instructions and no cost, so this file is now
// 55/55 words with ONLY the argument-save emission order left (4 words): retail saves `self` first
// (move s6,a0 / move s5,a1 / lw t9,24(t9) / move s4,a2 / jalr t9 / move s3,a3 in the delay) while ours saves
// a1,a2,a3 first and puts `move s6,a0` in the jalr delay slot. Declaration order, an alias, struct params and
// the two order nudges (v11/v12) do not move it.
// NEXT STEP: this is now a pure 4-word register-emission permutation - try a source shape that makes `self`
// live from the first instruction (e.g. a helper taking (Tag, Self*) so the self copy is emitted first), and
// treat it as a scheduler park otherwise. Everything else in the function is retail.
// FINAL PARK (session 11): the 4-word argument-save emission order resisted three further permutation shapes,
// all byte-identical to this version's 4 differ: (v14) helper parameters swapped so the tag is passed first,
// (v15) an identity inline `AsSelf(self)` forcing self through a temporary inside the Notify call, and (v13's
// own Tag() temporary). The residue is a pure register-emission permutation in MWCC 219's -O4,p scheduler
// (retail copies a0->s6 before the vptr load and leaves a3 for the jalr delay; this build does the reverse for
// both), with everything else in the function word-for-word. Treat as a scheduler wall alongside 0x0001cb88.
// near miss from lane dsn2 (unreviewed)
