/* HSTMATCH module=EBOOT.BIN start=0x001c70c0 end=0x001c7158 symbol=FUN_001c70c0 lang=c++ */
// NEAR MISS (~16/38 words): logic confirmed, frame not reproduced. Retail searches
// Owner->beg (0x88) .. beg + count (0x8c) for the element whose f30 (0x30) equals the
// key, returning *it or 0 (`it != end` is the xor/sltiu/xori tail).
// What is missing (the 22 words): retail builds a 32-byte frame holding three ONE-WORD
// STRUCT locals at sp+4/sp+8/sp+12 (key, end, cur) copied at entry as
// `sw a1,16(sp); lwc1 $f0,16(sp); swc1 $f0,4(sp)` (same for end/cur through sp+20/sp+24)
// and keeps `cur` in memory, reloading `lw v0,12(sp)` before every use. That is MWCC's
// small-struct copy (lwc1/swc1 via a temp) for by-value struct params/locals; the sibling
// 0x001c6f70 has the identical prologue (see wip/find_elem_001c6f70.c from lane ds2).
// Ruled out here (all scalarise to 16 words, no frame): plain pointer loop; one-word struct
// locals (`struct It { Elem **p; }`) with member assignment or `= { base }`; an inlined
// static inline helper taking (It cur, It end, Key) by value (also as a template, also with
// a user ctor/operator!=/operator++ iterator class); a KeyPred by-value predicate template;
// `Key key = { kid };` aggregate init (that form emits an extra 4-byte sb-zero loop).
struct Elem { char pad[0x30]; int f30; };
struct Owner { char pad[0x88]; Elem **beg; int count; };
struct It { Elem **p; };
struct Key { int v; };

static inline Elem *Search(It cur, It end, Key key)
{
  while (cur.p != end.p && key.v != (*cur.p)->f30) {
    cur.p++;
  }
  return cur.p != end.p ? *cur.p : 0;
}

extern "C" Elem *FUN_001c70c0(Owner *m, int kid)
{
  Key key;
  key.v = kid;
  It end;
  end.p = m->beg + m->count;
  It cur;
  cur.p = m->beg;
  return Search(cur, end, key);
}
// near miss from lane ds4 (unreviewed)
