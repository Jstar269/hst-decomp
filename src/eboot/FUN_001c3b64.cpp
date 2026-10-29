/* HSTMATCH module=EBOOT.BIN start=0x001c3b64 end=0x001c3bac symbol=FUN_001c3b64 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
struct VC_0 { virtual ~VC_0(); };

/* Owner of a polymorphic object at 0x58. */
struct Owner {
  char pad00[0x58];
  VC_0 *obj58;
};

/* Delete the owned object and clear the pointer. */
extern "C" void FUN_001c3b64(Owner *self)
{
  VC_0 *obj;
  
  obj = self->obj58;
  if (obj != (VC_0 *)0x0) {
    delete obj;
    self->obj58 = 0;
  }
}
