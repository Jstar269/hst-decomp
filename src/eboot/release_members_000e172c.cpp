/* HSTMATCH module=EBOOT.BIN start=0x000e172c end=0x000e1798 symbol=FUN_000e172c lang=c++ */
/* Hand-written reconstruction from the disassembly (release of an array member and a polymorphic member); exact match verified; names and types await human review. */

struct E { E(); int x; };
struct VD { virtual ~VD(); };
struct T { char pad[0x40]; VD *m40; char pad2[0x10]; E *m54; };
extern "C" void FUN_000e1798(T *);

extern "C" void FUN_000e172c(T *self)
{
  FUN_000e1798(self);
  if (self->m54) {
    delete[] self->m54;
    self->m54 = 0;
  }
  if (self->m40) {
    delete self->m40;
    self->m40 = 0;
  }
}
