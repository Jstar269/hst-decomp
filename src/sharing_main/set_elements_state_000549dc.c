/* HSTMATCH module=hstp_trans_main.prx start=0x000549dc end=0x00054a7c symbol=FUN_000549dc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0) corrected by hand: parameter ordering (self, flag, float value), typed element struct and loop scheduling; exact match verified; names and types await human review. */
typedef struct Elem {
  float f0;
  char pad[6];
  char b10;
  char b11;
} Elem;

typedef struct Obj {
  char pad[8];
  char *f8;
} Obj;

extern void *FUN_0002e678(void *, int);
extern int FUN_0002e868(void *);

void FUN_000549dc(Obj *self, int flag, float value)
{
  void *container;
  int i;
  int count;

  container = self->f8 + 16;
  count = FUN_0002e868(container);
  i = 0;
  if (count > 0) {
    do {
      Elem *elem = *(Elem **)FUN_0002e678(container, i);
      if (flag != 0) {
        elem->b10 = 1;
        elem->b11 = 2;
      } else {
        elem->b10 = 0;
        elem->b11 = 0;
      }
      i++;
      elem->f0 = value;
    } while (i < count);
  }
}
