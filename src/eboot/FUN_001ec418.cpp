/* HSTMATCH module=EBOOT.BIN start=0x001ec418 end=0x001ec488 symbol=FUN_001ec418 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/overlay_obj.h"

struct OverlayPartA { virtual ~OverlayPartA(); };
struct OverlayPartB { virtual ~OverlayPartB(); };

/* Delete the overlay's two parts. */
extern "C" void FUN_001ec418(OverlayObj *self)
{
  OverlayPartA *a = self->part_a;
  if (a != 0) {
    delete a;
    self->part_a = 0;
  }
  OverlayPartB *b = self->part_b;
  if (b != 0) {
    delete b;
    self->part_b = 0;
  }
}
