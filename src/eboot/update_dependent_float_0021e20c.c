/* HSTMATCH module=EBOOT.BIN start=0x0021e20c end=0x0021e25c symbol=FUN_0021e20c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Child {
  char pad[0x78];
  float value;
} Child;

typedef struct Obj {
  char pad0[0x54];
  Child *child0;
  Child *child1;
  Child *child2;
  char pad1[0x178];
  float value;
} Obj;

extern void FUN_00103480(Obj *);

void FUN_0021e20c(float value, Obj *self)
{
  if (self->value == value)
    return;

  self->value = value;
  self->child0->value = value;
  self->child1->value = self->value;
  self->child2->value = self->value;
  FUN_00103480(self);
}
