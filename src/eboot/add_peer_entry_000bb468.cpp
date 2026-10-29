/* HSTMATCH module=EBOOT.BIN start=0x000bb468 end=0x000bb61c symbol=FUN_000bb468 lang=c++ helpers=FUN_000ba3ac@0x000ba3ac-0x000ba3d8 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/add_peer_entry_000bb468.cpp, completed with its same-file static helper FUN_000ba3ac defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
struct Tag {};
struct Name6 {
  char c[6];
  Name6() {}
};
struct Entry {
  Name6 mac;      /* 6-byte peer address */
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
  Vec *peers;          /* 0x54 */
};
extern "C" {
void *FUN_00000bcc(unsigned n);
void *FUN_00000a90(unsigned n);
int FUN_0001100c(const void *, const void *, int);
void *FUN_00011090(void *, const void *, unsigned);
void *FUN_000114c0(void *, int, unsigned);
static void FUN_000ba3ac(...)
{
}
void FUN_000be910(Vec *, Entry **, Tag);
extern char DAT_002d5290[];
}

/* Adds a peer with the given 6-byte address and optional payload unless an entry with that address already exists. */
extern "C" void FUN_000bb468(Self *self, const char *mac, int len, const void *data)
{
  if (self->peers != 0) {
    Iter cur = self->peers->begin();
    if (cur != self->peers->end()) {
      do {
        if (FUN_0001100c(*cur, mac, 6) == 0) return;
        ++cur;
      } while (cur != self->peers->end());
    }
  } else {
    self->peers = new Vec;
  }
  Entry *entry = (Entry *)FUN_00000bcc(16);
  FUN_000114c0(entry, 0, 16);
  entry->mac = *(const Name6 *)mac;
  if (len > 0) {
    entry->buf = (char *)FUN_00000a90(len);
    FUN_00011090(entry->buf, data, len);
    entry->len = len;
  }
  FUN_000ba3ac(DAT_002d5290);
  Vec *peers = self->peers;
  if (peers->size < peers->cap) {
    ++peers->size;
    unsigned byte_off = (peers->size - 1) * 4;
    *(Entry **)((char *)peers->data + byte_off) = entry;
  } else {
    FUN_000be910(peers, &entry, Tag());
  }
}
