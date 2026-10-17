/* HSTMATCH module=EBOOT.BIN start=0x000fbbf8 end=0x000fbc90 symbol=FUN_000fbbf8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: member-array delete loop with the index declared first and self->m[i] access (typed struct, virtual deleting destructors); exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct Obj { char pad[0x3c]; VC_1 *one; VC_0 *m[6]; };

extern "C" void FUN_000fbbf8(Obj *self)
{
  int i;
  VC_0 *p;
  VC_1 *r;

  i = 0;
  do {
    p = self->m[i];
    if (p != 0) {
      delete p;
      self->m[i] = 0;
    }
    i++;
  } while (i < 6);
  r = self->one;
  if (r != 0) {
    delete r;
    self->one = 0;
  }
}
