/* HSTMATCH module=hstp_trans_main.prx start=0x001d54e8 end=0x001d5580 symbol=FUN_001d54e8 lang=c++ */
/* Clone of src/eboot/find_by_key_001c70c0.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: one-word iterator and key classes with user ctors passed BY VALUE to an inline Find (retail copies them through lwc1/swc1 frame slots); loop compares it.p but dereferences via a getter so the cursor reloads from its slot; != returns (a.p == b.p) ^ 1. */
struct Elem { char pad[0x30]; int f30; };
struct Owner { char pad[0x88]; Elem **beg; int count; };
struct It {
  Elem **p;
  It() {}
  It(Elem **q) : p(q) {}
  Elem *&operator*() const { return *p; }
  Elem **Ptr() const { return p; }
  It &operator++() { ++p; return *this; }
};
struct Key {
  int v;
  Key(int k) : v(k) {}
};

static inline bool operator!=(const It &a, const It &b) { return (a.p == b.p) ^ 1; }

static inline It Find(It first, It last, Key key)
{
  while (first.p != last.p && key.v != (*first.Ptr())->f30)
    ++first;
  return first;
}

extern "C" Elem *FUN_001d54e8(Owner *m, int kid) {
  It it = Find(It(m->beg), It(m->beg + m->count), Key(kid));
  if (it != It(m->beg + m->count))
    return *it;
  return 0;
}
