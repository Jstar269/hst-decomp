/* HSTMATCH module=EBOOT.BIN start=0x00203ba8 end=0x00203dcc symbol=FUN_00203ba8 lang=c99 */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
#include "hst/types.h"

#include "hst/look_obj.h"

typedef struct {
    float x;
    float y;
    float w;
    float h;
} Ext;

typedef struct {
    float x;
    float y;
    float w;
    float h;
    float pad[3];
    unsigned int col;
} Blk;

extern float DAT_002ef1d0;
extern float DAT_0032b190[];

extern void FUN_00051490(int, int, int, int, int, int, int);
extern void FUN_00203dcc(LookObj *, int, int);
extern void FUN_0005185c(int);
extern void FUN_00022548(Ext *, float *, Ext *);
extern void FUN_00051398(int, float);
extern void FUN_00051a10(int, unsigned int, float, float, float, float, float);

/* Draws the overlay: renders the entries into the first target, then, while the global scale is non-zero and the
   fade has progressed past the fade-in start, draws a full-screen quad whose alpha follows the progress. */
void FUN_00203ba8(LookObj *self)
{
  int i;
  int step;
  int peak;
  int progress;
  int span;
  int divisor;
  unsigned char alpha;
  float aspect;
  float value;
  Blk blk;

  if (self->active == 0) return;
  FUN_00051490(self->unk520, 0, 0, 0x1e0, 0x110, 0, 0);
  i = 1;
  if (self->unk14 > 1) {
    do {
      FUN_00203dcc(self, i, 0);
      i = i + 1;
    } while (i < self->unk14);
  }
  FUN_0005185c(self->unk520);
  if (DAT_002ef1d0 == 0.0f) return;
  step = self->unke4;
  peak = (int)(self->unk514 * (float)(step << 3));
  if (peak > 0xff) peak = 0xff;
  progress = (int)(self->unk510 * 4096.0f);
  span = step << 4;
  if (4096 - span < progress) {
    divisor = span;
    if (divisor == 0) divisor = 1;
    blk.col = self->unkf0;
    value = (float)((peak * (progress - (4096 - span))) / divisor);
    value = value * DAT_002ef1d0;
    alpha = (unsigned char)(value / 2.0f);
    ((unsigned char *)&blk.col)[3] = alpha;
    blk.x = 0.0f;
    blk.y = 0.0f;
    blk.w = 1000.0f;
    blk.h = 1.0f;
    FUN_00022548((Ext *)&blk, DAT_0032b190, (Ext *)&blk);
    aspect = blk.w / blk.h;
    FUN_00051398(self->unk524, 3000.0f);
    FUN_00051490(self->unk524, 0, 0, 0x1e0, 0x110, 0, 0);
    FUN_00051a10(self->unk524, blk.col, 0.0f, 0.0f, 480.0f, 272.0f, aspect);
    FUN_0005185c(self->unk524);
  }
}

/* Matching notes: the colour argument of FUN_00051a10 is declared unsigned int (with int, the handle and colour loads swap); the clamp must be `n > 0xff` (`n >= 0x100` allocates the slti to v1 instead of at); the 4-float extent is the first 16 bytes of the 32-u8 Blk aggregate whose last word is the colour. */
