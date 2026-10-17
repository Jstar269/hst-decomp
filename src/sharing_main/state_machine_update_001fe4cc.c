/* HSTMATCH module=hstp_trans_main.prx start=0x001fe4cc end=0x001fe700 symbol=FUN_001fe4cc lang=c99 */
/* Clone of src/eboot/state_machine_update_001f00c8.c (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct (slot array of 0x14-byte records, index table), if/else-if chain on the state field rewritten as a switch with cases written 0, 2, 3 (MWCC tests them in reverse), the duplicated activate sequence kept in both arms, and the `!= -1` arm written first; exact match verified; names and types await human review. */
extern void FUN_001eec00(void *, int);
extern void FUN_001f0be4(void *);
extern void FUN_001f0b34(void *);
extern int FUN_001f3cb4(void *);
extern int FUN_001f3c4c(void *);
extern void FUN_001f3c0c(void *, int);
extern void FUN_001c9b18(void *, int, int);
extern void FUN_00202c44(void *, int);
extern void FUN_00209b0c(void *);
extern void FUN_00201c30(void *);
extern void FUN_002031c4(void *);
extern void FUN_00202d34(void *);

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

void FUN_001fe4cc(Obj *self)
{
  if (self->f44 == 0) {
    self->state = 0;
    self->count = 0;
    FUN_001eec00(self->f510, 2);
    FUN_001f0be4(self->f510);
  }
  switch (self->state) {
  case 0:
    self->count++;
    if (self->count > 0x1e && self->tab[self->cur] != -1) {
      self->state = 2;
      self->count = 0;
      FUN_001c9b18(&self->slots[self->tab[self->cur]], 4, 0);
      FUN_00202c44(self, 0);
      FUN_001f3c0c(self->f510, self->tab[self->cur]);
      FUN_001f0be4(self->f510);
      FUN_00209b0c(self);
    }
    break;
  case 2:
    if (FUN_001f3cb4(self->f510) != 0) {
      FUN_001f0b34(self->f510);
    } else {
      FUN_001f0be4(self->f510);
    }
    if (FUN_001f3c4c(self->f510) != 0) {
      if (self->tab[self->cur] != -1) {
        self->state = 2;
        self->count = 0;
        FUN_001c9b18(&self->slots[self->tab[self->cur]], 4, 0);
        FUN_00202c44(self, 0);
        FUN_001f3c0c(self->f510, self->tab[self->cur]);
        FUN_001f0be4(self->f510);
        FUN_00209b0c(self);
      } else {
        FUN_001f0be4(self->f510);
        FUN_00201c30(self);
      }
    }
    break;
  case 3:
    self->count++;
    if (self->count > 10) {
      FUN_00209b0c(self);
      self->state = 2;
      FUN_001f0b34(self->f510);
    }
    break;
  }
  FUN_002031c4(self);
  FUN_00202d34(self);
}
