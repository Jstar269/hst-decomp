/* HSTMATCH module=EBOOT.BIN start=0x001cb5ec end=0x001cb700 symbol=FUN_001cb5ec lang=c++ data=0x002eaa9c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002eaa9c-0x002eaaac) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

#include "hst/panel_data.h"

extern "C" {
extern unsigned char DAT_002ea308;
extern int FUN_0000d62c(const char *);
extern void FUN_000143b0(void *, const char *, int, int);
extern int FUN_000149a8(...);
extern int FUN_00014a40(int);
extern int FUN_002295f4(int, void *, int);
extern int FUN_00287460(void *);
}

struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
  virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
  virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

/* Builds the "EVENT<n>_<m>_" key for an object whose name ends in digits and looks it up in the panel map. */
extern "C" void FUN_001cb5ec(PanelOwner *owner, void *out, VC_0 *obj, int sub_index)
{
  char *p;
  int event_num;
  int found;
  int name;

  if (obj->m() == 1) {
    name = FUN_00287460(obj);
    event_num = -1;
    if (name != 0) {
      p = (char *)(name + FUN_00014a40(name));
      p--;
      while (*p >= '0' && *p <= '9') p--;
      if (p != 0) event_num = FUN_0000d62c(p + 1);
    }
    FUN_000143b0(out, "EVENT%02d_%02d_", event_num, sub_index);
    found = FUN_002295f4((int)owner->panel->map34, out, 0);
    if (found != 0) FUN_000149a8(out, found);
  }
  else {
    FUN_000149a8(out, &DAT_002ea308);
  }
}
