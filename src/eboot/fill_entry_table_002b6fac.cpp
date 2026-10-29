/* HSTMATCH module=EBOOT.BIN start=0x002b6fac end=0x002b71e0 symbol=FUN_002b6fac lang=c++ data=0x00303140 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x00303140-0x0030317e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Started from hstgen.py tag v0. Matching idioms: the local C_002b6eb0 (vtable __vt__10C_002b6eb0 = 0x309ffc) has an inline ctor that stores the vptr, memset()s the whole 8 bytes and sets two bytes to -1, and an inline virtual dtor that only restores the vptr; each loop has its own int index (i, j, k) with explicit walking pointers assigned in the guard shape of the pseudocode; the index is int against the unsigned size so the entry address stays i*8; the sort argument reads the size through an inline getter so it is reloaded after the loop. */
extern "C" void *FUN_000114c0(void *, int, unsigned);
extern "C" void FUN_002b71e0(...);
struct Tag {};

/* One row of the judge database: "got" flag (-1 unused), table number and id; the class name stays because the compiler derives the vtable symbol from it. */
class C_002b6eb0 {
public:
  virtual void key();
  virtual ~C_002b6eb0() {}
  signed char got, no, id;
  C_002b6eb0() { FUN_000114c0(this, 0, sizeof(*this)); got = -1; id = -1; }
};

struct EntryVec { C_002b6eb0 *data; unsigned size; unsigned cap; C_002b6eb0 &operator[](unsigned i) { return data[i]; } unsigned Size() const { return size; } };
struct IntVec { int *data; unsigned size; unsigned cap; int &operator[](unsigned i) { return data[i]; } };
struct Self { void *vptr; EntryVec entries; IntVec ints; };
struct Pair { int key; int idx; }; /* sort key and entry index */

extern "C" {
extern signed char DAT_002cc530[];
extern int DAT_0030313c;
void FUN_002b7258(EntryVec *, unsigned, C_002b6eb0 *, Tag);
void FUN_0001cfa4(Pair *, int, int);
void FUN_001a5bcc(IntVec *, int, int *, Tag);

void FUN_002b6fac(Self *self)
{
  C_002b6eb0 proto;
  Pair pairs[1024];
  int i;
  int j;
  int k;
  Pair *q;
  const signed char *t;
  int count;

  FUN_002b7258(&self->entries, 8, &proto, Tag());
  i = 0;
  if (self->entries.size != 0) {
    t = DAT_002cc530;
    do {
      C_002b6eb0 *e = &self->entries[i];
      if (i == 0) {
        e->got = 1;
      } else {
        e->got = 0;
      }
      e->no = *t;
      e->id = i;
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
      if (e->got >= 0) {
        count++;
        q->key = e->no;
        q->idx = j;
      } else {
        q->key = 0x7fff;
        q->idx = j;
      }
      j++;
      q++;
    } while ((unsigned)j < self->entries.size);
  }
  FUN_0001cfa4(pairs, 0, self->entries.Size() - 1);
  FUN_001a5bcc(&self->ints, count, &DAT_0030313c, Tag());
  k = 0;
  if (self->ints.size != 0) {
    q = pairs;
    do {
      self->ints[k] = self->entries[q->idx].id;
      k++;
      q++;
    } while ((unsigned)k < self->ints.size);
  }
  FUN_002b71e0("--- JudgeDatabase ---\n");
  for (i = 0; i < self->entries.size; i++) {
    C_002b6eb0 *e = &self->entries[i];
    FUN_002b71e0("ID=%d: Get=%d, No=%d\n", i, e->got, e->no);
  }
  for (i = 0; i < self->ints.size; i++) {
    FUN_002b71e0("No=%d: ID=%d\n", i, self->ints[i]);
  }
}
}
