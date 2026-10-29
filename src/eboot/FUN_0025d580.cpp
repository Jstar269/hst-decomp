/* HSTMATCH module=EBOOT.BIN start=0x0025d580 end=0x0025d5c4 symbol=FUN_0025d580 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

extern "C" {
extern void FUN_00103628(...);
extern void FUN_0025d5c4(...);
}
struct Widget { virtual void d0(); virtual void d1(); virtual void m(int); };
struct Holder {
  char pad00[0x68];
  Widget *widget;  /* 0x68 */
};

extern "C" void FUN_0025d580(Holder *self)
{
  FUN_00103628(self,1);
  self->widget->m(0);
  FUN_0025d5c4(self);
}
