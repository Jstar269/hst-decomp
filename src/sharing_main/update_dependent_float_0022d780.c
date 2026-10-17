/* HSTMATCH module=hstp_trans_main.prx start=0x0022d780 end=0x0022d7d0 symbol=FUN_0022d780 lang=c99 */
/* Clone of src/eboot/update_dependent_float_0021e20c.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108dac(Obj *);

void FUN_0022d780(float value, Obj *self)
{
  if (self->value == value)
    return;

  self->value = value;
  self->child0->value = value;
  self->child1->value = self->value;
  self->child2->value = self->value;
  FUN_00108dac(self);
}
