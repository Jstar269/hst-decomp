/* HSTMATCH module=EBOOT.BIN start=0x001c3a18 end=0x001c3a88 symbol=FUN_001c3a18 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Owner of two polymorphic objects at 0x28 and 0x2c. */
struct Owner {
  char pad00[0x28];
  VC_1 *obj28;
  VC_0 *obj2c;
};

/* Delete both owned objects (0x2c first) and clear the pointers. */
extern "C" void FUN_001c3a18(Owner *self)
{
  VC_0 *obj;
  VC_1 *obj1;
  
  obj = self->obj2c;
  if (obj != (VC_0 *)0x0) {
    delete obj;
    self->obj2c = 0;
  }
  obj1 = self->obj28;
  if (obj1 != (VC_1 *)0x0) {
    delete obj1;
    self->obj28 = 0;
  }
}
