/* HSTMATCH module=EBOOT.BIN start=0x0012a5cc end=0x0012a698 symbol=FUN_0012a5cc lang=c99 rodata=0x002c14dc */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad[0x190];
  int state;
  char pad1[0x32d - 0x194];
  unsigned char f32d;
  char pad2[0x330 - 0x32e];
  int f330;
} Obj;

extern int FUN_0012b868(Obj *self);
extern void FUN_000935b0(Obj *self, float f);
extern void FUN_00093cc8(Obj *self);
extern void FUN_0012b2b0(Obj *self, int a, int b, float f);
extern void FUN_0012a254(Obj *self, int a, int b, int c);

void FUN_0012a5cc(Obj *self)
{
  if (FUN_0012b868(self) == 0)
    return;
  switch (self->state) {
  case 0:
    if (self->f330 > 0) {
      self->f330--;
      FUN_000935b0(self, 0.0f);
      FUN_00093cc8(self);
    } else if (self->f32d == 0) {
      FUN_0012b2b0(self, 1, 1, -1.0f);
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xd:
    FUN_0012a254(self, 0, -1, 0);
    FUN_00093cc8(self);
  }
}
