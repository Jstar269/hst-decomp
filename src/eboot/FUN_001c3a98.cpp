/* HSTMATCH module=EBOOT.BIN start=0x001c3a98 end=0x001c3ae0 symbol=FUN_001c3a98 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };

/* Owner of a polymorphic object at 0x30. */
struct Owner {
  char pad00[0x30];
  VC_0 *obj30;
};

/* Delete the owned object and clear the pointer. */
extern "C" void FUN_001c3a98(Owner *self)
{
  VC_0 *obj;
  
  obj = self->obj30;
  if (obj != (VC_0 *)0x0) {
    delete obj;
    self->obj30 = 0;
  }
}
