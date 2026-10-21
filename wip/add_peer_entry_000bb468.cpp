/* HSTMATCH module=EBOOT.BIN start=0x000bb468 end=0x000bb61c symbol=FUN_000bb468 lang=c++ */
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
void FUN_000ba3ac(const char *);
void FUN_000be910(Vec *, Entry **, Tag);
extern char DAT_002d5290[];
}

extern "C" void FUN_000bb468(Self *self, const char *name, int len, const void *data)
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
  FUN_000ba3ac(DAT_002d5290);
  Vec *v = self->vec;
  if (v->size < v->cap) {
    ++v->size;
    unsigned off = (v->size - 1) * 4;
    *(Entry **)((char *)v->data + off) = e;
  } else {
    FUN_000be910(v, &e, Tag());
  }
}
// NEAR MISS (11 of 109 words, EBOOT twin of the Sharing 0xbe8dc wip, started from it): identical opcodes/schedule; only register naming in the
// 3-iteration name-copy loop (retail dst a2/count a1/bytes a0,v1; ours a1/a0/v1,v0, incl. the `lw aN,40(sp)` reload) and the final reload before
// `sw s2,12(..)` (retail v1, ours v0). It looks as if v0 were unavailable to the allocator in retail (the loop vregs are shifted by one register),
// but making the memset result live (z = memset(..); e->len = z), `*(Name6 *)e = ...` and a `const Name6 &` temp did not help (sn3: 3 more compiles);
// see the earlier lane's ruled-out list in wip/add_peer_entry_000be8dc.cpp.
// near miss from lane sn3 (unreviewed)
