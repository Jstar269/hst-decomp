/* HSTMATCH module=hstp_trans_main.prx start=0x0008b17c end=0x0008b34c symbol=FUN_0008b17c lang=c99 */
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
extern unsigned char DAT_003e19f8;
extern void *DAT_003e1e30;
extern Global1e84 *DAT_003e1e84;
extern void *DAT_003e47a0;
extern void FUN_0008c348(Self *s);
extern int FUN_00098bc8(void *p);
extern Entry *FUN_000c8538(void *list, int idx);
extern void FUN_000c8b48(void *list);
extern int FUN_001259f4(void *p);

void FUN_0008b17c(Self *self)
{
  int ok = 0;
  int changed;
  unsigned i;
  Entry *e0;
  Entry *e1;
  if (DAT_003e19f8 != 0) {
    if (DAT_003e1e30 != 0) {
      ok = 1;
      changed = 0;
      for (i = 0; i < 4; i++) {
        if (self->slot[i] != 0) {
          FUN_00098bc8(self->slot[i]);
          if ((int)i > 0) {
            e0 = FUN_000c8538(DAT_003e1e30, i - 1);
            e1 = FUN_000c8538(DAT_003e1e30, i);
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
            FUN_000c8b48(DAT_003e1e30);
          }
        }
      } else {
        self->count = 0;
      }
    }
  } else {
    if (DAT_003e1e84->b5c != 0) {
      ok = 1;
    }
  }
  if (ok) {
    FUN_0008c348(self);
  }
  if (DAT_003e19f8 != 0 && FUN_001259f4(DAT_003e47a0) == 0) {
    if (self->n6c > 0) {
      self->n6c = self->n6c - 1;
    }
    self->b68 = self->n6c < 0x97;
  }
}
