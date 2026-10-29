/* HSTMATCH module=EBOOT.BIN start=0x001cddb0 end=0x001cde28 symbol=FUN_001cddb0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Three identical views of the same object: each Kind() call reloads the vtable. */
struct ObjView0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int Kind(); };
struct ObjView1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int Kind(); };
struct ObjView2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int Kind(); };

/* True when the object's kind is 3, 5 or 4. */
extern "C" bool FUN_001cddb0(u32 viewer,ObjView0 *obj)
{
  bool match;
  int kind;
  
  kind = obj->Kind();
  match = kind == 3;
  if (!match) {
    kind = ((ObjView1 *)(obj))->Kind();
    match = kind == 5;
  }
  if (!match) {
    kind = ((ObjView2 *)(obj))->Kind();
    match = kind == 4;
  }
  return match;
}
