/* HSTMATCH module=EBOOT.BIN start=0x001f00c8 end=0x001f02fc symbol=FUN_001f00c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct (slot array of 0x14-byte records, index table), if/else-if chain on the state field rewritten as a switch with cases written 0, 2, 3 (MWCC tests them in reverse), the duplicated activate sequence kept in both arms, and the `!= TAB_NONE` arm written first; readability pass; exact match verified; names and types await human review. */
extern void FUN_001e09dc(void *, int);
extern void FUN_001e2990(void *);
extern void FUN_001e28e0(void *);
extern int FUN_001e5a9c(void *);
extern int FUN_001e5a34(void *);
extern void FUN_001e59f4(void *, int);
extern void FUN_001bbd30(void *, int, int);
extern void FUN_001f46b4(void *, int);
extern void FUN_001fb3f4(void *);
extern void FUN_001f3770(void *);
extern void FUN_001f4bfc(void *);
extern void FUN_001f47a4(void *);

#define TAB_NONE (-1)        /* index-table entry meaning "no slot" */
#define WAIT_FRAMES 0x1e     /* frames counted in STATE_WAIT before activating */
#define HOLD_FRAMES 10       /* frames counted in STATE_HOLD before resuming */

enum { STATE_WAIT = 0, STATE_ACTIVE = 2, STATE_HOLD = 3 };

typedef struct Slot { char b[0x14]; } Slot;

typedef struct Obj {
  char pad0[0x44];
  int unk44;
  char pad1[0x510 - 0x48];
  void *child;     /* 0x510 helper object driven by this update */
  char pad2[0x628 - 0x514];
  int state;      /* 0x628 */
  int count;      /* 0x62c frame counter for the current state */
  char pad3[0xc70 - 0x630];
  Slot slots[40]; /* 0xc70 */
  int tab[0x20];  /* index table into slots */
  char pad4[0x1034 - 0xf90 - 0x20 * 4];
  int cur;        /* 0x1034 index into tab */
} Obj;

void FUN_001f00c8(Obj *self)
{
  if (self->unk44 == 0) {
    self->state = STATE_WAIT;
    self->count = 0;
    FUN_001e09dc(self->child, 2);
    FUN_001e2990(self->child);
  }
  switch (self->state) {
  case STATE_WAIT:
    self->count++;
    if (self->count > WAIT_FRAMES && self->tab[self->cur] != TAB_NONE) {
      self->state = STATE_ACTIVE;
      self->count = 0;
      FUN_001bbd30(&self->slots[self->tab[self->cur]], 4, 0);
      FUN_001f46b4(self, 0);
      FUN_001e59f4(self->child, self->tab[self->cur]);
      FUN_001e2990(self->child);
      FUN_001fb3f4(self);
    }
    break;
  case STATE_ACTIVE:
    if (FUN_001e5a9c(self->child) != 0) {
      FUN_001e28e0(self->child);
    } else {
      FUN_001e2990(self->child);
    }
    if (FUN_001e5a34(self->child) != 0) {
      if (self->tab[self->cur] != TAB_NONE) {
        self->state = STATE_ACTIVE;
        self->count = 0;
        FUN_001bbd30(&self->slots[self->tab[self->cur]], 4, 0);
        FUN_001f46b4(self, 0);
        FUN_001e59f4(self->child, self->tab[self->cur]);
        FUN_001e2990(self->child);
        FUN_001fb3f4(self);
      } else {
        FUN_001e2990(self->child);
        FUN_001f3770(self);
      }
    }
    break;
  case STATE_HOLD:
    self->count++;
    if (self->count > HOLD_FRAMES) {
      FUN_001fb3f4(self);
      self->state = STATE_ACTIVE;
      FUN_001e28e0(self->child);
    }
    break;
  }
  FUN_001f4bfc(self);
  FUN_001f47a4(self);
}
