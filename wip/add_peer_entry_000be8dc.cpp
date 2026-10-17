/* HSTMATCH module=hstp_trans_main.prx start=0x000be8dc end=0x000bea90 symbol=FUN_000be8dc lang=c++ */
/* Hand-written reconstruction from the disassembly (siblings: src/sharing_main/table_set_entry_000bf090.cpp, erase_entry_by_key_000bea90.cpp); NEAR MISS, not exact: 11 words differ, register naming only; names and types await human review. */
struct Tag {};
struct Name6 {
  char c[6];
  Name6() {}
};
struct Entry {
  Name6 name;
  char pad[2];
  char *buf;
  int len;
};
struct Iter {
  Entry **p;
  Iter(Entry **q) : p(q) {}
  Iter &operator++() { ++p; return *this; }
  Entry *&operator*() const { return *p; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }
struct Vec {
  Entry **data;
  unsigned size;
  unsigned cap;
  Vec() : data(0), size(0), cap(0) {}
  Iter begin() const { return Iter(data); }
  Iter end() { return Iter(data + size); }
};
struct Self {
  char pad[0x54];
  Vec *vec;
};
extern "C" {
void *FUN_00000bcc(unsigned n);
void *FUN_00000a90(unsigned n);
int FUN_0001100c(const void *, const void *, int);
void *FUN_00011090(void *, const void *, unsigned);
void *FUN_000114c0(void *, int, unsigned);
void FUN_000bd6f0(const char *);
void FUN_000c1fb0(Vec *, Entry **, Tag);
extern char DAT_0037bb9c[];
}

extern "C" void FUN_000be8dc(Self *self, const char *name, int len, const void *data)
{
  if (self->vec != 0) {
    Iter it = self->vec->begin();
    if (it != self->vec->end()) {
      do {
        if (FUN_0001100c(*it, name, 6) == 0) return;
        ++it;
      } while (it != self->vec->end());
    }
  } else {
    self->vec = new Vec;
  }
  Entry *e = (Entry *)FUN_00000bcc(16);
  FUN_000114c0(e, 0, 16);
  e->name = *(const Name6 *)name;
  if (len > 0) {
    e->buf = (char *)FUN_00000a90(len);
    FUN_00011090(e->buf, data, len);
    e->len = len;
  }
  FUN_000bd6f0(DAT_0037bb9c);
  Vec *v = self->vec;
  if (v->size < v->cap) {
    ++v->size;
    unsigned off = (v->size - 1) * 4;
    *(Entry **)((char *)v->data + off) = e;
  } else {
    FUN_000c1fb0(v, &e, Tag());
  }
}
// NEAR MISS (11 of 109 words differ, all register names): the opcodes, branches and schedule are identical to retail.
// Differing words: in the 3-iteration name-copy loop (e->name = *(const Name6 *)name; lb/lb/sb/sb countdown) retail uses
// dst a2 / count a1 / bytes a0,v1 while ours uses a1 / a0 / v1,v0 (7 words incl. the `lw aN,40(sp)` reload), and the last
// reload before `sw s2,12(..)` (e->len = len) is v1 in retail, v0 in ours (2 words).
// Ruled out (all gave the same 11 words): new Entry / (Entry *)new(16) / Entry *p=...;Entry *e=p; (p2: e after memset -> 13 words),
// `new Entry()` (inlines the zeroing, 57 words), Name6 *dst = &e->name; SetName() member; const Name6 * parameter;
// Vec *v / Iter declared at the top (j1/j2: same; e declared at the top: 16 words); memset/memmove declared void or void *,
// memset declared with 1-2 arguments (loop registers unchanged), sizeof(Entry); unsigned len; ablating the search, the len>0 block
// or the append leaves the loop registers unchanged, so the cause is local to the copy block.
