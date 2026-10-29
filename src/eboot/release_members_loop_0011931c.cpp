/* HSTMATCH module=EBOOT.BIN start=0x0011931c end=0x001193bc symbol=FUN_0011931c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the member pointer (s-register order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/banner_screen.h"

extern "C" {
extern int * FUN_0011aa84(...);
extern int * FUN_0011b5c4(...);
}
struct VirtualDtorObj { virtual ~VirtualDtorObj(); };

/* Delete every banner and release the two helper objects, clearing each pointer. */
extern "C" void FUN_0011931c(BannerScreen *self)
{
  int i;
  VirtualDtorObj *banner;
  void *helper;

  i = 0;
  do {
    banner = (VirtualDtorObj *)self->banners[i];
    if (banner != (VirtualDtorObj *)0x0) {
      delete banner;
      self->banners[i] = 0;
    }
    i = i + 1;
  } while (i < BANNER_COUNT);
  if (self->unk3c != 0) {
    FUN_0011aa84(self->unk3c,1);
    self->unk3c = 0;
  }
  helper = self->unk40;
  if (helper != 0) {
    FUN_0011b5c4(helper,1);
    self->unk40 = 0;
  }
}
