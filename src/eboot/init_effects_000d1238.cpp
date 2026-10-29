/* HSTMATCH module=EBOOT.BIN start=0x000d1238 end=0x000d13e4 symbol=FUN_000d1238 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The vector-grow helper takes its third argument as a by-value TAG STRUCT (`struct Tag { char c; }`,
   called as `Tag()`), not a char or an int: that is what gives retail's `move v0,zero` + `seb a2,v0`
   in the branch delay slot and the 16-byte-larger frame; every char/bool spelling folds to
   `move a2,zero` and loses the word. */
extern "C" int DAT_002d6538[];
extern "C" char DAT_002d6548[];
extern "C" char DAT_002d657c[];
extern "C" char DAT_002d65b0[];
extern "C" char DAT_002d65d8[];
extern "C" char DAT_002d6608[];
extern "C" char DAT_002d6628[];

extern "C" void *FUN_00000bcc(unsigned int);
extern "C" void *FUN_00050ff4(void *, void *, int);
struct Tag {
  char c;
};

extern "C" void FUN_0006ea5c(void **, void **, Tag);
extern "C" void *FUN_00056bec(void *, char *, char *, int, int, int, int);
extern "C" void FUN_000573a0(void *, int, char *, int, int);
extern "C" void *FUN_000e5b9c(void *, void *, int);
extern "C" void FUN_000e6fc4(void *, void *);
extern "C" void FUN_0001f21c(void *, void *);

struct Obj {
  char pad0[0xc8];
  void **items;           /* 0xc8, growable array of created items */
  unsigned int count;     /* 0xcc */
  unsigned int cap;       /* 0xd0 */
  void *unk0d4;
  char pad1[0x180 - 0xd8];
  void *unk180;
  char pad2[0x190 - 0x184];
  void *unk190;
  void *unk194;
};

#define ITEM_COUNT 4   /* items created from the first table */

/* Create the owned objects: four items pushed into the item array, then the remaining sub-objects. */
extern "C" void FUN_000d1238(struct Obj *self)
{
  unsigned int i;
  void *item;
  void *p;

  i = 0;
  do {
    p = FUN_00000bcc(0x48);
    if (p != 0)
      p = FUN_00050ff4(p, (void *)DAT_002d6538[i], 0);
    item = p;
    if (self->count < self->cap) {
      self->count++;
      self->items[self->count - 1] = item;
    } else {
      FUN_0006ea5c((void **)&self->items, &item, Tag());
    }
    i++;
  } while (i < ITEM_COUNT);

  p = FUN_00000bcc(0x48);
  if (p != 0)
    p = FUN_00050ff4(p, DAT_002d6548, 0);
  self->unk0d4 = p;

  p = FUN_00000bcc(0x1b0);
  if (p != 0)
    p = FUN_00056bec(p, DAT_002d657c, DAT_002d65b0, 0, 0, 0, 0);
  self->unk190 = p;

  p = FUN_00000bcc(0x1b0);
  if (p != 0)
    p = FUN_00056bec(p, DAT_002d65d8, DAT_002d6608, 0, 0, 0, 0);
  self->unk194 = p;
  FUN_000573a0(p, 0, DAT_002d6628, 0, 0);

  p = FUN_00000bcc(0x100);
  if (p != 0)
    p = FUN_000e5b9c(p, self->unk0d4, 8);
  self->unk180 = p;
  FUN_000e6fc4(p, (char *)self + 0x130);
  FUN_0001f21c(self, self->unk180);
}
// NEAR MISS: 106/107 words, everything matches except the vector-grow else arm. Retail emits
// `beqzl at,else` with `move v0,zero` in the DELAY SLOT, then `seb a2,v0` (third argument, a signed-char
// conversion of a value that is 0 on this path), `addiu a0,s2,0xc8`, `jal`, `addiu a1,sp,28`. We emit
// `addiu a0,s2,0xc8` in the delay slot and `move a2,zero` after the jal, so we are one word short and the
// argument setup order differs. The `seb` means retail's third argument is a char-typed VALUE, not the
// literal 0 - but MWCC folds every spelling tried so far back to `move a2,zero`:
//   - `char zero = 0;` declared inside the else and passed,
//   - `char flag; flag = 0;` at function scope and passed,
//   - `char ok = count < cap;` with `if (ok) ... else grow(..., ok)`,
//   - a static `Grow(vec,item,char flag)` wrapper (not inlined -> MISPLACED).
// Next idea: the value may come from a caller-visible bool that is provably false at this point (e.g. the
// `p != 0` test above), or the whole arm may be an inlined container `push_back` whose char parameter is
// converted at the inline boundary.
