/* HSTMATCH module=hstp_trans_main.prx start=0x000c4230 end=0x000c43b4 symbol=FUN_000c4230 lang=c++ data=0x0037c320 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037c320-0x0037c32b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
// Builds an 80-byte entry in a local (64-byte name from strlen/memmove or a formatted counter, then a kind switch 0/1/2 for the data block) and push_back()s it into the vector at +0x770; the inline push_back uses placement new (its null check merges with the size reload in the likely-branch slot; an explicit `if (p)` in front of it does not).
inline void *operator new(unsigned, void *p) { return p; }
struct Tag {};
struct Entry {
  char name[64];
  void *data;
  void *f44;
  int size;
  int f4c;
};
struct Vec {
  Entry *data;
  unsigned size;
  unsigned cap;
};
struct Obj {
  char pad[0x770];
  Vec v;
};
extern "C" {
void *FUN_00000a90(unsigned);
void *FUN_00011090(void *, const void *, unsigned);
void FUN_000143b0(char *, const char *, ...);
int FUN_00014a40(const char *);
void FUN_000c4d4c(Vec *, Entry *, Tag);
}
extern "C" int FUN_000c4230(Obj *o, int kind, void *src, int size, int f4c, const char *name, int num)
{
  Entry e;
  e.size = size;
  e.f4c = f4c;
  if (name != 0) {
    int n = FUN_00014a40(name);
    if ((unsigned)(n + 1) >= 64) return 0;
    FUN_00011090(e.name, name, n);
  } else {
    if (num < 0) num = o->v.size;
    FUN_000143b0(e.name, "DATA%d.BIN", num);
  }
  switch (kind) {
  case 0:
    e.f44 = 0;
    e.data = FUN_00000a90(e.size);
    FUN_00011090(e.data, src, e.size);
    break;
  case 1:
    e.f44 = FUN_00000a90(e.size);
    e.data = src;
    break;
  case 2:
    e.f44 = 0;
    e.data = 0;
    break;
  }
  if (o->v.size < o->v.cap) {
    Entry *p = o->v.data + o->v.size;
    new (p) Entry(e);
    o->v.size++;
  } else {
    FUN_000c4d4c(&o->v, &e, Tag());
  }
  return 1;
}
