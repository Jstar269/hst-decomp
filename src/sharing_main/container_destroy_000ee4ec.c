/* HSTMATCH module=hstp_trans_main.prx start=0x000ee4ec end=0x000ee5d8 symbol=FUN_000ee4ec lang=c99 */
/* Clone of src/eboot/container_destroy_000e9418.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00000a00();
extern int FUN_0005c688();
extern int FUN_000ee668();

typedef struct Elem { char pad0[0x30]; char sub[0x2c0]; } Elem;
typedef struct Vec { Elem *data; int size; int pad[2]; int start; } Vec;

Vec *FUN_000ee4ec(Vec *self, short flag)
{
  if (self != 0) {
    Elem *first = self->data + self->start;
    Elem *last = first + self->size;
    if (first < last) {
      do {
        last--;
        if (last != 0) FUN_0005c688(last->sub, -1);
      } while (first < last);
    }
    self->size = 0;
    if (self != 0) {
      FUN_000ee668(self);
      if (self->data != 0) FUN_00000a00(self->data);
    }
    if (0 < flag) FUN_00000a00(self);
  }
  return self;
}
