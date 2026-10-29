/* HSTMATCH module=EBOOT.BIN start=0x0017049c end=0x001705ac symbol=FUN_0017049c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the loop-wide selected id (sel) is the dropped second argument of the call after the loop, FUN_0016f970(o, sel), which gives retail's a1/a2/a3 colouring; readability pass (names, structs, constants); exact match verified; names and types await human review. */
extern int DAT_003386c8;
extern int DAT_00338ac4;
extern void FUN_0016f970(void *, int);
extern void FUN_00170658();
extern void FUN_0017358c();
extern int FUN_001feec4();

typedef struct {
  int id;
  char pad4[7];
  unsigned char selected;
} Item;

typedef struct {
  int pad0;
  int count;                  /* items in the group */
  int pad8;
} Group;

typedef struct {
  char pad0[0x3d];
  unsigned char entered;
  char pad3e[0x4f0 - 0x3e];
  char unk4f0[0xc];
  Item **items;
  char pad4fc[0x508 - 0x500];
  Group *groups;
  unsigned ngroups;
  char pad510[0x538 - 0x510];
  void *unk538;
  int setFnSrc;
  int (*getSelectedId)();
  char pad544[0x554 - 0x544];
  int setFn;
  int (*getFn)();
} MenuObj;

static inline Group *GroupAt(MenuObj *o, unsigned i)
{
  return &o->groups[i];
}

static inline Item *ItemAt(MenuObj *o, unsigned i)
{
  return o->items[i];
}

/* Total number of items over all groups. */
static inline int ItemCount(MenuObj *o)
{
  int total = 0;
  int k = 0;
  if (o->ngroups != 0) {
    do {
      total += GroupAt(o, k)->count;
      k++;
    } while (k < o->ngroups);
  }
  return total;
}

/* Leaves the entered state: rebinds the callbacks and re-marks the item whose id matches the current selection. */
void FUN_0017049c(MenuObj *o)
{
  int (*fn)();
  int sel;
  int i;
  int r;

  o->entered = 0;
  o->unk538 = o->unk4f0;
  o->setFn = o->setFnSrc;
  o->getFn = o->getSelectedId;
  if (DAT_003386c8 != 0) {
    if (DAT_00338ac4 != 0) {
      sel = ((short *)FUN_001feec4())[0x20];
      i = 0;
      while (i < ItemCount(o)) {
        Item *it = ItemAt(o, i);
        if (it->id == sel) {
          it->selected = 1;
        } else {
          it->selected = 0;
        }
        i++;
      }
      FUN_0016f970(o, sel);
    }
  }
  fn = o->getFn;
  r = fn();
  FUN_0017358c(o, r);
  r = o->getFn();
  FUN_00170658(o, r);
}

