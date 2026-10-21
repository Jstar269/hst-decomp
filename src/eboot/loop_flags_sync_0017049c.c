/* HSTMATCH module=EBOOT.BIN start=0x0017049c end=0x001705ac symbol=FUN_0017049c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop-wide selected id (sel) is the dropped second argument of the call after the loop, FUN_0016f970(o, sel), which gives retail's a1/a2/a3 colouring; exact match verified; names and types await human review. */
extern int DAT_003386c8;
extern int DAT_00338ac4;
extern void FUN_0016f970(void *, int);
extern void FUN_00170658();
extern void FUN_0017358c();
extern int FUN_001feec4();

typedef struct {
  int id;
  char pad4[7];
  unsigned char mark;
} Item;

typedef struct {
  int pad0;
  int count;
  int pad8;
} Seg;

typedef struct {
  char pad0[0x3d];
  unsigned char flag3d;
  char pad3e[0x4f0 - 0x3e];
  char sub[0xc];
  Item **items;
  char pad4fc[0x508 - 0x500];
  Seg *segs;
  unsigned nsegs;
  char pad510[0x538 - 0x510];
  void *subptr;
  int f53c;
  int (*f540)();
  char pad544[0x554 - 0x544];
  int f554;
  int (*f558)();
} Obj;

static inline Seg *SegAt(Obj *o, unsigned i)
{
  return &o->segs[i];
}

static inline Item *ItemAt(Obj *o, unsigned i)
{
  return o->items[i];
}

static inline int Total(Obj *o)
{
  int total = 0;
  int k = 0;
  if (o->nsegs != 0) {
    do {
      total += SegAt(o, k)->count;
      k++;
    } while (k < o->nsegs);
  }
  return total;
}

void FUN_0017049c(Obj *o)
{
  int (*fn)();
  int sel;
  int i;
  int r;

  o->flag3d = 0;
  o->subptr = o->sub;
  o->f554 = o->f53c;
  o->f558 = o->f540;
  if (DAT_003386c8 != 0) {
    if (DAT_00338ac4 != 0) {
      sel = ((short *)FUN_001feec4())[0x20];
      i = 0;
      while (i < Total(o)) {
        Item *it = ItemAt(o, i);
        if (it->id == sel) {
          it->mark = 1;
        } else {
          it->mark = 0;
        }
        i++;
      }
      FUN_0016f970(o, sel);
    }
  }
  fn = o->f558;
  r = fn();
  FUN_0017358c(o, r);
  r = o->f558();
  FUN_00170658(o, r);
}

