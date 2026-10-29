/* HSTMATCH module=EBOOT.BIN start=0x0018ba64 end=0x0018baac symbol=FUN_0018ba64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/render_target.h"

extern void FUN_0018bd64(RenderTarget *);
extern RenderTarget *DAT_0034152c;

/* Stores the render parameters in self, then flags the global instance for a camera re-setup. */
void FUN_0018ba64(float x, float y, float z, RenderTarget *self, void *chara, int arg50, int arg54, int arg58, float *rect)
{
  self->chara = chara;
  self->unk50 = arg50;
  self->unk54 = arg54;
  self->unk58 = arg58;
  self->unk70[0] = x;
  self->unk70[1] = y;
  self->unk70[2] = z;
  self->unk60[0] = rect[0];
  self->unk60[1] = rect[1];
  self->unk60[2] = rect[2];
  self->unk60[3] = rect[3];
  FUN_0018bd64(DAT_0034152c);
}
