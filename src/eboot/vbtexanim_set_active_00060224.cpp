/* HSTMATCH module=EBOOT.BIN start=0x00060224 end=0x00060334 symbol=FUN_00060224 lang=c++ */
/* Hand-written reconstruction from the disassembly (written together with the exact Sharing twin src/sharing_main/vbtexanim_set_active_00061070.cpp, EBOOT addresses, ASSERT compiled out); readability pass; exact match verified; names and types await human review. */
/* VBlank texture animation switched on or off (see the Sharing twin: there the ASSERT is real, here empty): on, it
   copies the w x h source rectangle at (x, y) of the current frame buffer (0x60758, 512-pixel stride, bpp bytes per
   pixel) into its buffer, registers itself as s_pThis (DAT_003313cc) and installs the vblank handler 0x6078c in
   *hook; off, it clears both again. */
#include "hst/vbtexanim.h"

extern "C" {
extern VbTexAnim *DAT_003313cc;
char *FUN_00060758(void);
void FUN_00011090(void *, const void *, int);
void FUN_0006078c(void);
}

#define ASSERT(c, line)

extern "C" void FUN_00060224(VbTexAnim *self, int on)
{
  if (on) {
    if (self->active)
      return;
    ASSERT(DAT_003313cc == 0, 62);
    char *base = FUN_00060758();
    if (base) {
      char *src = base + self->bpp * (self->x + self->y * VBTEXANIM_STRIDE);
      char *dst = self->buf;
      for (int i = 0; i < self->h; i++) {
        FUN_00011090(dst, src, self->bpp * self->w);
        src += self->bpp * VBTEXANIM_STRIDE;
        dst += self->bpp * self->w;
      }
    }
    self->active = 1;
    DAT_003313cc = self;
    *self->hook = FUN_0006078c;
  } else if (self->active) {
    *self->hook = 0;
    DAT_003313cc = 0;
    self->active = 0;
  }
}
