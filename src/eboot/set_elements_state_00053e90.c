/* HSTMATCH module=EBOOT.BIN start=0x00053e90 end=0x00053f30 symbol=FUN_00053e90 lang=c99 */
/* Clone of src/sharing_main/set_elements_state_000549dc.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
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

extern void *FUN_0002e650(void *, int);
extern int FUN_0002e840(void *);

void FUN_00053e90(Obj *self, int flag, float value)
{
  void *container;
  int i;
  int count;

  container = self->f8 + 16;
  count = FUN_0002e840(container);
  i = 0;
  if (count > 0) {
    do {
      Elem *elem = *(Elem **)FUN_0002e650(container, i);
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
