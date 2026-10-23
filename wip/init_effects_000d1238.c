/* HSTMATCH module=EBOOT.BIN start=0x000d1238 end=0x000d13e4 symbol=FUN_000d1238 lang=c99 */
extern int DAT_002d6538[];
extern char DAT_002d6548[];
extern char DAT_002d657c[];
extern char DAT_002d65b0[];
extern char DAT_002d65d8[];
extern char DAT_002d6608[];
extern char DAT_002d6628[];

extern void *FUN_00000bcc(unsigned int);
extern void *FUN_00050ff4(void *, void *, int);
extern void FUN_0006ea5c(void **, void **, char);
extern void *FUN_00056bec(void *, char *, char *, int, int, int, int);
extern void FUN_000573a0(void *, int, char *, int, int);
extern void *FUN_000e5b9c(void *, void *, int);
extern void FUN_000e6fc4(void *, void *);
extern void FUN_0001f21c(void *, void *);

struct Obj {
  char pad0[0xc8];
  void **items;
  unsigned int count;
  unsigned int cap;
  void *f0d4;
  char pad1[0x180 - 0xd8];
  void *f180;
  char pad2[0x190 - 0x184];
  void *f190;
  void *f194;
};

void FUN_000d1238(struct Obj *self)
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
      FUN_0006ea5c((void **)&self->items, &item, 0);
    }
    i++;
  } while (i < 4);

  p = FUN_00000bcc(0x48);
  if (p != 0)
    p = FUN_00050ff4(p, DAT_002d6548, 0);
  self->f0d4 = p;

  p = FUN_00000bcc(0x1b0);
  if (p != 0)
    p = FUN_00056bec(p, DAT_002d657c, DAT_002d65b0, 0, 0, 0, 0);
  self->f190 = p;

  p = FUN_00000bcc(0x1b0);
  if (p != 0)
    p = FUN_00056bec(p, DAT_002d65d8, DAT_002d6608, 0, 0, 0, 0);
  self->f194 = p;
  FUN_000573a0(p, 0, DAT_002d6628, 0, 0);

  p = FUN_00000bcc(0x100);
  if (p != 0)
    p = FUN_000e5b9c(p, self->f0d4, 8);
  self->f180 = p;
  FUN_000e6fc4(p, (char *)self + 0x130);
  FUN_0001f21c(self, self->f180);
}
// NEAR MISS: 106/107 words. Everything matches except the vector-growth path: retail
// emits `beqzl at,else` with `move v0,zero` in the delay and then `seb a2,v0` before the
// FUN_0006ea5c call (a signed-char third argument that is provably 0 on the else path),
// where we emit `addiu a0,s2,200` in the delay and `move a2,zero` after the jal - one
// word short and the argument setup order swapped.
// Ruled out: passing 0 with the callee's param typed char/signed char/unsigned char;
// (char)/(signed char) casts of `self->count < self->cap` and of `self->count >= self->cap`
// (materialises sltu+xori); a `char`/`signed char` flag local assigned from the comparison
// and passed (5 shapes); bool in C++ (not tried in the C++ TU).
// near miss from lane fm7 (unreviewed)
