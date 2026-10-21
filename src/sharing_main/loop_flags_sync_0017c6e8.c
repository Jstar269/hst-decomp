/* HSTMATCH module=hstp_trans_main.prx start=0x0017c6e8 end=0x0017c7f8 symbol=FUN_0017c6e8 lang=c99 */
/* Clone of src/eboot/loop_flags_sync_0017049c.c (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop-wide selected id (sel) is the dropped second argument of the call after the loop, FUN_0017bbbc(o, sel), which gives retail's a1/a2/a3 colouring; exact match verified; names and types await human review. */
extern int DAT_003e1a08;
extern int DAT_003e1e04;
extern void FUN_0017bbbc(void *, int);
extern void FUN_0017c8a4();
extern void FUN_0017f918();
extern int FUN_0020d694();

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

void FUN_0017c6e8(Obj *o)
{
  int (*fn)();
  int sel;
  int i;
  int r;

  o->flag3d = 0;
  o->subptr = o->sub;
  o->f554 = o->f53c;
  o->f558 = o->f540;
  if (DAT_003e1a08 != 0) {
    if (DAT_003e1e04 != 0) {
      sel = ((short *)FUN_0020d694())[0x20];
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
      FUN_0017bbbc(o, sel);
    }
  }
  fn = o->f558;
  r = fn();
  FUN_0017f918(o, r);
  r = o->f558();
  FUN_0017c8a4(o, r);
}

