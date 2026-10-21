/* HSTMATCH module=EBOOT.BIN start=0x002aae5c end=0x002ab040 symbol=FUN_002aae5c lang=c++ */
struct Child {};
extern "C" Child *FUN_00091830(void *);
extern "C" void FUN_00091c48(Child *, int);
struct Slot {
  Child *child;
  int f4, f8, fc, f10, f14;
  char f18, f19, f1a;
  int f1c;
};
static inline Slot *InitSlot(Slot *p)
{
  p->child = 0;
  p->f4 = 0;
  p->f8 = 0;
  p->fc = 0;
  p->f10 = 0;
  p->f19 = 0;
  p->f1a = 1;
  p->f14 = 0;
  p->f18 = 0;
  p->f1c = 0;
  void *m = ::operator new(0xe0);
  if (m != 0) {
    m = FUN_00091830(m);
  }
  p->child = (Child *)m;
  FUN_00091c48(p->child, -1);
  return p;
}
struct Item {
  char pad[0xf8];
  char *name;
  char pad_fc[0x3c];
  int flag;
};
struct NameEntry {
  char pad;
  char name[63];
};
struct Owner {
  char pad0[0xdb0];
  Item *src[26];
  Item *tab[5][26];
  char pad_1020[0x18];
  char *f1038;
  NameEntry names[5][26];
  char pad_30bc[0xc];
  int f30c8, f30cc, f30d0;
  char pad30d4[0x30];
  Slot *slots[4];
};
struct Obj {
  char pad[0xd8];
  int fd8, fdc;
};

extern "C" {
extern char DAT_00300a90[];
void FUN_002ab040(void);
void FUN_000143b0(char *, char *);
void FUN_0010d4a8(void);
void FUN_002a9114(Owner *, int, int);

void FUN_002aae5c(Owner *self)
{
  self->f30c8 = 0;
  self->f30cc = 0;
  self->f30d0 = 0xd;
  Obj *obj = (Obj *)self->f1038;
  obj->fd8 = 0xd;
  obj->fdc = 5;
  FUN_002ab040();
  char *p3;
  int i;
  i = 0;
  p3 = (char *)self;
  do {
    if (*(Slot **)(p3 + 0x3104) == 0) {
      Slot *s = (Slot *)::operator new(0x20);
      if (s != 0) {
        s = InitSlot(s);
      }
      *(Slot **)(p3 + 0x3104) = s;
    }
    i++;
    p3 += 4;
  } while (i < 4);
  for (int k = 0; k < 5; k++) {
    for (int j = 0; j < 26; j++) {
      if (self->tab[k][j] != 0) {
        FUN_000143b0(self->names[k][j].name, DAT_00300a90);
        Item *q = self->tab[k][j];
        q->name = self->names[k][j].name;
        q->flag = 1;
        FUN_0010d4a8();
      } else if (k == 0 && self->src[j] != 0) {
        self->tab[k][j] = self->src[j];
        FUN_000143b0(self->names[k][j].name, DAT_00300a90);
        Item *q = self->tab[k][j];
        q->name = self->names[k][j].name;
        q->flag = 1;
        FUN_0010d4a8();
      }
    }
  }
  FUN_002a9114(self, 0, 0);
}
}
// NEAR MISS (120/121 words; sn3, ~25 compiles). The second loop (5 x 26 array walk: tab/src/names indexing, `!= 0` first, k == 0 && src[j] != 0) and
// everything after it is retail-exact, as are the prologue and the first loop's counter/walker registers (declare `char *p3; int i;` then `i = 0; p3 = self;`).
// Remaining: the 4-iteration slot loop. Retail tests the allocation result in v0 (`beqzl v0,L; sw v0,slot(s1)`), does the ten field stores through v0 (move s2,v0 only
// before the second allocation) and ends with `move v0,s2; sw v0,slot(s1)`; ours copies v0 to s2 first (`move s2,v0; beqzl s2,L; sw s2,..`) and stores through s2 (1 word
// extra in total). Ruled out: new Slot with inline ctor (also containing the child alloc), static inline Init returning the pointer, splitting the zero stores from
// the child part, `if (s) {..} else {slot = s}` / `o = s` variants (all normalised to the same code), a second pointer for the stores.
// near miss from lane sn3 (unreviewed)
