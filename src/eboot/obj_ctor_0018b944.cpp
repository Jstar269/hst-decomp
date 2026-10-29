/* HSTMATCH module=EBOOT.BIN start=0x0018b944 end=0x0018b9e0 symbol=FUN_0018b944 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/render_target.h"

extern "C" void FUN_0001f06c(void *p);
extern "C" void FUN_0018c4dc(void *p);
extern "C" void FUN_0018b850();
extern "C" void FUN_0018b810();
extern "C" void FUN_0018b82c();
extern char DAT_0030915c[];
extern void *DAT_0034152c;

/* Constructor: registers itself as the global instance and installs the three callbacks. */
extern "C" RenderTarget *FUN_0018b944(RenderTarget *self, int width, int height)
{
  FUN_0001f06c(self);
  self->vtable = DAT_0030915c;
  DAT_0034152c = self;
  self->unk50 = 0;
  self->unk54 = 0;
  self->dirty = 0;
  self->unk45 = 0;
  self->camera = 0;
  self->width = width;
  self->height = height;
  FUN_0018c4dc(self);
  self->fn7c = (void *)FUN_0018b850;
  self->fn80 = (void *)FUN_0018b810;
  self->fn84 = (void *)FUN_0018b82c;
  return self;
}
