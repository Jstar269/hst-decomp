/* HSTMATCH module=EBOOT.BIN start=0x001cdd14 end=0x001cdd68 symbol=FUN_001cdd14 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with a virtual Kind() query (slot 11); slots 1..10 are unused here. */
struct ResultMethods {
  virtual ~ResultMethods();
  virtual int F0();
  virtual int F1();
  virtual int F2();
  virtual int F3();
  virtual int F4();
  virtual int F5();
  virtual int F6();
  virtual int F7();
  virtual int F8();
  virtual int F9();
  virtual int Kind();
};

/* True when the object's kind is 2 or 3. */
extern "C" bool FUN_001cdd14(ResultMethods *obj)
{
  int kind;
  bool match;

  kind = obj->Kind();
  match = kind == 2;
  if (!match) {
    kind = obj->Kind();
    match = kind == 3;
  }
  return match;
}
