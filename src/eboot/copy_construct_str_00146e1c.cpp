/* HSTMATCH module=EBOOT.BIN start=0x00146e1c end=0x00146ee0 symbol=FUN_00146e1c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed 40-byte object, first 12 bytes as a struct with an unsigned[3] array (assigned whole = batched lwc1/swc1), sixth argument of the long call is a derived empty tag temporary (fwd_tag()), byte field unsigned char, last two floats; exact match verified; names and types await human review. */
struct in_tag {};
struct fwd_tag : in_tag {};
struct Rep { unsigned v[3]; };
struct X {
  Rep rep;
  unsigned f3, f4, f5;
  unsigned char f6;
  unsigned f7;
  float f8, f9;
};
extern "C" void FUN_00003ed4(X *, unsigned);
extern "C" void FUN_00003370(X *, unsigned, unsigned, unsigned, unsigned, fwd_tag);

extern "C" X *FUN_00146e1c(X *d, X *s)
{
  if ((s->rep.v[0] & 1) == 0) {
    d->rep = s->rep;
  } else {
    d->rep.v[0] = 0;
    d->rep.v[1] = 0;
    d->rep.v[2] = 0;
    FUN_00003ed4(d, s->rep.v[1]);
    FUN_00003370(d, 0, 0, s->rep.v[2], s->rep.v[2] + s->rep.v[1], fwd_tag());
  }
  d->f3 = s->f3;
  d->f4 = s->f4;
  d->f5 = s->f5;
  d->f6 = s->f6;
  d->f7 = s->f7;
  d->f8 = s->f8;
  d->f9 = s->f9;
  return d;
}
