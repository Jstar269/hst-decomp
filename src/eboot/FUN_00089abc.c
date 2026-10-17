/* HSTMATCH module=EBOOT.BIN start=0x00089abc end=0x00089c8c symbol=FUN_00089abc lang=c99 */
/* Clone of src/sharing_main/FUN_0008b17c.c (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the flag byte is read into an `int f0` and compared as `(unsigned char)f0` (gives retail's andi 0xff), and the three loop-exit conditions are ONE `||` chain sharing one `ok = 0; break;`. */
typedef struct Entry { char pad[0x138]; unsigned char flag; char kind; } Entry;
typedef struct Global1e84 { char pad[0x5c]; unsigned char b5c; } Global1e84;
typedef struct Self {
  char pad0[0x54];
  int count;
  char pad1[0x68 - 0x58];
  unsigned char b68;
  char pad2[3];
  int n6c;
  void *slot[4];
} Self;
extern unsigned char DAT_003386b8;
extern void *DAT_00338af0;
extern Global1e84 *DAT_00338b44;
extern void *DAT_0033b460;
extern void FUN_0008ac88(Self *s);
extern int FUN_00096a90(void *p);
extern Entry *FUN_000c4ba0(void *list, int idx);
extern void FUN_000c50c4(void *list);
extern int FUN_0011a820(void *p);

void FUN_00089abc(Self *self)
{
  int ok = 0;
  int changed;
  unsigned i;
  Entry *e0;
  Entry *e1;
  if (DAT_003386b8 != 0) {
    if (DAT_00338af0 != 0) {
      ok = 1;
      changed = 0;
      for (i = 0; i < 4; i++) {
        if (self->slot[i] != 0) {
          FUN_00096a90(self->slot[i]);
          if ((int)i > 0) {
            e0 = FUN_000c4ba0(DAT_00338af0, i - 1);
            e1 = FUN_000c4ba0(DAT_00338af0, i);
            int f0 = e0->flag;
            if (f0 != 0 && e1->flag != 0 && e0->kind != e1->kind) {
              changed = 1;
            }
            if (f0 == 0 || (unsigned char)f0 != e1->flag || e0->kind != e1->kind) {
              ok = 0;
              break;
            }
          }
        }
      }
      if (changed) {
        if (self->count < 300) {
          self->count = self->count + 1;
          if (self->count == 300) {
            FUN_000c50c4(DAT_00338af0);
          }
        }
      } else {
        self->count = 0;
      }
    }
  } else {
    if (DAT_00338b44->b5c != 0) {
      ok = 1;
    }
  }
  if (ok) {
    FUN_0008ac88(self);
  }
  if (DAT_003386b8 != 0 && FUN_0011a820(DAT_0033b460) == 0) {
    if (self->n6c > 0) {
      self->n6c = self->n6c - 1;
    }
    self->b68 = self->n6c < 0x97;
  }
}
