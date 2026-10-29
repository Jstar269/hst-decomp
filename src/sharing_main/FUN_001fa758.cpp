/* HSTMATCH module=hstp_trans_main.prx start=0x001fa758 end=0x001fa7c8 symbol=FUN_001fa758 lang=c++ */
/* Clone of src/eboot/FUN_001ec418.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/overlay_obj.h"

struct OverlayPartA { virtual ~OverlayPartA(); };
struct OverlayPartB { virtual ~OverlayPartB(); };

/* Delete the overlay's two parts. */
extern "C" void FUN_001fa758(OverlayObj *self)
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
