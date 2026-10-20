/* HSTMATCH module=EBOOT.BIN start=0x0014c274 end=0x0014c344 symbol=FUN_0014c274 lang=c++ */

typedef struct {
  char *key;
  int value;
} Rec;

typedef struct {
  Rec *data;
  int count;
} Cont;

struct It {
  const char *key;
  Rec *end;
  Rec *cur;
  bool Done() const { return cur == end; }
  void Next() { cur++; }
};

extern "C" int FUN_00014934(const char *a, const char *b);

static inline It Begin(const char *key, Rec *data, int count)
{
  It r;
  r.key = key;
  r.end = data + count;
  r.cur = data;
  return r;
}

extern "C" int FUN_0014c274(Cont *c, const char *key)
{
  It it = Begin(key, c->data, c->count);
  for (;;) {
    if (it.Done())
      break;
    if (FUN_00014934(it.cur->key, it.key) == 0)
      break;
    it.Next();
  }
  if (it.cur == c->data + c->count)
    return -1;
  return it.cur - c->data;
}
// 6 words short of exact (48/52 words): retail builds a 12-byte temporary at sp+48 and copies it
// field-by-field (interleaved lwc1/swc1) into the used struct at sp+32, then re-loads cur/end/key
// from memory every iteration; this source makes MWCC copy batched (3 lwc1, 3 swc1) into sp+36 and
// keep cur in s0. Tried: C by-value param to a static inline helper (MWCC coalesces it away),
// address-taken param (Step(&it)), compound literal arg (zero-fills the temp), plain pointer locals,
// non-inlined struct-returning factory (jal + copy of the return slot, 44/52 words).
// near miss from lane ds6 (unreviewed)
