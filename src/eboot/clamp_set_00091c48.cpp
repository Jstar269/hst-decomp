/* HSTMATCH module=EBOOT.BIN start=0x00091c48 end=0x00091cbc symbol=FUN_00091c48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern "C" int DAT_002d28ec; /* lowest accepted level */
extern "C" int DAT_002d28f0; /* highest accepted level */
extern "C" void FUN_00091cbc(void);

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

/* Set the level (clamped to its limits); refill the entry table when it changed and is non-negative. */
extern "C" void FUN_00091c48(ModelSetFull *self,int level)
{
  int n = Clamp(level, DAT_002d28ec, DAT_002d28f0);

  if (self->level != n) {
    self->level = n;
    if (n >= 0) {
      FUN_00091cbc();
    }
  }
}
