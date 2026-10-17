/* HSTMATCH module=hstp_trans_main.prx start=0x002c6d4c end=0x002c6f80 symbol=FUN_002c6d4c lang=c++ */
/* Clone of src/eboot/fill_entry_table_002b6fac.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Started from hstgen.py tag v0. Matching idioms: the local C_002b6eb0 (vtable __vt__10C_002b6eb0 = 0x3b32c8) has an inline ctor that stores the vptr, memset()s the whole 8 bytes and sets two bytes to -1, and an inline virtual dtor that only restores the vptr; each loop has its own int index (i, j, k) with explicit walking pointers assigned in the guard shape of the pseudocode; the index is int against the unsigned size so the entry address stays i*8; the sort argument reads the size through an inline getter so it is reloaded after the loop. */
extern "C" void *FUN_000114c0(void *, int, unsigned);
extern "C" void FUN_002c6f80(...);
struct Tag {};

class C_002b6eb0 {
public:
  virtual void key();
  virtual ~C_002b6eb0() {}
  signed char a, b, c;
  C_002b6eb0() { FUN_000114c0(this, 0, sizeof(*this)); a = -1; c = -1; }
};

struct EntryVec { C_002b6eb0 *data; unsigned size; unsigned cap; C_002b6eb0 &operator[](unsigned i) { return data[i]; } unsigned Size() const { return size; } };
struct IntVec { int *data; unsigned size; unsigned cap; int &operator[](unsigned i) { return data[i]; } };
struct Self { void *vptr; EntryVec entries; IntVec ints; };
struct Pair { int key; int idx; };

extern "C" {
extern signed char DAT_002dc81c[];
extern int DAT_003ac3d8;
extern char DAT_003ac3dc[];
extern char DAT_003ac3f4[];
extern char DAT_003ac40c[];
void FUN_002c6ff8(EntryVec *, unsigned, C_002b6eb0 *, Tag);
void FUN_0001cbf0(Pair *, int, int);
void FUN_001b3198(IntVec *, int, int *, Tag);

void FUN_002c6d4c(Self *self)
{
  C_002b6eb0 proto;
  Pair pairs[1024];
  int i;
  int j;
  int k;
  Pair *q;
  const signed char *t;
  int count;

  FUN_002c6ff8(&self->entries, 8, &proto, Tag());
  i = 0;
  if (self->entries.size != 0) {
    t = DAT_002dc81c;
    do {
      C_002b6eb0 *e = &self->entries[i];
      if (i == 0) {
        e->a = 1;
      } else {
        e->a = 0;
      }
      e->b = *t;
      e->c = i;
      i++;
      t++;
    } while ((unsigned)i < self->entries.size);
  }
  pairs[0].key = 0;
  pairs[0].idx = 0;
  q = pairs;
  count = 0;
  j = 0;
  if (self->entries.size != 0) {
    do {
      C_002b6eb0 *e = &self->entries[j];
      if (e->a >= 0) {
        count++;
        q->key = e->b;
        q->idx = j;
      } else {
        q->key = 0x7fff;
        q->idx = j;
      }
      j++;
      q++;
    } while ((unsigned)j < self->entries.size);
  }
  FUN_0001cbf0(pairs, 0, self->entries.Size() - 1);
  FUN_001b3198(&self->ints, count, &DAT_003ac3d8, Tag());
  k = 0;
  if (self->ints.size != 0) {
    q = pairs;
    do {
      self->ints[k] = self->entries[q->idx].c;
      k++;
      q++;
    } while ((unsigned)k < self->ints.size);
  }
  FUN_002c6f80(DAT_003ac3dc);
  for (i = 0; i < self->entries.size; i++) {
    C_002b6eb0 *e = &self->entries[i];
    FUN_002c6f80(DAT_003ac3f4, i, e->a, e->b);
  }
  for (i = 0; i < self->ints.size; i++) {
    FUN_002c6f80(DAT_003ac40c, i, self->ints[i]);
  }
}
}
