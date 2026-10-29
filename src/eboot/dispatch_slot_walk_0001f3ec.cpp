/* HSTMATCH module=EBOOT.BIN start=0x0001f3ec end=0x0001f540 symbol=FUN_0001f3ec lang=c++ */
/* Hand-written reconstruction from the disassembly (rebuilt as C++ with real virtual calls from the dsn2 near miss); matching idiom: the three virtual notifies go through static inline helpers taking an unused empty Tag by value, which reserves the retail frame's 16 spare bytes at no instruction cost; exact match verified; names and types await human review. */
struct Tag {};

struct Obj;

struct Link {
  Link *prev;
  Link *next;
  Obj *obj;
};

struct Slot {
  unsigned char active;
  unsigned char pending;
  unsigned short pad;
  int off;
};

struct Obj {
  virtual void v0();
  virtual void notify0();
  virtual void notify1();
  virtual void notify2();
  int f4;
  int count;
  Link *prev;
  Link *first;
  Link *cursor;
  unsigned char pad18[8];
  unsigned char gate[4];
  Slot slot[3];
};

extern "C" void FUN_0001f3ec(Obj *self, int idx, int off);

static inline void Notify0(Obj *s, Tag t) { s->notify0(); }
static inline void Notify1(Obj *s, Tag t) { s->notify1(); }
static inline void Notify2(Obj *s, Tag t) { s->notify2(); }

extern "C" void FUN_0001f3ec(Obj *self, int idx, int off)
{
  Link **cp;
  Link *head;
  Link *cur;
  Link *c;

  if (self->gate[off] == 0)
    return;
  if (self->slot[idx].pending == 0)
    return;
  if (self->slot[idx].active != 0) {
    if (self->slot[idx].off == off) {
      switch (idx) {
      case 0:
        Notify0(self, Tag());
        break;
      case 1:
        Notify1(self, Tag());
        break;
      case 2:
        Notify2(self, Tag());
        break;
      }
    }
  }
  if (self->count == 0)
    return;
  cur = self->first;
  cp = &self->cursor;
  head = (Link *)&self->prev;
  self->cursor = cur;
  while (cur != head) {
    FUN_0001f3ec(cur->obj, idx, off);
    if (self->count == 0)
      break;
    c = *cp;
    if (c == (Link *)&self->prev)
      break;
    if (c == cur)
      *cp = c->next;
    cur = *cp;
  }
  *cp = (Link *)&self->prev;
}
