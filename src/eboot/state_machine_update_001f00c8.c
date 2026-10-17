/* HSTMATCH module=EBOOT.BIN start=0x001f00c8 end=0x001f02fc symbol=FUN_001f00c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct (slot array of 0x14-byte records, index table), if/else-if chain on the state field rewritten as a switch with cases written 0, 2, 3 (MWCC tests them in reverse), the duplicated activate sequence kept in both arms, and the `!= -1` arm written first; exact match verified; names and types await human review. */
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

typedef struct Slot { char b[0x14]; } Slot;

typedef struct Obj {
  char pad0[0x44];
  int f44;
  char pad1[0x510 - 0x48];
  void *f510;
  char pad2[0x628 - 0x514];
  int state;
  int count;
  char pad3[0xc70 - 0x630];
  Slot slots[40];
  int tab[0x20];
  char pad4[0x1034 - 0xf90 - 0x20 * 4];
  int cur;
} Obj;

void FUN_001f00c8(Obj *self)
{
  if (self->f44 == 0) {
    self->state = 0;
    self->count = 0;
    FUN_001e09dc(self->f510, 2);
    FUN_001e2990(self->f510);
  }
  switch (self->state) {
  case 0:
    self->count++;
    if (self->count > 0x1e && self->tab[self->cur] != -1) {
      self->state = 2;
      self->count = 0;
      FUN_001bbd30(&self->slots[self->tab[self->cur]], 4, 0);
      FUN_001f46b4(self, 0);
      FUN_001e59f4(self->f510, self->tab[self->cur]);
      FUN_001e2990(self->f510);
      FUN_001fb3f4(self);
    }
    break;
  case 2:
    if (FUN_001e5a9c(self->f510) != 0) {
      FUN_001e28e0(self->f510);
    } else {
      FUN_001e2990(self->f510);
    }
    if (FUN_001e5a34(self->f510) != 0) {
      if (self->tab[self->cur] != -1) {
        self->state = 2;
        self->count = 0;
        FUN_001bbd30(&self->slots[self->tab[self->cur]], 4, 0);
        FUN_001f46b4(self, 0);
        FUN_001e59f4(self->f510, self->tab[self->cur]);
        FUN_001e2990(self->f510);
        FUN_001fb3f4(self);
      } else {
        FUN_001e2990(self->f510);
        FUN_001f3770(self);
      }
    }
    break;
  case 3:
    self->count++;
    if (self->count > 10) {
      FUN_001fb3f4(self);
      self->state = 2;
      FUN_001e28e0(self->f510);
    }
    break;
  }
  FUN_001f4bfc(self);
  FUN_001f47a4(self);
}
