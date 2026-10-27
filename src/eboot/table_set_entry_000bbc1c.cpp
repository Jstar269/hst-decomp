/* HSTMATCH module=EBOOT.BIN start=0x000bbc1c end=0x000bbe00 symbol=FUN_000bbc1c lang=c++ data=0x002d5310 */
/* Clone of src/sharing_main/table_set_entry_000bf090.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d5310-0x002d531d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Table update by key: when the length equals the stored one (+0x174), find the entry whose 6-byte name
   (+4, memcmp 0x1100c) matches in the pointer vector at +0x50 and overwrite its buffer (+0xc) with the data,
   resetting +0x10 to 600; otherwise create the vector on demand, build a new 20-byte entry (vptr, copied name,
   600, buffer from 0x104b0 filled with the data), report through 0xbd6f0 and append it. Matching idioms: the
   allocation is tested in place and assigned to the address-taken local afterwards (`Entry *e = p;`, one merged
   store), the iterator has a free !(a == b) operator!=, the fast append bumps size first and then stores at
   (size - 1) * 4, and the name copy is the implicit memberwise assignment of a type with a user constructor.
   Names provisional. */
struct Tag {};
struct Name6 {
  char c[6];
  Name6() {}
};
struct Entry {
  void *vptr;
  Name6 name;
  char pad[2];
  char *buf;
  int f10;
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
  char pad[0x50];
  Vec *vec;
  char pad54[0x120];
  int f174;
};
extern "C" {
void *FUN_00000bcc(unsigned n);
int FUN_0001100c(const void *, const void *, int);
void *FUN_00011090(void *, const void *, unsigned);
char *FUN_000104b0(int);
void FUN_000ba3ac(const char *);
void FUN_000be864(Vec *, Entry **, Tag);
extern char DAT_003073d8[];
}

extern "C" void FUN_000bbc1c(Self *self, const char *name, int len, const void *data)
{
  if (len == self->f174) {
    if (self->vec != 0) {
      Iter it = self->vec->begin();
      if (it != self->vec->end()) {
        do {
          if (FUN_0001100c(&(*it)->name, name, 6) == 0) {
            FUN_00011090((*it)->buf, data, len);
            (*it)->f10 = 600;
            return;
          }
          ++it;
        } while (it != self->vec->end());
      }
    } else {
      self->vec = new Vec;
    }
    Entry *p = (Entry *)FUN_00000bcc(20);
    if (p) {
      p->vptr = DAT_003073d8;
      p->buf = 0;
    }
    Entry *e = p;
    e->name = *(const Name6 *)name;
    e->f10 = 600;
    e->buf = FUN_000104b0(len);
    FUN_00011090(e->buf, data, len);
    FUN_000ba3ac("SetGameList\n");
    Vec *v = self->vec;
    if (v->size < v->cap) {
      ++v->size;
      unsigned off = (v->size - 1) * 4;
      *(Entry **)((char *)v->data + off) = e;
    } else {
      FUN_000be864(v, &e, Tag());
    }
  }
}
