/* HSTMATCH module=EBOOT.BIN start=0x000e9418 end=0x000e9504 symbol=FUN_000e9418 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#define ELEM_SUB_SIZE 0x2c0 /* an element is 0x30 bytes of header and this sub-object: 752 bytes */

extern void FUN_00000a00();
extern int FUN_0005ba00();
extern int FUN_000e9594();

typedef struct Elem { char pad0[0x30]; char sub[ELEM_SUB_SIZE]; } Elem;

/* Element array whose live range starts `start` elements into the storage. */
typedef struct OffsetVec {
  Elem *data;     /* 0x00 */
  int size;       /* 0x04 live elements */
  int pad[2];
  int start;      /* 0x10 index of the first live element */
} OffsetVec;

/* Destructor: destroy the live elements back to front, release the storage, and free the object when `flag` is positive. */
OffsetVec *FUN_000e9418(OffsetVec *self, short flag)
{
  if (self != 0) {
    Elem *first = self->data + self->start;
    Elem *last = first + self->size;
    if (first < last) {
      do {
        last--;
        if (last != 0) FUN_0005ba00(last->sub, -1);
      } while (first < last);
    }
    self->size = 0;
    if (self != 0) {
      FUN_000e9594(self);
      if (self->data != 0) FUN_00000a00(self->data);
    }
    if (0 < flag) FUN_00000a00(self);
  }
  return self;
}
